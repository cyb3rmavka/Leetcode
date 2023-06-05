/* 
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.
*/

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] % 2 == 0) {
                left++;
            } else {
                std::swap(nums[left], nums[right]);
                right--;
            }
        }

        return nums;
    }
};
