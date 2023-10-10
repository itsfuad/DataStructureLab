#include <iostream>

int main() {

    int row1 = 5, col1 = 5;
    int row2 = 5, col2 = 6;

    long matrix1[row1][col1] = {{1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {1, 2, 3, 4, 5}};

    long matrix2[row2][col2] = {{1, 2, 3, 4, 5, 6},
                                {7, 8, 9, 0, 11, 12},
                                {1, 2, 3, 4, 5, 6},
                                {7, 8, 9, 10, 11, 12},
                                {1, 2, 3, 4, 5, 6}};

    long result[row1][col2] = {0};


    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    std::cout << "Multiplication\n";
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    int transpose[col2][row1];

    for (int i = 0; i < col2; ++i) {
        for (int j = 0; j < row1; ++j) {
            transpose[i][j] = result[j][i];
        }
    }

    std::cout << "Transpose of Resulting Matrix:\n";
    for (int i = 0; i < col2; ++i) {
        for (int j = 0; j < row1; ++j) {
            std::cout << transpose[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
