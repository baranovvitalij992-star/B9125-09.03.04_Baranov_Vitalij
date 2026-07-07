#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int size = 3;
    int str_sum, stolb_sum, diag1_sum, diag2_sum;
    int magic_sum = size * (size * size + 1) / 2;
    int square[size][size];

    // Заполнение матрицы случайными числами
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            square[i][j] = rand() % (size * size) + 1;
        }
    }

    cout << "Квадратная матрица: " << "\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << setprecision(3) << setw(5) << square[i][j];
        }
        cout << "\n";
    }

    // Проверка на уникальность
    bool isMagicSquare = true;
    bool numbers[size * size + 1] = {false}; // Для отслеживания уникальности чисел

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int num = square[i][j];
            if (num < 1 || num > size * size || numbers[num]) {
                isMagicSquare = false;
            }
            numbers[num] = true;
        }
    }

    // Проверка сумм
    for (int i = 0; i < size && isMagicSquare; ++i) {
        str_sum = 0;
        stolb_sum = 0;
        for (int j = 0; j < size; ++j) {
            stolb_sum += square[j][i];
            str_sum += square[i][j];
        }
        if (stolb_sum != magic_sum || str_sum != magic_sum) {
            isMagicSquare = false;
        }
    }

    // Проверка диагоналей
    diag1_sum = diag2_sum = 0;
    for (int i = 0; i < size; ++i) {
        diag1_sum += square[i][i];
        diag2_sum += square[i][size - 1 - i];
    }
    if (diag1_sum != magic_sum || diag2_sum != magic_sum) {
        isMagicSquare = false;
    }

    if (isMagicSquare) {
        cout << "Квадратная матрица является магическим квадратом" << endl;
    } else {
        cout << "Квадратная матрица не является магическим квадратом" << endl;
    }

    return 0;
}