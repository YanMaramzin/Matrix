#include <iostream>
#include "matrix.h"

int main()
{
    Matrix<int, 0> matrix;

    // главная диагональ
    for (int i = 0; i < 10; ++i)
        matrix[i][i] = i;

    // побочная диагональ
    for (int i = 0; i < 10; ++i)
        matrix[i][9 - i] = 9 - i;

    // вывод фрагмента [1,1] .. [8,8]
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << "\n";
    }

    std::cout << "Occupied cells: " << matrix.size() << "\n";

    // вывод всех занятых
    for (auto const &[pos, value]: matrix) {
        auto [x, y] = pos;
        std::cout << x << " " << y << " " << value << "\n";
    }
}

