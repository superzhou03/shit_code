// Author: superzhou03
// Created time: 2023-12-10
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int left = 0, right = nums.size() - 1;
//         vector<int> result;
//         while(left != right){
//             if(std::pow(nums[left], 2) <= std::pow(nums[right], 2))
//                 result.insert(result.begin(), std::pow(nums[right--], 2));
//             else
//                 result.insert(result.begin(), std::pow(nums[left++], 2));
//         }
//         result.insert(result.begin(), std::pow(nums[right], 2));
//         return result;
//     }
// };
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
           pos--;
        }
        return ans;
    }
};
