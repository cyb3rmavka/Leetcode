/*Given an array of integers arr, return true if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i + 1 < j
with (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])

*/
class Solution {
public:
    bool canThreePartsEqualSum(std::vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
        }

        if (sum % 3 != 0) {
            return false;
        }

        int targetSum = sum / 3;
        int runningSum = 0;
        int partitionCount = 0;

        for (int i = 0; i < arr.size(); ++i) {
            runningSum += arr[i];

            if (runningSum == targetSum) {
                runningSum = 0;
                partitionCount++;
                
                // Early termination if three partition points found
                if (partitionCount >= 2 && i != arr.size() - 1) {
                    return true;
                }
            }

            // Break the loop if running sum exceeds the target sum
            if (partitionCount < 2 && runningSum > targetSum) {
                break;
            }
        }

        return false;
    }
};
