#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

// ������� ��� �������� �������
void InputMatrix(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

// ������� ��� ��������� �������
void PrintMatrix(int** a, const int rowCount, const int colCount) {
    cout << endl;
    for (int i = 0; i < rowCount; i++) {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

// ������� ��� ����������� ������ ������� ������� � �������� ���������
int FindFirstZeroColumn(int** a, const int rowCount, const int colCount) {
    for (int j = 0; j < colCount; j++) {
        for (int i = 0; i < rowCount; i++) {
            if (a[i][j] == 0) {
                return j; // ��������� ����� �������
            }
        }
    }
    return -1; // ���� �������� �������� ����
}

// ������� ��� ���������� �������������� ����� (���� ��'����� ������ ��������)
int RowCharacteristic(int* row, int colCount) {
    int sum = 0;
    for (int j = 0; j < colCount; j++) {
        if (row[j] < 0 && row[j] % 2 == 0) {
            sum += row[j];
        }
    }
    return sum;
}

// ������� ��� ������������ ����� ������� �� ��������� �������������
void SortRowsByCharacteristic(int** a, const int rowCount, const int colCount) {
    // ����� ��� ��������� �������������
    int* characteristics = new int[rowCount];

    // ���������� ����� �������������
    for (int i = 0; i < rowCount; i++) {
        characteristics[i] = RowCharacteristic(a[i], colCount);
    }

    // ������� ����� �� ���������������� �� ���������
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = i + 1; j < rowCount; j++) {
            if (characteristics[i] < characteristics[j]) {
                // �������� ��������������
                swap(characteristics[i], characteristics[j]);
                // �������� �����
                swap(a[i], a[j]);
            }
        }
    }

    delete[] characteristics; // ��������� ���'��
}

int main() {
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    // ��������� ����������� ������
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    InputMatrix(a, rowCount, colCount); // �������� �������� �������
    PrintMatrix(a, rowCount, colCount); // ��������� �������

    // ����� ������� �������, �� ������ �������� �������
    int zeroColumnIndex = FindFirstZeroColumn(a, rowCount, colCount);
    if (zeroColumnIndex != -1) {
        cout << "First column with zero element: " << zeroColumnIndex << endl;
    }
    else {
        cout << "No zero elements in any column." << endl;
    }

    // ���������� ����� �� ��������������� (� ������� ��������)
    SortRowsByCharacteristic(a, rowCount, colCount);
    cout << "Matrix after sorting rows by characteristic (descending):" << endl;
    PrintMatrix(a, rowCount, colCount); // ��������� ����������� �������

    // ��������� ���'��
    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
