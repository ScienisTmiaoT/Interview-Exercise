#include "array.h"

int main() {
    Solution *s = new Solution();
    std::vector<int> nums1(8, 0);
    nums1[0] = 1;
    nums1[1] = 4;
    nums1[2] = 6;
    nums1[3] = 8;
    std::vector<int> nums2(4, 0);
    nums2[0] = 2;
    nums2[1] = 3;
    nums2[2] = 5;
    nums2[3] = 7;
    s->mergeT(nums1, 4, nums2, 4);
    for(int i = 0; i < nums1.size(); i++)
        std::cout << nums1[i] << " ";
    std::cout << std::endl;
    return 0;
}