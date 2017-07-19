#include "histogram.h"

int main() {
    Solution *s = new Solution();
    std::vector<int> nums{2,1,5,6,2,3};
    std::cout << s->largestRectangleArea(nums) << std::endl;
    return 0;
}