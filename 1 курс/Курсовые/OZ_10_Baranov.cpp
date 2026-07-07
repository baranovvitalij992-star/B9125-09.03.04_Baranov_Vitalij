#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

int main(){
    const int size = 10;
    float matrix[size][size];
    int samanaseby = 0;
    int prstr = 0;
    bool prorto = true;
    srand(static_cast<unsigned>(time(0)));


    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            matrix[i][j] = rand() % 101; 
        }
    }

    cout << "Матрица: " << "\n";
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            cout << setprecision(2) << setw(4) << matrix[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < size; ++i){
        samanaseby = 0;
        for (int j = 0; j < size; ++j){
            samanaseby += matrix[i][j] * matrix[i][j];
        }
        if (samanaseby != 1){
            prorto = false;
            break;
        }
        for (int k = i + 1; k < size; ++k){
            for (int j = 0; j < size; ++j){
                prstr += matrix[i][j] * matrix[k][j];
            }
            if (prstr != 0){
                prorto = false;
                break;
            }
        }
        if(!prorto){
            break;
        }
    }

    if(prorto){
        cout << "Матрица ортонормированная";
    }
    else {
        cout << "Матрица не ортонормированная";
    }
}