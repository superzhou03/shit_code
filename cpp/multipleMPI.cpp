// Author: superzhou03
// Created time: 2023-12-28
#include <mpi.h>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

const int AColSize = 1000, ARowSize = 1000, BColSize = 1000;
double matrix1[ARowSize][AColSize] = {0};
double matrix2[AColSize][BColSize] = {0};
double ans_buffer[BColSize] = {0};
std::vector<std::vector<int>> ans(ARowSize, std::vector<int>(AColSize, 0));
double buffer[AColSize] = {0};
int numSent = 0, numProcess = 0;
const int m_id = 0, end_tag = 0;
MPI_Status status;
const std::string outputFile = "result3.txt";

void master() {
    for (int i = 0; i < ARowSize; i++) {
        for (int j = 0; j < AColSize; j++) {
            matrix1[i][j] = i + 1;
            for (int k = 0; k < BColSize; k++)
                matrix2[j][k] = k + 1;
        }
    }
    MPI_Bcast(matrix2, AColSize * BColSize, MPI_DOUBLE, m_id, MPI_COMM_WORLD);
    for (int i = 0; i < std::min(numProcess - 1, ARowSize); i++) {
        for (int j = 0; j < AColSize; j++) {
            buffer[j] = matrix1[i][j];
        }
        MPI_Send(buffer, AColSize, MPI_DOUBLE, i + 1, i + 1, MPI_COMM_WORLD);
        numSent++;
    }
    for (int i = 0; i < ARowSize; i++) {
        MPI_Recv(ans_buffer, BColSize, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        for (int j = 0; j < BColSize; j++) {
            ans[status.MPI_TAG - 1][j] = ans_buffer[j];
        }
        int sender = status.MPI_SOURCE;
        if (numSent < ARowSize) {
            for (int j = 0; j < AColSize; j++) {
                buffer[j] = matrix1[numSent][j];
            }
            MPI_Send(buffer, AColSize, MPI_DOUBLE, sender, numSent + 1, MPI_COMM_WORLD);
            numSent++;
        } else {
            MPI_Send(0, 0, MPI_DOUBLE, sender, end_tag, MPI_COMM_WORLD);
        }
    };
}


void slave() {
    MPI_Bcast(matrix2, AColSize * BColSize, MPI_DOUBLE, m_id, MPI_COMM_WORLD);
    while (true) {
        MPI_Recv(buffer, AColSize, MPI_DOUBLE, m_id, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
        if (status.MPI_TAG != end_tag) {
            for (int i = 0; i < BColSize; i++) {
                ans_buffer[i] = 0;
                for (int j = 0; j < AColSize; j++) {
                    ans_buffer[i] += buffer[j] * matrix2[j][i];
                }
            }
            MPI_Send(ans_buffer, BColSize, MPI_DOUBLE, m_id, status.MPI_TAG, MPI_COMM_WORLD);
        } else {
            break;
        }
    }
}

void writeMatrixToFile(const std::string &filename,
                       std::vector<std::vector<int>> &matrix) {
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

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numProcess);
    int myid;
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    double start_time = MPI_Wtime();
    if (myid == m_id) {
        master();
    } else {
        slave();
    }
    if (myid == m_id) {
        double end_time = MPI_Wtime();
        double time = end_time - start_time;
        std::cout << "Multiple Thread Total Time : " << time * 60 << " ms" << std::endl;
        writeMatrixToFile(outputFile, ans);
    }
    MPI_Finalize();
    return 0;
}
