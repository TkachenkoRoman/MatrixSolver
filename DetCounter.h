/* 
 * File:   DetCounter.h
 * Author: roman
 *
 * Created on October 3, 2015, 4:15 PM
 */

#ifndef DETCOUNTER_H
#define	DETCOUNTER_H

#include <iostream>

class DetCounter {
public: 
    DetCounter();
    int GetDet(int **matr, int size);
    virtual ~DetCounter();
private:
    int det;   //переменная для хранения определителя
    int k;      //степень
    int n;
    void CountDet(int **matr);
    bool CheckMatrOK(int **matr);  // return true if need to calc det
    void Get_matr(int **matr, int n, int **temp_matr, int indRow, int indCol);
    template <typename T> void FreeMem(T **matr, int n);
};

#endif	/* DETCOUNTER_H */

