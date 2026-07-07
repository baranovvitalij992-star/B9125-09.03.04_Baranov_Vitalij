#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>

using namespace std;

const int k = 3;
typedef double matrix[k][k];

void fill_matrix(matrix m){
    for (int i = 0; i < k; ++i){
        for (int j = 0; j < k; ++j){
            m[i][j] = (rand() % 20001 - 10000) / 100.0;
        }
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

double find_norm(matrix m, char name, int len){
    double max_abs = 0.0;
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len; ++j){
            if (abs(m[i][j]) > max_abs){
                max_abs = abs(m[i][j]);
            }
        }
    }
    cout << "Норма матрицы " << name << ": " << max_abs << "\n";
    return max_abs;
}

void choice_matrix(double num_norm1, double num_norm2, double num_norm3, 
                   matrix m1, matrix m2, matrix m3, 
                   char name1, char name2, char name3, int len){
    
    cout << "\nВыбор матрицы с наименьшей нормой:\n";
    
    if (num_norm1 <= num_norm2 && num_norm1 <= num_norm3) {
    cout << "Матрица " << name1 << " имеет наименьшую норму: " << num_norm1 << "\n";
    pr_matrix(m1, name1, len);
    }
    else if (num_norm2 <= num_norm3) { 
        cout << "Матрица " << name2 << " имеет наименьшую норму: " << num_norm2 << "\n";
        pr_matrix(m2, name2, len);
    }
    else {
        cout << "Матрица " << name3 << " имеет наименьшую норму: " << num_norm3 << "\n";
        pr_matrix(m3, name3, len);
    }
}

int main(){
    srand(time(0));
    matrix A, B, C;
    double num_norm_A, num_norm_B, num_norm_C;
    
    fill_matrix(A); 
    fill_matrix(B); 
    fill_matrix(C);
    
    pr_matrix(A, 'A', 3); 
    pr_matrix(B, 'B', 3); 
    pr_matrix(C, 'C', 3);
    
    num_norm_A = find_norm(A, 'A', 3); 
    num_norm_B = find_norm(B, 'B', 3); 
    num_norm_C = find_norm(C, 'C', 3);
    
    choice_matrix(num_norm_A, num_norm_B, num_norm_C, A, B, C, 'A', 'B', 'C', 3);
    
    return 0;
}