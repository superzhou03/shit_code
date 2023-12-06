// Author: superzhou03
// Created time: 2023-12-06
/*
  最大子段和-DP方法
  Description
  给出N个数字, 计算出最大的子段和。
 
  Input
  第一行给出一个数字 T(1<=T<=20) 代表接下来的组数.
  接下来每 T 行,开始给出一个正整数 N(1<=N<=100000), 接着跟着N个整数.。
  数据保证中间结果和最后结果都在int范围内。
  Output
  输出最大的子段和
 
  Sample Input
  2
  5 6 -1 5 4 -7
  7 0 6 -1 1 -6 7 -5
  Sample Output
  14
  7
*/
#include <iostream>
#include <vector>
#include <climits>

int maxSubArraySum(const std::vector<int> &nums)
{
    int n = nums.size();
    int maxSum = INT_MIN;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N;
        std::cin >> N;
        std::vector<int> nums(N);
        for (int i = 0; i < N; i++)
            std::cin >> nums[i];        
        int maxSum = maxSubArraySum(nums);
        std::cout << maxSum << std::endl;
    }
    return 0;
}
