class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> mergedArray;
        int i = 0; 
        int j = 0; 

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            } else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while (i < nums1.size()) {
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            mergedArray.push_back(nums2[j]);
            j++;
        }
        if((mergedArray.size()-1)%2==0){
            return mergedArray[mergedArray.size()/2];
        } return double(mergedArray[(mergedArray.size()-1)/2 ] + mergedArray[(mergedArray.size()-1)/2 + 1])/2;
    }
};
