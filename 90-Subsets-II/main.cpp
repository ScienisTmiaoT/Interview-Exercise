#include "subset.h"

int main() {
    Solution *s = new Solution();
    std::vector<int> nums{1,2,2,3,3};
    std::vector<std::vector<int>> res = s->subsetsWithDup(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[0].size(); j++) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}