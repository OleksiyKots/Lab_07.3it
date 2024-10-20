#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// Функція для введення матриці
void InputMatrix(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// Функція для виведення матриці
void PrintMatrix(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

// Функція для знаходження номера першого стовпця з нульовим елементом
int FindFirstZeroColumn(int** a, const int rowCount, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] == 0) {
                return j; // Повертаємо номер стовпця
            }
        }
    }
    return -1; // Якщо нульових елементів немає
}

// Функція для обчислення характеристики рядка (сума від'ємних парних елементів)
int RowCharacteristic(int* row, int colCount) {
    int sum = 0;
    for (int j = 0; j < colCount; j++) {
        if (row[j] < 0 && row[j] % 2 == 0) {
            sum += row[j];
        }
    }
    return sum;
}

// Функція для перестановки рядків матриці за спаданням характеристик
void SortRowsByCharacteristic(int** a, const int rowCount, const int colCount) {
    // Масив для зберігання характеристик
    int* characteristics = new int[rowCount];

    // Заповнюємо масив характеристик
    for (int i = 0; i < rowCount; i++) {
        characteristics[i] = RowCharacteristic(a[i], colCount);
    }

    // Сортуємо рядки за характеристиками за спаданням
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = i + 1; j < rowCount; j++) {
            if (characteristics[i] < characteristics[j]) {
                // Обмінюємо характеристики
                swap(characteristics[i], characteristics[j]);
                // Обмінюємо рядки
                swap(a[i], a[j]);
            }
        }
    }

    delete[] characteristics; // Звільнення пам'яті
}

int main() {
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    // Створення двовимірного масиву
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    InputMatrix(a, rowCount, colCount); // Введення елементів матриці
    PrintMatrix(a, rowCount, colCount); // Виведення матриці

    // Пошук першого стовпця, що містить нульовий елемент
    int zeroColumnIndex = FindFirstZeroColumn(a, rowCount, colCount);
    if (zeroColumnIndex != -1) {
        cout << "First column with zero element: " << zeroColumnIndex << endl;
    }
    else {
        cout << "No zero elements in any column." << endl;
    }

    // Сортування рядків за характеристикою (в порядку спадання)
    SortRowsByCharacteristic(a, rowCount, colCount);
    cout << "Matrix after sorting rows by characteristic (descending):" << endl;
    PrintMatrix(a, rowCount, colCount); // Виведення відсортованої матриці

    // Звільнення пам'яті
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
