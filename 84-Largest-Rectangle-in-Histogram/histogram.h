//
// Created by Marvin on 2017/7/19.
//

#ifndef INC_84_LARGEST_RECTANGLE_IN_HISTOGRAM_HISTOGRAM_H
#define INC_84_LARGEST_RECTANGLE_IN_HISTOGRAM_HISTOGRAM_H

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

/*
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the histogram.
 */

class Solution {
public:
    /*
     * 这个解法的主要思想就是用一个数组记录从小到大递增的数，只要遇到了开始下降的数就将
     * 比他大的数弹出并且计算当前的最大面积，为了让所有数都能计算到，需要在一开始的数组尾部加入0
     * 这样等扫描到最后一个数的时候，前面的数都会计算
     */
    int largestRectangleAreaT(std::vector<int>& heights) {
        //插入0
        heights.push_back(0);
        int len = heights.size();
        int area = 0;
        std::vector<int> index;
        for(int i = 0; i < len; i++) {
            //将比当前数大的数弹出
            while(!index.empty() && heights[index.back()] >= heights[i]) {
                int height = heights[index.back()];
                index.pop_back();
                //如果之前只有一个数在index里面，此时已经弹出，不能使用index.back()了
                //这是计算边长，index为空说明刚刚弹出栈的高度是第一个压进去的，也就是
                //可以通过i来定位边长，若是非空则要通过下一个栈里的元素来获得边长
                int bias = index.empty() ? -1 : index.back();
                area = std::max(area, height * (i - 1 - bias));
            }
            index.push_back(i);
        }
        return area;
    }

    /*
     * 这种解法比较直观，假设我们从左往右扫描原数列，每到一个点，当前点能够获得的最大面积是通过
     * 观察左边和右边的边界来决定的，所以我们可以先计算每个点的左边界和右边界，在计算的时候不是
     * 通过依次判断每个点来获知的，而是利用已经得到的信息可以实现直接获取。
     */
    int largestRectangleArea(std::vector<int>& heights) {
        int len = heights.size();
        int area = 0;
        //每个点的左边界，代表离该点左边最近的小于自己的数的索引
        //lindex[0]初始化为-1
        std::vector<int> lindex(len, -1);
        //每个点的右边界，代表离该点右边最近的小于自己的数的索引
        //rindex[len-1]初始化为len
        std::vector<int> rindex(len, len);
        for(int i = 1; i < len; i++) {
            int p = i - 1;
            while(p >= 0 && heights[i] <= heights[p])
                //利用已知的信息
                p = lindex[p];
            lindex[i] = p;
        }
        for(int i = len - 2; i >= 0; i--) {
            int p = i + 1;
            while(p < len && heights[i] <= heights[p])
                //利用已知的信息
                p = rindex[p];
            rindex[i] = p;
        }
        for(int i = 0; i < len; i++)
            area = std::max(area, heights[i] * (rindex[i] - lindex[i] - 1));
        return area;
    }
};
#endif //INC_84_LARGEST_RECTANGLE_IN_HISTOGRAM_HISTOGRAM_H
