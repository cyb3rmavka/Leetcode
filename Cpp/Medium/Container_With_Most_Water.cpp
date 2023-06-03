/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.
*/

class Solution {
public:
int maxArea(std::vector<int>& height) {
    int max_square = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        int h = std::min(height[left], height[right]);
        int w = right - left;
        int square = h * w;
        max_square = std::max(max_square, square);

        if (height[left] < height[right]) {
            int curr = height[left];
            while (left < right && height[left] <= curr) {
                left++;
            }
        } else {
            int curr = height[right];
            while (left < right && height[right] <= curr) {
                right--;
            }
        }
    }

    return max_square;
}
};
