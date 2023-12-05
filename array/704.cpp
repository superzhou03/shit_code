// Author: superzhou03
// Created time: 2023-12-05
class Solution {
public:
    int search(vector<int>& nums,int target){
        int left = 0, right = nums.size() - 1, middle = 0;
        while(left <= right){
            middle = (left + right) / 2;
            if(nums[middle] > target)
                right = middle - 1;
            else if(nums[middle] < target)
                left = middle + 1;
            else 
                return middle;
        }
        return -1;
    }
}
