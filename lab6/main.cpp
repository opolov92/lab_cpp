#include <iostream>
#include <vector>
using namespace std;

void swapMinMaxElements(vector<int>& array) {
    int N = array.size();
    if (N == 0) return;
    int minIndex = 0, maxIndex = 0;
    // Find indices of the minimum and maximum elements
    for (int i = 1; i < N; ++i) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    // Swap the minimum and maximum elements
    swap(array[minIndex], array[maxIndex]);
}

void inputArray(vector<int>& array) {
    int N;
    // Input array size with validation
    do {
        cout << "Введіть розмір масиву (N > 1): ";
        cin >> N;
        if (N <= 1) {
            cout << "Розмір масиву повинен бути більше 1." << endl;
        }
    } while (N <= 1);
    
    array.resize(N);
    // Input array elements with validation
    cout << "Введіть елементи масиву: ";
    for (int i = 0; i < N; ++i) {
        while (!(cin >> array[i])) {
            cout << "Невірний ввід! Будь ласка, введіть ціле число: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }
}

void printArray(const vector<int>& array) {
    // Output the array
    cout << "Масив: ";
    for (int i = 0; i < array.size(); ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void processArray() {
    vector<int> array;
    inputArray(array);
    cout << "Початковий масив: ";
    printArray(array);
    swapMinMaxElements(array);
    cout << "Змінений масив: ";
    printArray(array);
}

void generateAndPrintGeometricProgression() {
    int N;
    double A, D;
    // Input array size with validation
    do {
        cout << "Введіть розмір масиву (N > 1): ";
        cin >> N;
        if (N <= 1) {
            cout << "Розмір масиву повинен бути більше 1." << endl;
        }
    } while (N <= 1);
    
    // Input first term and common ratio with validation
    do {
        cout << "Введіть перший член прогресії (A): ";
        cin >> A;
        if (!cin) {
            cout << "Невірний ввід! Будь ласка, введіть число для A." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    } while (!cin);
    
    do {
        cout << "Введіть знаменник прогресії (D): ";
        cin >> D;
        if (!cin) {
            cout << "Невірний ввід! Будь ласка, введіть число для D." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    } while (!cin);

    // Create and fill the array
    vector<double> array(N);
    array[0] = A;
    for (int i = 1; i < N; ++i) {
        array[i] = array[i - 1] * D;
    }
    // Output the array
    cout << "Масив: ";
    for (int i = 0; i < N; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void menu() {
    int choice;
    do {
        // Display the menu
        cout << "\nОберіть завдання:\n";
        cout << "1. Генерація та виведення геометричної прогресії\n";
        cout << "2. Обмін місцями мінімального і максимального елементів масиву\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        
        // Input menu choice with validation
        while (!(cin >> choice) || (choice < 0 || choice > 2)) {
            cout << "Невірний вибір! Спробуйте ще раз: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }

        switch (choice) {
            case 1:
                generateAndPrintGeometricProgression();
                break;
            case 2:
                processArray();
                break;
            case 0:
                cout << "Вихід з програми.\n";
                break;
            default:
                break; // In case it's an invalid choice, but validation already ensures it won't happen
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}
