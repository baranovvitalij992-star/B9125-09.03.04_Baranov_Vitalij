#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;
const int k = 3;
typedef double matrix[k][k];
typedef double vector[k];

void fil_matrix(matrix m, int len){
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            m[i][j] = rand() % 10001 / 100.0;
        }
    }
}

void fil_vector(vector v, int len){
    for (int i = 0; i < len; ++i){
        v[i] = rand() % 10001 / 100.0;
    }
}

void pr_matrix(matrix m, char name, int len){
    cout << "Матрица " << name << ": " << "\n";
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            cout << fixed << setprecision(2) << setw(8) << m[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void pr_vector(vector v, char name, int len){
    cout << "Вектор " << name << ": " << "\n";
    for (int i = 0; i < len; ++i){
        cout << fixed << setprecision(2) << setw(8) << v[i];
    }
    cout << "\n\n";
}

double proiz_vectors(vector v1, vector v2, int len){
    double pr = 0;
    for (int i = 0; i < len; ++i){
        pr += v1[i] * v2[i];
    }
    return pr;
}

void matr_vect(matrix m, vector v, vector res, int len){
    for (int i = 0; i < len; ++i){
        res[i] = 0;
        for (int j = 0; j < len; ++j){
            res[i] += m[i][j] * v[j]; 
        }
    }
}

int main(){
    srand(time(0));
    vector x, y, Ax, By, Cx;
    matrix A, B, C;
    fil_vector(x, 3); fil_vector(y, 3);
    fil_matrix(A, 3); fil_matrix(B, 3); fil_matrix(C, 3);
    pr_vector(x, 'x', 3); pr_vector(y, 'y', 3);
    pr_matrix(A, 'A', 3); pr_matrix(B, 'B', 3); pr_matrix(C, 'C', 3);
    matr_vect(A, x, Ax, 3); matr_vect(B, y, By, 3); matr_vect(C, x, Cx, 3);
    cout << proiz_vectors(Ax, By, 3) + proiz_vectors(Cx, y, 3) / proiz_vectors(x, By, 3);
}

