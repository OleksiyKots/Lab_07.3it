#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.3it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest073
{
    TEST_CLASS(FindFirstZeroColumnTests)
    {
    public:

        TEST_METHOD(TestFindFirstZeroColumn)
        {
            const int rowCount = 3;
            const int colCount = 4;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount];
            }

            // Тест 1: Перший стовпець містить нуль
            matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; matrix[0][3] = 4;
            matrix[1][0] = 0; matrix[1][1] = 5; matrix[1][2] = 6; matrix[1][3] = 7;
            matrix[2][0] = 8; matrix[2][1] = 9; matrix[2][2] = 10; matrix[2][3] = 11;
            Assert::AreEqual(0, FindFirstZeroColumn(matrix, rowCount, colCount));

            // Тест 2: Жодного нуля в матриці
            matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3; matrix[0][3] = 4;
            matrix[1][0] = 5; matrix[1][1] = 6; matrix[1][2] = 7; matrix[1][3] = 8;
            matrix[2][0] = 9; matrix[2][1] = 10; matrix[2][2] = 11; matrix[2][3] = 12;
            Assert::AreEqual(-1, FindFirstZeroColumn(matrix, rowCount, colCount));

            // Звільнення пам'яті
            for (int i = 0; i < rowCount; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
