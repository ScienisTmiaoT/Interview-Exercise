//
// Created by Marvin on 2017/7/21.
//

#ifndef INC_90_SUBSETS_II_SUBSET_H
#define INC_90_SUBSETS_II_SUBSET_H

#include <iostream>
#include <vector>
#include <algorithm>
/*
 * Given a collection of integers that might contain duplicates, nums, return all possible subsets.
 * Note: The solution set must not contain duplicate subsets.
 * For example,
 * If nums = [1,2,2], a solution is:
 * [[2],[1],[1,2,2],[2,2],[1,2],[]]
 */

/*
 * 这道题的解题思路和（78. Subsets）是一样的，只不过增加了重复元素，解决思路就是先排序，然后依次从空集开始
 * 依次往已有的subset里面添加新的元素，遇到重复的元素我们可以发现一个规律，每次重复元素添加进去之后，
 * 新增加的subset都是在上一次新增加的subset的基础上添加进去的，所以我们可以用一个index来记录上一次
 * 新增加的subset的元素的位置，等到下一次添加的时候只需要从这个位置开始，如果不是重复元素则只需要
 * 从头开始就好了。
 *
 * 还有一种方法是将重复元素看作一类，每次都是在原来的subset里面添加不同数量的重复元素，这就告诉我们
 * 不需要去访问重复元素，先把重复元素的个数记录好即可
 */
class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> item;
        std::vector<std::vector<int>> res;
        res.push_back(item);
        int len = nums.size();
        int index = 0;
        for(int i = 0; i < len; i++) {
            int size = res.size();
            for(int j = index; j < size; j++) {
                item = res[j];
                item.push_back(nums[i]);
                res.push_back(item);
            }
            if(i < len - 1 && nums[i] == nums[i + 1])
                index = size;
            else
                index = 0;
        }
        return res;
    }
};
#endif //INC_90_SUBSETS_II_SUBSET_H
