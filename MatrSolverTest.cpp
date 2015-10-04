#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MATR_SOLVER
#include <boost/test/included/unit_test.hpp>
#include "MatrSolver.h"
 
BOOST_AUTO_TEST_CASE(constructor_test_case)
{
    MatrSolver matrSolver(5);
    BOOST_CHECK(matrSolver.GetMatrSize() == 5);
}

BOOST_AUTO_TEST_CASE(det_test_case)
{
    int n = 3;
    MatrSolver *matrSolver = new MatrSolver();
    int **matr;
    matr = new int * [n];
    for(int i = 0; i < n; i++)
    {
        matr[i] = new int[n];
    }
    int test[9] = { 1, 5, 8, 3, 5, 7, 9, 2, 4 };
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = test[k];
            k++;
        }
    }
    BOOST_CHECK(matrSolver->Det(matr, n) == -51);
}

BOOST_AUTO_TEST_CASE(get_matr_test_case)
{
    int n = 3;
    MatrSolver *matrSolver = new MatrSolver();
    int **matr;
    int **res;
    matr = new int * [n];
    res = new int * [n];
    for(int i = 0; i < n; i++)
    {
        matr[i] = new int[n];
        res[i] = new int[n];
    }
    int test[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int test_exp_res[4] = { 1, 3, 7, 9 };
    int indRow = 1;
    int indCol = 1;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = test[k];
            k++;
        }
    }
    matrSolver->Get_matr(matr, n, res, indRow, indCol);
    
    k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            BOOST_CHECK(res[i][j] == test_exp_res[k]);
            k++;
        }
    } 
}

/*BOOST_AUTO_TEST_CASE(transponMtx_test_case)
{
    int n = 3;
    int **matr;    
    int **tobr_matr;
    int test[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    tobr_matr = new int * [n];
    matr = new int * [n];
    for(int i = 0; i < n; i++)
    {
        tobr_matr[i] = new int[n];
        matr[i] = new int[n];
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matr[i][j] = test[k];
            k++;
        }
    }
    
    MatrSolver matrSolver(n);
    matrSolver.TransponMtx(matr, tobr_matr, n);
    
    BOOST_CHECK(tobr_matr[0][0] == 1);
    BOOST_CHECK(tobr_matr[1][0] == 2);
    BOOST_CHECK(tobr_matr[2][0] == 3);
    BOOST_CHECK(tobr_matr[0][1] == 4);
    BOOST_CHECK(tobr_matr[1][1] == 5);
    BOOST_CHECK(tobr_matr[2][1] == 6);
    BOOST_CHECK(tobr_matr[0][2] == 7);
    BOOST_CHECK(tobr_matr[1][2] == 8);
    BOOST_CHECK(tobr_matr[2][2] == 9);
} */