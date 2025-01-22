#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Task 1

// Function to calculate the perimeter of an equilateral triangle
void calculate_triangle_perimeter(double triangle_side, double &perimeter);

// Function to calculate the area of an equilateral triangle
void calculate_triangle_area(double triangle_side, double &area);

// Function to calculate both the perimeter and area of the triangle
void calculate_triangle_properties_by_triangle_length();

// Task 2

// Function to input and validate integers A and B
bool input_and_validate(int &A, int &B);

// Function to check the logical condition A > 2 and B <= 3
bool check_condition(int A, int B);

// Function to handle input, condition checking, and output result
void process_input_condition();

// Task 3

// Function to input and validate integers A and B (within [-100, 100])
bool input_and_validate_segments(int &A, int &B);

// Function to calculate the number of segments B that fit in segment A
int calculate_segments(int A, int B);

// Function to output the result
void output_result(int A, int B, int segments);

// Function to process input, calculation, and output result
void process_segment_calculation();

// Menu-driven program to select and execute tasks
int main() {
    int choice;
    
    do {
        // Display menu
        cout << "\nОберіть завдання для виконання:" << endl;
        cout << "1. Обчислення периметра і площі рівностороннього трикутника " << endl;
        cout << "2. Перевірити істинність висловлювання: «Справедливі нерівності A> 2 і B ≤ 3» " << endl;
        cout << "3. Обчислення кількості відрізків B, які розміщуються на відрізку A " << endl;
        cout << "0. Вихід" << endl;
        
        // Validating input choice
        bool valid_choice = false;
        while (!valid_choice) {
            cout << "Ваш вибір: ";
            cin >> choice;
            
            if (cin.fail()) {
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Неправильний вибір. Спробуйте ще раз." << endl;
            } else {
                valid_choice = true; // Valid choice entered
            }
        }
        
        switch (choice) {
            case 1: {
                // Task 1: Calculate triangles area and perimeter
                calculate_triangle_properties_by_triangle_length();
                break;
            }
            case 2: {
                // Task 2: Check inputs
                process_input_condition();
                break;
            }
            case 3: {
                // Task 3: Calculate the number of segments
                process_segment_calculation();
                break;
            }
            case 0:
                cout << "Вихід..." << endl;
                break;
            default:
                cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }
        
    } while (choice != 0);
    
    return 0;
}

// Task 1 Definitions

void calculate_triangle_perimeter(double triangle_side, double &perimeter) {
    perimeter = 3 * triangle_side; // Perimeter formula for equilateral triangle
}

void calculate_triangle_area(double triangle_side, double &area) {
    area = (triangle_side * triangle_side * sqrt(3)) / 4; // Area formula for equilateral triangle
}

void calculate_triangle_properties_by_triangle_length() {
    double area, perimeter;
    double triangle_side;
    
    // Asking user to input the side length of the triangle
    cout << "Введіть довжину сторони A: ";
    cin >> triangle_side;
    
    // Validate the input for triangle side
    if (triangle_side < -100 || triangle_side > 100) {
        cout << "Помилка! Введена довжина сторони повинна бути в межах [-100, 100]." << endl;
        return;
    }
    
    // Calculating area and perimeter
    calculate_triangle_area(triangle_side, area);
    calculate_triangle_perimeter(triangle_side, perimeter);
    
    // Outputting
    cout << "Периметр трикутника: " << perimeter << endl;
    cout << "Площа трикутника: " << area << endl;
}

// Task 2 Definitions

bool input_and_validate(int &A, int &B) {
    cout << "Введіть ціле число A: ";
    cin >> A;
    
    // Check if the input is valid and in range [-100, 100]
    if (cin.fail() || A < -100 || A > 100) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Помилка! Ви ввели некоректне число для A. Воно повинно бути в межах [-100, 100]." << endl;
        return false;
    }
    
    cout << "Введіть ціле число B: ";
    cin >> B;
    
    // Check if the input is valid and in range [-100, 100]
    if (cin.fail() || B < -100 || B > 100) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Помилка! Ви ввели некоректне число для B. Воно повинно бути в межах [-100, 100]." << endl;
        return false;
    }
    
    return true; // Inputs are valid
}

bool check_condition(int A, int B) {
    return (A > 2 && B <= 3); // Check if both conditions are true
}

void process_input_condition() {
    int A, B;
    
    // Input and validation of A and B
    while (!input_and_validate(A, B)) {
        // Keep asking for input until it is valid
        cout << "Будь ласка, спробуйте ще раз." << endl;
    }
    
    // If inputs are valid, check the condition
    bool result = check_condition(A, B);
    
    // Output the result
    if (result) {
        cout << "Умови істинні: A > 2 і B <= 3" << endl;
    } else {
        cout << "Умови не виконуються." << endl;
    }
}

// Task 3 Definitions

bool input_and_validate_segments(int &A, int &B) {
    cout << "Введіть ціле додатне число A (A > B): ";
    cin >> A;
    
    // Validate input for A within [-100, 100]
    if (cin.fail() || A <= 0 || A < -100 || A > 100) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Помилка! Ви ввели некоректне число для A. Воно повинно бути додатним числом в межах [-100, 100]." << endl;
        return false;
    }
    
    cout << "Введіть ціле додатне число B (B < A): ";
    cin >> B;
    
    // Validate input for B within [-100, 100]
    if (cin.fail() || B <= 0 || B >= A || B < -100 || B > 100) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Помилка! Ви ввели некоректне число для B. Воно повинно бути додатним числом в межах [-100, 100] і меншим за A." << endl;
        return false;
    }
    
    return true; // Inputs are valid
}

int calculate_segments(int A, int B) {
    return A / B; // Using integer division to find how many B fit in A
}

void output_result(int A, int B, int segments) {
    cout << "На відрізку довжиною " << A << " розміщується " << segments << " відрізків довжиною " << B << "." << endl;
}

void process_segment_calculation() {
    int A, B;
    
    // Input and validation of A and B
    while (!input_and_validate_segments(A, B)) {
        // Keep asking for input until it is valid
        cout << "Будь ласка, спробуйте ще раз." << endl;
    }
    
    // Calculate the number of segments
    int segments = calculate_segments(A, B);
    
    // Output the result
    output_result(A, B, segments);
}
