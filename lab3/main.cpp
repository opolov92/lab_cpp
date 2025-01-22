#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Task 1: Count positive numbers
void countPositivesFromInput() {
    int a, b, c;
    int count = 0;
    
    // Prompt the user to input three integers
    cout << "Введіть три цілих числа через пробіл: ";
    
    // Validate the input to ensure that all values are integers
    while (!(cin >> a >> b >> c)) {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        cout << "Будь ласка, введіть правильні цілі числа через пробіл: ";
    }
    
    // Check each number to see if it is positive
    if (a > 0) count++;
    if (b > 0) count++;
    if (c > 0) count++;
    
    // Print the count of positive numbers
    cout << "Кількість додатних чисел: " << count << endl;
}

// Task 2: Check if the point is inside the shaded area
void checkPointInShapes() {
    double radius, cathetus, x, y;
    
    // Input radius, cathetus, and point coordinates
    cout << "Введіть радіус круга: ";
    while (!(cin >> radius) || radius <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Радіус повинен бути додатнім числом. Введіть знову: ";
    }

    cout << "Введіть довжину катета рівнобедреного трикутника: ";
    while (!(cin >> cathetus) || cathetus <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Довжина катета повинна бути додатнім числом. Введіть знову: ";
    }

    cout << "Введіть координати точки (x y): ";
    while (!(cin >> x >> y)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Введіть правильні координати точки: ";
    }
    
    // Center of the circle
    double x0 = 0.0;
    double y0 = 0.0;
    
    // Check if the point is inside the circle
    bool inCircle = (pow(x - x0, 2) + pow(y - y0, 2) <= pow(radius, 2));
    
    // Calculate the height of the isosceles triangle
    double h = sqrt(pow(cathetus, 2) - pow(cathetus / 2, 2));
    
    // Calculate the equations of the triangle sides
    double yAB = -h / (cathetus / 2) * (x + cathetus / 2) + h; // Side AB
    double yAC = h / (cathetus / 2) * (x - cathetus / 2) + h; // Side AC
    
    // Check if the point is below all sides of the triangle
    bool inTriangle = (y <= yAB && y <= yAC && y <= 0);
    
    // Output results
    if (inCircle) {
        cout << "Точка (" << x << ", " << y << ") входить у круг." << endl;
    } else {
        cout << "Точка (" << x << ", " << y << ") не входить у круг." << endl;
    }
    if (inTriangle) {
        cout << "Точка (" << x << ", " << y << ") входить у рівнобедрений трикутник." << endl;
    } else {
        cout << "Точка (" << x << ", " << y << ") не входить у рівнобедрений трикутник." << endl;
    }
}

// Task 3: Calculate the area and perimeter of a shape
void calculateShapeProperties() {
    int choice;
    double radius, cathetus;
    
    // Prompt user for shape choice
    cout << "Оберіть фігуру для обчислення (1 - Коло, 2 - Рівнобедрений трикутник): ";
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неправильний вибір. Будь ласка, виберіть 1 або 2: ";
    }
    
    // Calculate properties based on the chosen shape
    if (choice == 1) {
        // Input radius for circle
        cout << "Введіть радіус круга: ";
        while (!(cin >> radius) || radius <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Радіус повинен бути додатнім числом. Введіть знову: ";
        }
        // Calculate area and perimeter of the circle
        double area = M_PI * pow(radius, 2);
        double perimeter = 2 * M_PI * radius;
        // Output results
        cout << "Площа круга: " << area << endl;
        cout << "Периметр круга: " << perimeter << endl;
    } else if (choice == 2) {
        // Input cathetus for isosceles triangle
        cout << "Введіть довжину катета рівнобедреного трикутника: ";
        while (!(cin >> cathetus) || cathetus <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Довжина катета повинна бути додатнім числом. Введіть знову: ";
        }
        // Calculate area and perimeter of the isosceles triangle
        double height = sqrt(pow(cathetus, 2) - pow(cathetus / 2, 2));
        double area = (cathetus * height) / 2;
        double perimeter = 2 * cathetus + cathetus; // Base is equal to cathetus
        // Output results
        cout << "Площа рівнобедреного трикутника: " << area << endl;
        cout << "Периметр рівнобедреного трикутника: " << perimeter << endl;
    }
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\nОберіть задачу:\n";
        cout << "1 - Підрахунок додатних чисел\n";
        cout << "2 - Перевірка попадання точки в фігуру\n";
        cout << "3 - Обчислення площі та периметра фігури\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        while (!(cin >> choice) || (choice < 0 || choice > 3)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Невірний вибір. Спробуйте ще раз: ";
        }
        
        switch (choice) {
            case 1:
                countPositivesFromInput();
                break;
            case 2:
                checkPointInShapes();
                break;
            case 3:
                calculateShapeProperties();
                break;
            case 0:
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0);
    
    return 0;
}
