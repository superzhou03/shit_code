// Author: superzhou03
// Created time: 2023-12-30
#include<iostream>
#include<vector>
#include<thread>
#include<ctime>
#include <fstream>

int row = 1000, col = 1000;
const std::string filaname = "result2.txt";
std::vector<std::vector<int>> matrix1(row, std::vector<int>(col, 0));
std::vector<std::vector<int>> matrix2(row, std::vector<int>(col, 0));
std::vector<std::vector<int>> result(row, std::vector<int>(col, 0));


void mulMulti(int rowStart, int rowEnd);
void writeMatrix(const std::string &filename, const std::vector<std::vector<int>> &matrix);
void initMatrix();

int main() {
    clock_t startTime, endTime;
    initMatrix();
    startTime = clock();
    
    int m = matrix1.size();
    int n = matrix2[0].size();
    result.resize(m);
    
    for (int i = 0; i < m; ++i)
        result[i].resize(n);
    int div = m / 4;
    std::thread t1(mulMulti, 0, div);
    std::thread t2(mulMulti, div, 2 * div);
    std::thread t3(mulMulti, 2 * div, 3 * div);
    std::thread t4(mulMulti, 3 * div, m);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    endTime = clock();
    writeMatrix(filaname, result);
    std::cout << "Multiple Thread Total Time : " << (double) (endTime - startTime)  << " ms"
              << std::endl;

    return 0;
}

void mulMulti(int rowStart, int rowEnd) {
    int t = matrix1[0].size();
    int n = matrix2[0].size();
    // ikj is faster than ijk (memory access issues)
    for (int i = rowStart; i < rowEnd; i++)
        for (int k = 0; k < t; k++) {
            int s = matrix1[i][k];
            for (int j = 0; j < n; j++)
                result[i][j] += s * matrix2[k][j];
        }
}
void writeMatrix(const std::string &filename, const std::vector<std::vector<int>> &matrix) {
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

void initMatrix(){
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            matrix1[i][j] = i + 1;
            for (int k = 0; k < 1000; k++)
                matrix2[j][k] = k + 1;
        }
    }
}
