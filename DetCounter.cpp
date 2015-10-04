/* 
 * File:   DetCounter.cpp
 * Author: roman
 * 
 * Created on October 3, 2015, 4:15 PM
 */

#include "DetCounter.h"

DetCounter::DetCounter() {
    det = 0;
    k = 1;
}

int DetCounter::GetDet(int **matr, int size)
{
    det = 0;
    k = 1;
    n = size;
    CountDet(matr);
    return det;
}

bool DetCounter::CheckMatrOK(int **matr)
{
    if(n < 1){
        std::cout<<"Не верный размер матрицы!!!" << std::endl;
        return false;
    }
    else if (n == 1)
        det = matr[0][0];
    else if (n == 2)
        det = matr[0][0] * matr[1][1] - matr[1][0] * matr[0][1];
    if (n <= 2) return false;
    return true;
} 

void DetCounter::CountDet(int **matr)
{
    DetCounter * tempCounter = new DetCounter();
    if (det == 0 && CheckMatrOK(matr))
        for(int i = 0; i < n; i++){
            int m = n - 1; 
            int **temp_matr = new int * [m];
            for(int j = 0; j < m; j++) temp_matr[j] = new int [m];
            Get_matr(matr, n, temp_matr, 0, i);
            det = det + k * matr[0][i] * tempCounter->GetDet(temp_matr, m);
            k = -k;
            FreeMem(temp_matr, m);
        }
    delete(tempCounter);
}

void DetCounter::Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol)
{
    int ki = 0; 
    for (int i = 0; i < n; i++){
        if(i != indRow){
            for (int j = 0, kj = 0; j < n; j++){
                if (j != indCol){
                    temp_matr[ki][kj] = matr[i][j];
                    kj++;
                }
            }
            ki++;       
        }
    }
}

template <typename T> void DetCounter::FreeMem(T **matr, int n)
{
    for(int i = 0; i < n; i++)
        delete [] matr[i];
    delete [] matr;
}

DetCounter::~DetCounter() {
}

