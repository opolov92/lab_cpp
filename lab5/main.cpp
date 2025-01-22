#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

// Function to check if the input for epsilon is correct
bool isValidEpsilon(double epsilon) {
    return epsilon >= 1e-20 && epsilon <= 1e-5;
}

// Function to check if the input for g is correct
bool isValidG(double g) {
    return g >= 1e2 && g <= 1e5;
}

// Function to calculate the factorial
unsigned long long factorial(int k) {
    if (k == 0 || k == 1) return 1;
    unsigned long long result = 1;
    for (int i = 2; i <= k; ++i) {
        result *= i;
    }
    return result;
}

// Function to check if a point is inside a triangle
bool isInsideTriangle(double x, double y, double a) {
    // Coordinates of the vertices of the equilateral triangle
    double x1 = 0, y1 = 0;
    double x2 = a, y2 = 0;
    double x3 = a / 2, y3 = a * sqrt(3) / 2;
    // Barycentric coordinates
    double denominator = ((y2 - y3)*(x1 - x3) + (x3 - x2)*(y1 - y3));
    double alpha = ((y2 - y3)*(x - x3) + (x3 - x2)*(y - y3)) / denominator;
    double beta = ((y3 - y1)*(x - x3) + (x1 - x3)*(y - y3)) / denominator;
    double gamma = 1.0 - alpha - beta;
    return (alpha >= 0) && (beta >= 0) && (gamma >= 0);
}

// Function to check if a point is inside a circle
bool isInsideCircle(double x, double y, double r) {
    return (x * x + y * y <= r * r);
}

// Function to calculate the number of points inside the triangle and circle
void calculatePoints() {
    int n;
    double a, r;
    // Input number of points
    cout << "Введіть кількість точок: ";
    cin >> n;
    while (cin.fail() || n <= 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Некоректний ввід. Введіть додатнє ціле число для кількості точок: ";
        cin >> n;
    }
    
    // Input side of the triangle
    cout << "Введіть сторону трикутника: ";
    cin >> a;
    while (cin.fail() || a <= 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Некоректний ввід. Введіть додатнє число для сторони трикутника: ";
        cin >> a;
    }

    // Input radius of the circle
    cout << "Введіть радіус кола: ";
    cin >> r;
    while (cin.fail() || r <= 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Некоректний ввід. Введіть додатнє число для радіусу кола: ";
        cin >> r;
    }

    vector<pair<double, double> > points(n);
    // Input coordinates of points
    for (int i = 0; i < n; ++i) {
        cout << "Введіть координати точки " << i + 1 << " (x y): ";
        cin >> points[i].first >> points[i].second;
        while (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Некоректний ввід. Введіть правильні координати для точки " << i + 1 << ": ";
            cin >> points[i].first >> points[i].second;
        }
    }

    int countTriangle = 0, countCircle = 0;
    // Check each point
    for (int i = 0; i < n; ++i) {
        if (isInsideTriangle(points[i].first, points[i].second, a)) {
            countTriangle++;
        }
        if (isInsideCircle(points[i].first, points[i].second, r)) {
            countCircle++;
        }
    }

    // Output results
    cout << "Кількість точок у трикутнику: " << countTriangle << endl;
    cout << "Кількість точок у колі: " << countCircle << endl;
}

// Function to calculate the product expression
void calculateAndPrintProduct() {
    double x;
    int n;
    // Input x and n
    cout << "Введіть дійсне число x: ";
    cin >> x;
    while (cin.fail()) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Некоректний ввід. Введіть дійсне число x: ";
        cin >> x;
    }

    cout << "Введіть натуральне число n: ";
    cin >> n;
    while (cin.fail() || n <= 0) {
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Некоректний ввід. Введіть додатнє ціле число для n: ";
        cin >> n;
    }

    double product = 1.0;
    // Calculate the product
    for (int k = 1; k <= n; ++k) {
        double numerator = pow(1 - x, k + 1) + 1;
        unsigned long long denominator = factorial(k - 1);
        product *= numerator / denominator;
    }

    // Output the result of the product
    cout << "Значення виразу: " << product << endl;

    // Output every third or fourth element based on the variant
    if (n % 2 == 0) {
        cout << "Значення кожного третього елемента:" << endl;
        for (int k = 3; k <= n; k += 3) {
            double numerator = pow(1 - x, k + 1) + 1;
            unsigned long long denominator = factorial(k - 1);
            double element = numerator / denominator;
            cout << "Елемент " << k << ": " << element << endl;
        }
    } else {
        cout << "Значення кожного четвертого елемента:" << endl;
        for (int k = 4; k <= n; k += 4) {
            double numerator = pow(1 - x, k + 1) + 1;
            unsigned long long denominator = factorial(k - 1);
            double element = numerator / denominator;
            cout << "Елемент " << k << ": " << element << endl;
        }
    }
}

// Function to calculate the sum of the series
void calculateSeriesSum() {
    double epsilon, g;
    cout << "Введіть малу величину для переривання циклу обчислення суми збіжного ряду (epsilon): ";
    cin >> epsilon;
    if (!isValidEpsilon(epsilon)) {
        cout << "Некоректне значення epsilon. Спробуйте ще раз." << endl;
        return;
    }

    cout << "Введіть величину для переривання циклу обчислення суми розбіжного ряду (g): ";
    cin >> g;
    if (!isValidG(g)) {
        cout << "Некоректне значення g. Спробуйте ще раз." << endl;
        return;
    }

    double sum = 0.0;
    int n = 1;
    while (true) {
        double term = pow(n, 3) / pow(2, n + 1);
        if (fabs(term) < epsilon) {
            cout << "Ряд збігається. Умова |u_n| < epsilon виконана." << endl;
            break;
        }
        if (fabs(term) > g) {
            cout << "Ряд розбігається. Умова |u_n| > g виконана." << endl;
            break;
        }
        sum += term;
        n++;
    }

    cout << "Сума ряду: " << sum << endl;
}

// Function to display the menu and handle user input
void displayMenu() {
    int choice;
    while (true) {
        cout << "Меню:" << endl;
        cout << "1. Обчислити кількість точок у трикутнику та колі" << endl;
        cout << "2. Обчислити значення виразу" << endl;
        cout << "3. Обчислити суму ряду" << endl;
        cout << "4. Вийти" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Некоректний вибір. Спробуйте ще раз." << endl;
            continue; // Skip the rest of the loop and ask for input again
        }

        switch (choice) {
            case 1:
                calculatePoints();
                break;
            case 2:
                calculateAndPrintProduct();
                break;
            case 3:
                calculateSeriesSum();
                break;
            case 4:
                cout << "Вихід з програми." << endl;
                return; // Exit the function, thus ending the program
            default:
                cout << "Некоректний вибір. Спробуйте ще раз." << endl;
        }
    }
}

int main() {
    // Call the function to display the menu
    displayMenu();
    return 0;
}
