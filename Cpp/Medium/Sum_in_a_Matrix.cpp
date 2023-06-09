/*You are given a 0-indexed 2D integer array nums. Initially, your score is 0. Perform the following operations until the matrix becomes empty:

From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
Identify the highest number amongst all those removed in step 1. Add that number to your score.
Return the final score.You are given a 0-indexed 2D integer array nums. Initially, your score is 0. Perform the following operations until the matrix becomes empty:

From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
Identify the highest number amongst all those removed in step 1. Add that number to your score.
Return the final score.*/


class Solution {
public:
    int matrixSum(std::vector<std::vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL) ;
        int rows = nums.size();
        int cols = nums[0].size();

        // Sort each row in descending order
        for (auto& row : nums) {
            std::sort(row.rbegin(), row.rend());
        }

        int sum = 0;
        int max = 0;
        for(int i = 0; i<cols;i++){
            for(int j = 0; j<rows;j++){
                if(max<nums[j][i]){
                    max = nums[j][i];
                }
            }

            sum+= max;
            max = 0;    
        }
        return sum;
    }
};
