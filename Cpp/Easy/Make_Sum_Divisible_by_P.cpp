/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

*/



class Solution {
public:
    int minSubarray(std::vector<int> &nums, int p) {
        int sum = 0;
        for (int num: nums) {
            sum = (sum + num) % p;
        }

        if (sum == 0) {
            return 0;
        }

        std::unordered_map<int, int> remainderMap;
        remainderMap[0] = -1;

        int currSum = 0;
        int minLen = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            currSum = (currSum + nums[i]) % p;

            int targetRemainder =
                    (currSum - sum + p) % p;  // Calculate the remainder needed for a subarray sum to be equal to 'sum'

            if (remainderMap.count(targetRemainder) > 0) {
                int subarrayLen = i - remainderMap[targetRemainder];
                minLen = std::min(minLen, subarrayLen);
            }

            remainderMap[currSum] = i;  // Store the cumulative sum and its index
        }

        return (minLen < nums.size()) ? minLen : -1;  // Return -1 if no valid subarray is found
    }
};


