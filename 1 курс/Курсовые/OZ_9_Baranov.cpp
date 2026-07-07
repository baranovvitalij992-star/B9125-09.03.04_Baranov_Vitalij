#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main (){
    const int n = 3;
    const int m = 4;
    const int k = 2;

    int A[n][m];
    int B[m][k];
    int C[n][k];

    srand(static_cast<unsigned>(time(0)));

    cout << "Матрица A: " << "\n";
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            A[i][j] = rand() % 101;
            cout << setprecision(2) << setw(4) << A[i][j];
        }
        cout << "\n";
    }

    cout << "Матрица B: " << "\n";
    for (int i = 0; i < m; ++i){
        for(int j = 0; j < k; ++j){
            B[i][j] = rand() % 101;
            cout << setprecision(2) << setw(4) << B[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < k; ++j){
            C[i][j] = 0;
            for (int p = 0; p < m; ++p){
                C[i][j] += A[i][p] * B[p][j];
            }
        }
    }

    cout << "Матрица C: " << "\n";
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            cout << setprecision(2) << setw(6) << C[i][j];
        }
        cout << "\n";
    }
    return 0;
}