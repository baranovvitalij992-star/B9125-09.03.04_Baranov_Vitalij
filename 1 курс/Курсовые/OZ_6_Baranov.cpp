#include <iostream>
#include <cmath>

using namespace std;

int main(){
    const double Eps = 1E-5; //заданная точность
    double N, D; cin >> N >> D; //Делимое и делитель
    double x0 = 1.0 / D; //Заданное начальное приближение
    double x1;
    
    //Вычисляем x1
    do {
         x1 = x0 * (2 - D * x0);
         x0 = x1;
    } while (fabs(x1 - x0) >= Eps);

    double result = x1 * N; //Результат

    cout << "Результат деления " << N << "/" << D << " = " << result;





}