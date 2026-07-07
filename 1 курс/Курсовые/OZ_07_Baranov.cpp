#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int size = 9; // Размер матрицы
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    int arr[size][size];

    // Заполнение матрицы случайными числами от 0 до 100
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = rand() % 101;
        }
    }

    // Вывод матрицы с форматированием
    cout << "Матрица 9x9:\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << setw(4) << arr[i][j]; // Форматирование для выравнивания
        }
        cout << "\n";
    }

    // Сумма контура
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Проверяем, находится ли элемент на контуре
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                s1 += arr[i][j];
            }
        }
    }

    // Сумма главных диагоналей
    for (int i = 0; i < size; i++) {
        s2 += arr[i][i]; // Главная диагональ
        s2 += arr[i][size - i - 1]; // Побочная диагональ
    }
    s2 -= arr[size / 2][size / 2]; // Убираем центральный элемент, чтобы не был учтен дважды

    // Сумма ромба
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (abs(i - (size / 2)) + abs(j - (size / 2)) <= size / 2) {
                s3 += arr[i][j];
            }
        }
    }

    // Сумма песочных часов
    for (int i = 0; i < size; i++) {
        if (i <= size / 2) { // Верхняя часть песочных часов
            for (int j = i; j < size - i; j++) {
                s4 += arr[i][j];
            }
        } else { // Нижняя часть песочных часов
            int row = size - 1 - i;
            for (int j = size - row - 1; j < row + 1; j++) {
                s4 += arr[row][j];
            }
        }
    }

    // Вывод результата
    cout << "Сумма контура: " << s1 << "\n";
    cout << "Сумма главных диагоналей: " << s2 << "\n";
    cout << "Сумма ромба: " << s3 << "\n";
    cout << "Сумма песочных часов: " << s4 << endl;

    return 0;
}
