// Author: superzhou03
// Created time: 2023-12-05
class Solution{
    public:
        int removeElement(vector<int>& nums, int val){
           int fast = 0 ,slow = 0, lenth = nums.size();
           for (int fast = 0; fast < lenth; fast++)
                if(nums[fast] != val)
                    nums[slow++] = nums[fast];
                return slow;
        }
}
