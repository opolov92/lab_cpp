#include <iostream>
using namespace std;

int main() {
    // Task 1 - Calculate the perimeter of a square
    cout << "Задача 1: Обчислення периметра квадрата" << endl;

    // Variable declaration
    double a, P;

    // Input
    cout << "Введіть сторону квадрата a: ";
    cin >> a;

    // Validate input
    if (a <= 0) {
        cout << "Помилка: Сторона квадрата має бути позитивним числом!" << endl;
        return 1;
    }

    // Calculate the perimeter
    P = 4 * a;

    // Output
    cout << "Периметр квадрата (P): " << P << endl;

    // Task 2 - Calculate the circumference of a circle
    cout << "\nЗадача 2: Обчислення довжини кола" << endl;

    // Variable declaration
    double d, L;
    const double PI = 3.14; // hardcoded value of Pi

    // Input
    cout << "Введіть діаметр кола d: ";
    cin >> d;

    // Validate input
    if (d <= 0) {
        cout << "Помилка: Діаметр кола має бути позитивним числом!" << endl;
        return 1;
    }

    // Calculate the circumference
    L = PI * d;

    // Output
    cout << "Довжина кола (L): " << L << endl;

    // Success exit
    return 0;
}
