// Author: superzhou03
// Created time: 2023-12-28
#include <iostream>
#include <fstream>
#include <random>
#include <vector>

using namespace std;

vector<vector<int>> initialize_matrix(int size) {
    // 创建随机数生成器
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 9);

    // 生成范围为 0 到 9 的随机整数
    vector<vector<int>> matrix(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = dist(gen);
        }
    }
    return matrix;
}

void save_matrix(const string &filename, vector<vector<int>> matrix, int size) {
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                outputFile << matrix[i][j] << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Matrix saved to file." << endl;
    } else {
        cerr << "Failed to open the file for writing." << endl;
    }
}

int main() {
    vector<vector<int>> matrix1 = initialize_matrix(1000);
    vector<vector<int>> matrix2 = initialize_matrix(1000);
    save_matrix("matrix1.txt", matrix1, 1000);
    save_matrix("matrix2.txt", matrix2, 1000);
}
