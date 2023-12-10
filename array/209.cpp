// Author: superzhou03
// Created time: 2023-12-10
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        if(size == 0)   return 0;
        int start = 0, end = 0;
        int current_lenth = 0, lenth = INT_MAX, sum = 0;
        for (end = 0; end < size; end++){
            sum += nums[end];
            while(sum >= target){
                current_lenth = end - start + 1;
                lenth = min(lenth, current_lenth);
                sum -= nums[start++];
            }
        }
        // 这里如果所有数组元素和<target,就输出0
        return lenth == INT_MAX ? 0 : lenth;       
    }
}
