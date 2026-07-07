#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

using namespace std;

int main(){
    srand(static_cast<unsigned int> (time(0)));
    const int size = 7; //Размер матрицы
    double arr[size][size];

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            arr[i][j] = 1 - 2 * rand()/double(RAND_MAX);
        }
    }

    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            cout << setprecision(2) << setw(8) << arr[i][j];
        }
        cout << "\n";
    }

    //Находим макс элемент и его индекс
    double MaxEl = arr[0][0];
    int IndMaxEl = 0;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (arr[i][j] > MaxEl){
                MaxEl = arr[i][j];
                IndMaxEl = i;
            }        
        }
    }

    //Находим мин элемент и его индекс
    double MinEl = arr[0][0];
    int IndMinEl = 0;
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (arr[i][j] < MinEl){
                MinEl = arr[i][j];
                IndMinEl = j;
            }        
        }
    }

    //Находим скалярное произведение
    double Scalurpr = 0.0;
    for (int i = 0; i < size; ++i){
        Scalurpr += arr[IndMaxEl][i] * arr[i][IndMinEl];
    }

    // Вывод результатов
    cout << "Максимальный элемент: " << MaxEl << " в строке " << IndMaxEl + 1 << endl;
    cout << "Минимальный элемент: " << MinEl << " в столбце " << IndMinEl + 1 << endl;
    cout << "Скалярное произведение: " << Scalurpr << endl;

    return 0;
}