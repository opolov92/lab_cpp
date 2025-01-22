#include <iostream>
#include <cmath> // Including the math library
using namespace std;

int main() {
    // Task 1: Integer calculations
    cout << "Завдання 1 (Integer4): Обчислення цілих чисел\n";
    
    // Variables for lengths
    int A, B, segments;
    
    // Input data
    cout << "Введіть довжину відрізка A: ";
    cin >> A;
    cout << "Введіть довжину відрізка B (B < A): ";
    cin >> B;
    
    // Validation
    if (A <= B) {
        cout << "Помилка: A повинно бути більше за B.\n";
        return 1; // Exit with error
    }
    
    if (A <= 0) {
        cout << "Помилка: Відрізок А не може бути менше одиниці\n";
        return 1; // Exit with error
    }
    
    if (B <= 0) {
        cout << "Помилка: Відрізок B не може бути менше одиниці\n";
        return 1; // Exit with error
    }
    
    // Calculate the number of segments B that fit into A
    segments = A / B;
    
    // Output the result
    cout << "Кількість відрізків B, які можна розмістити на відрізку A: " << segments << endl;
    
    // Task 2: Boolean calculations
    cout << "\nЗавдання 2 (Boolean4): Логічні обчислення\n";
    
    // Variables to check conditions
    int C, D;
    cout << "Введіть ціле число A: ";
    cin >> C;
    cout << "Введіть ціле число B: ";
    cin >> D;
    
    // Check the truth of the statement
    bool is_true = (C > 2) && (D <= 3);
    
    // Output the result
    cout << "Справедливість висловлювання «A > 2 і B ≤ 3»: " << boolalpha << is_true << endl;
    
    // Task 3: Math expressions with new formula
    cout << "\nЗавдання 3: Математичні обчислення\n";
    
    // Constants and variables
    const double pi = M_PI; // Pi constant
    double x, numerator, denominator, y;
    
    // Input value for x
    cout << "Введіть дійсний аргумент x: ";
    cin >> x;
    
    // Calculate the new expression
    numerator = 4 * pi * std::pow(std::sin(4 * pi + x), 2) * std::cbrt(std::abs(x - 0.5 * std::exp(x))); // Numerator
    denominator = std::pow(3, x - 1) * std::log10(std::sin(37 * pi / 180)); // Denominator
    
    // Avoid division by zero
    if (denominator == 0) {
        cout << "Помилка: Ділення на нуль у математичному виразі.\n";
        return 1; // Exit with error
    }
    
    // Final calculation for y
    y = numerator / denominator;
    
    // Output the result
    cout << "Значення функції y: " << y << endl;
    
    
    return 0;
}
