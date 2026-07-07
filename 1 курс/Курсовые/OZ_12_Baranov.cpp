#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    // Создание матрицы со случайными числами
    srand(static_cast<unsigned int>(time(0)));
    const int str = 10;
    const int stolb = 15;
    int matrixx[str][stolb];
    
    for (int i = 0; i < str; ++i) {
        for (int j = 0; j < stolb; ++j) {
            matrixx[i][j] = rand() % 101;
        }
    }

    // Вывод матрицы
    cout << "Матрица" << "\n";
    for (int i = 0; i < str; ++i) {
        for (int j = 0; j < stolb; ++j) {
            cout << setprecision(3) << setw(5) << matrixx[i][j];
        }
        cout << "\n";
    }

    // Проверка на седловые точки
    for (int i = 0; i < str; ++i) {
        for (int j = 0; j < stolb; ++j) {
            int num = matrixx[i][j];
            bool isSaddlePoint = true;

            // Проверка, является ли элемент наименьшим в своей строке и наибольшим в своем столбце
            bool isMinInRow = true;
            bool isMaxInCol = true;

            for (int k = 0; k < stolb; ++k) {
                if (matrixx[i][k] < num) {
                    isMinInRow = false;
                }
            }
            for (int k = 0; k < str; ++k) {
                if (matrixx[k][j] > num) {
                    isMaxInCol = false;
                }
            }

            if (isMinInRow && isMaxInCol) {
                cout << "Седловая точка (индекс матрицы): " << i << ", " << j << endl;
                isSaddlePoint = false;
            }

            // Проверка, является ли элемент наибольшим в своей строке и наименьшим в своем столбце
            bool isMaxInRow = true;
            bool isMinInCol = true;

            for (int k = 0; k < stolb; ++k) {
                if (matrixx[i][k] > num) {
                    isMaxInRow = false;
                }
            }
            for (int k = 0; k < str; ++k) {
                if (matrixx[k][j] < num) {
                    isMinInCol = false;
                }
            }

            if (isMaxInRow && isMinInCol) {
                cout << "Седловая точка (индекс матрицы): " << i << ", " << j << endl;
            }
        }
    }

    return 0;
}