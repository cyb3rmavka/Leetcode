/*
Given an integer array nums of unique elements, return all possible 
subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> subset;
        for (int mask = 0; mask < (1 << nums.size()); ++mask){
            bool first = true;
            subset.push_back({});
            for (int i = 0; i < nums.size(); ++i){
                if (mask & (1 << i)){
                    subset[mask].push_back(nums[i]);
                }
            }
        }
        return subset;
    }
};
