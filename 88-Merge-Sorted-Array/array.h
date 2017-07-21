//
// Created by Marvin on 2017/7/21.
//

#ifndef INC_88_MERGE_SORTED_ARRAY_ARRAY_H
#define INC_88_MERGE_SORTED_ARRAY_ARRAY_H

#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n)
 * to hold additional elements from nums2. The number of elements initialized in
 * nums1 and nums2 are m and n respectively.
 */

class Solution {
public:
    /*
     * 这种解法就是先将nums1中的数组复制到一个数组中，然后再依次比较填入到nums1中
     */
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> temp;
        for(int i = 0; i < m; i++)
            temp.push_back(nums1[i]);
        int i = 0, j = 0, index = 0;
        while(i < m && j < n) {
            if(temp[i] < nums2[j]) nums1[index++] = temp[i++];
            else nums1[index++] = nums2[j++];
        }
        for(int p = i; p < m; p++)
            nums1[index++] = temp[p];
        for(int k = j; k < n; k++)
            nums1[index++] = nums2[k];
    }

    /*
     * 这种解法是从两个数组的尾部开始比较，然后依次从nums1最末端的位置开始填入，这种方法只需要
     * 扫描一遍，而且没有利用额外的空间，利用的是nums1本身就是有序的，如果这样填入，那么nums1
     * 的前面一部分甚至不需要移动位置
     */
    void mergeT(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while(j >= 0)
            nums1[index--] = i >= 0 && nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
    }
};
#endif //INC_88_MERGE_SORTED_ARRAY_ARRAY_H
