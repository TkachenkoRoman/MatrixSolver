/* 
 * File:   MatrSolver.cpp
 * Author: roman
 * 
 * Created on October 2, 2015, 5:43 PM
 */

#include "MatrSolver.h"

MatrSolver::MatrSolver()
{

}

MatrSolver::MatrSolver(int size)
{
    InitVars(size);
    InitRand();
    InitMatr();
    SetMtx(matr, b_matr, n);
    PrintMtx(matr, n);
    std::cout << "Матрица В: " << std::endl;
    PrintVector(b_matr, n);
    //Solve();
}

int MatrSolver::GetMatrSize(){
    return n;
}

void MatrSolver::Solve(){
    std::clock_t start = std::clock();
    det = Det(matr, n);
    std::cout << "Определитель матрицы = " << det << std::endl;
    if (det) FindObrMatr();
    else std::cout << "Т.к. определитель матрицы = 0,\nто матрица вырожденная и обратной не имеет!!!" << std::endl;
    TransponMtx(obr_matr, tobr_matr, n);
    PrintMtx(tobr_matr, n);
    SolveEquation(tobr_matr, b_matr, res, n);
    std::cout << "Результат: " << std::endl;
    PrintVector(res, n);
    FreeResources();
    std::cout<<"Solve() execution time: "<< ( std::clock() - start ) / (double) CLOCKS_PER_SEC <<'\n';
}

void MatrSolver::FreeResources()
{
    FreeMem(tobr_matr, n);
    FreeMem(matr, n);
    FreeMem(obr_matr, n);
}

template <typename T> void MatrSolver::SolveEquation(T **matr, int *b_matr, double*res, int n)
{
    for (int i = 0; i < n; i++)
    {
        double sum = 0;
        for (int j = 0; j < n; j++)
            sum += matr[i][j]*b_matr[j];
        res[i] = sum;
    }
}

template <typename T> void MatrSolver::TransponMtx(T **matr, T **tMatr, int n)
{
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            tMatr[j][i] = matr[i][j];
}

void MatrSolver::FindObrMatr()
{
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int m = n - 1;
                int **temp_matr = new int * [m];
                for(int k = 0; k < m; k++) temp_matr[k] = new int[m];
                Get_matr(matr, n, temp_matr, i, j);
                obr_matr[i][j] = pow(-1.0, i + j + 2) * Det(temp_matr, m) / det;
                FreeMem(temp_matr, m);  
            }
        }
}

void MatrSolver::InitVars(int size)
{
    n = size;
    matr = new int * [n];
    obr_matr = new double * [n];
    tobr_matr = new double * [n];
    b_matr = new int [n];
    res = new double [n];
    det = 0;
}

void MatrSolver::InitRand()
{
    srand((unsigned)time(NULL));
    setlocale(0, "");
}

void MatrSolver::InitMatr()
{
    for(int i = 0; i < n; i++){
        matr[i] = new int[n];
        obr_matr[i] = new double[n];
        tobr_matr[i] = new double[n];
    }
}

//функция заполнения матрицы
template <typename T> void MatrSolver::SetMtx(T **matr, int *b_matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        b_matr[i] = rand()%9 + 1;
        for (int j = 0; j < n; j++)
            matr[i][j] = rand()%9 + 1;
    }
}

template <typename T> void MatrSolver::PrintMtx(T **matr, int n)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            std::cout << matr[i][j] << " ";
        std::cout << std::endl; 
    }
}

template <typename T> void MatrSolver::PrintVector(T *vector, int n)
{
    for (int i = 0; i < n; i++){
        std::cout << vector[i] << " ";
    }                       
    std::cout << std::endl;
}

//==============================================================================================================
//                              вычисление определителя
//==============================================================================================================
//функция вычисления определителя матрицы
int MatrSolver::Det(int **matr, int n)  
{
    std::clock_t start = std::clock();
    int res;
    DetCounter *detCounter = new DetCounter();
    res = detCounter->GetDet(matr, n);
    std::cout<<"Det() execution time: "<< ( std::clock() - start ) / (double) CLOCKS_PER_SEC <<'\n';
    return res;
}

void MatrSolver::Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol)
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

template <typename T> void MatrSolver::FreeMem(T **matr, int n)
{
    for(int i = 0; i < n; i++)
        delete [] matr[i];
    delete [] matr;
}

MatrSolver::~MatrSolver() {
}

