#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<int>> readMatrixFromFile(const std::string &filename, int row, int col) {
    std::vector<std::vector<int>> matrix(row, std::vector<int>(col, 0));
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                inputFile >> matrix[i][j];
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Failed to open the file for reading." << std::endl;
    }

    return matrix;
}

// 将矩阵数据写入文件
void writeMatrixToFile(const std::string &filename, const std::vector<std::vector<int>> &matrix) {
    std::ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const auto &row: matrix) {
            for (const auto &value: row) {
                outputFile << value << " ";
            }
            outputFile << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Failed to open the file for writing." << std::endl;
    }
}

int main() {
    const std::string inputFile = "matrix1.txt";
    const std::string outputFile = "result.txt";
    const int rows = 100;
    const int cols = 100;

    // 从文件中读取矩阵数据
    std::vector<std::vector<int>> matrix = readMatrixFromFile(inputFile, rows, cols);

    // 打印读取的矩阵数据
    for (const auto &row: matrix) {
        for (const auto &value: row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // 将矩阵数据写入文件
    writeMatrixToFile(outputFile, matrix);

    std::cout << "Matrix has been written to the output file." << std::endl;

    return 0;
}