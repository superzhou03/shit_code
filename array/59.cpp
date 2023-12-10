// Author: superzhou03
// Created time: 2023-12-10
// 螺旋矩阵关键是要留一个元素给下一组循环处理
//  1  2  3  4
//  5  6  7  8
//  9 10 11 12
// 13 14 15 16
// 如上，处理的顺序应该是
// 1,2,3一组; 4,8,12一组; 16,14,15一组; 13,9,5一组
class Solution {
public:
    vector <vector<int>> generateMatrix(int n) {
        vector <vector<int>> matrix(n, vector<int>(n, 0));
        // start_x,start_y是每次循环赋值开始的位置
        // 正方形start_x,start_y每次循环过后始终相等
        // 方便可以只用一个start表示
        // 分别用两个表示是为了便于理解
        int start_x = 0, start_y = 0;
        // 表示每次循环赋值时的位置
        int x = 0, y = 0;
        // 偏移量,每赋值一次就++
        int offset = 1;
        int cnt=1,loop = n / 2;
        while (loop--) {
            for (y = start_y; y < n - offset; y++)
                matrix[start_x][y] = cnt++;

            for (x = start_x; x < n - offset; x++)
                matrix[x][y] = cnt++;

            for (; y > start_y; y--)
                matrix[x][y] = cnt++;

            for (; x > start_x; x--)
                matrix[x][y] = cnt++;

            start_x++;
            start_y++;
            offset++;
        }
        if (n % 2)
            matrix[n / 2][n / 2] = cnt;
        return matrix;
    }
};
