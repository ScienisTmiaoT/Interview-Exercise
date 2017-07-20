#include "rectangle.h"

int main() {
    Solution *s = new Solution();
    std::vector<std::vector<char>> nums{{'1','0','1','0','0'},
                                       {'1','0','1','1','1'},
                                       {'1','1','1','1','1'},
                                       {'1','0','0','1','0'}};
    std::vector<std::vector<char>> nums1{{'1','0'},{'1','0'}};
    std::cout << s->maximalRectangleTTT(nums1) << std::endl;
    return 0;
}