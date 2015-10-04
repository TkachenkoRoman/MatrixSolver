#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include "MatrSolver.h"

using namespace std;
 
int main()
{
    clock_t start = clock();
    int n, det;
    cout << "Введите размер матрицы: ";
    cin >> n;
    //for(int i = 0; i<10; i++)
    //{
        MatrSolver *matrSolver = new MatrSolver(n); 
        matrSolver->Solve();
        delete(matrSolver);
    //}
    cout<<"Main execution time: "<< ( clock() - start ) / (double) CLOCKS_PER_SEC <<'\n';
    return 0;
}
  