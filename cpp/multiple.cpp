#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

//using namespace std::chrono;

int row = 1000, col = 1000;
//int matrix1[1000][1000], matrix2[1000][1000], result[1000][1000];
std::vector<std::vector<int>> matrix1(row, std::vector<int>(col, 0));
std::vector<std::vector<int>> matrix2(row, std::vector<int>(col, 0));
std::vector<std::vector<int>> result(row, std::vector<int>(col, 0));

int i, j, k;
const std::string filaname = "result1.txt";

void writeMatrix(const std::string &filename, const std::vector<std::vector<int>> &matrix);
void initMatrix();

int main() {
    initMatrix();
    // 记录开始时间
    clock_t startTime, endTime;
    startTime = clock();

    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            result[i][j] = 0;
            for (k = 0; k < 1000; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    endTime = clock();
    writeMatrix(filaname, result);
    std::cout << "Multiple Total Time : " << (double) (endTime - startTime)  << " ms"
              << std::endl;
    return 0;
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
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            matrix1[i][j] = i + 1;
            for (k = 0; k < 1000; k++)
                matrix2[j][k] = k + 1;
        }
    }
}
