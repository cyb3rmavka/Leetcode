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
