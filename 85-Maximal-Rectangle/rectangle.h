//
// Created by Marvin on 2017/7/20.
//

#ifndef INC_85_MAXIMAL_RECTANGLE_RECTANGLE_H
#define INC_85_MAXIMAL_RECTANGLE_RECTANGLE_H

#include <iostream>
#include <vector>
#include <algorithm>

/*
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * For example, given the following matrix:
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * Return 6.
 */


class Solution {
public:
    /*
     * 这种方法是非常直接的，就是每当遇到一个为1的点，就不断向左向下判断是否存在矩形，先找到
     * 可能的最长的边长，然后跳到下一行，以之前的边长为界限去找下一条边长，这个边长有可能变小，
     * 因此需要更新，这样不断按照行的顺序寻找，每到一行都要更新当前最大的面积。
     * 这种算法的时间复杂度还是比较高的，不过还是通过了在线评判
     */
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int column = matrix[0].size();
        int area = 0;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(matrix[i][j] == '1') {
                    int width = 0;
                    for(int k = j; k < column; k++) {
                        if(matrix[i][k] == '1') width++;
                        else break;
                    }
                    area = std::max(area, width);
                    for(int p = i + 1; p < row; p++) {
                        int q = j;
                        if(matrix[p][q] == '0') break;
                        int width2 = 0;
                        for(; q < j + width; q++) {
                            if(matrix[p][q] == '1') width2++;
                            else break;
                        }
                        width = width2;
                        area = std::max(area, (p - i + 1) * width);
                    }
                }
            }
        }
        return area;
    }

    /*
     * 这是一种非常机智的解法，主要思想就是按照行扫描矩阵，在每一行的时候，记录下每个点的左边界和
     * 右边界，也就是以1为限制的边界，这两个边界的更新依靠的是上一行获得的信息，以下面的矩阵为例：
     * 1 0 1 0 0
     * 1 0 1 1 1
     * 1 1 1 1 1
     * 1 0 0 1 0
     * Row 0: h: 1 0 1 0 0 l: 0 0 2 0 0 r: 1 5 3 5 5
     * Row 1: h: 2 0 2 1 1 l: 0 0 2 2 2 r: 1 5 3 5 5
     * Row 2: h: 3 1 3 2 2 l: 0 0 2 2 2 r: 1 5 3 5 5
     * Row 3: h: 4 0 0 3 0 l: 0 0 0 3 0 r: 1 5 5 4 5
     *
     * 以上是left，right以及height矩阵所保存的值，height保存的是当前点的高度，
     * 因此(right - left)*height就是当前点的最大面积
     */
    int maximalRectangleT(std::vector<std::vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int column = matrix[0].size();
        int area = 0;
        //初始化为0
        std::vector<int> left(column, 0);
        //初始化为column
        std::vector<int> right(column, column);
        std::vector<int> height(column, 0);
        for(int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            //当前的边界记录值
            int curleft = 0;
            //从左往右扫描，尽可能地让left变大
            for(int j = 0; j < column; j++) {
                if(matrix[i][j] == '1') left[j] = std::max(left[j], curleft);
                else {
                    left[j] = 0;
                    curleft = j + 1;
                }
            }
            //当前的边界记录值
            int curright = column;
            //从右往左扫描，尽可能地让right变小
            for(int j = column - 1; j >= 0; j--){
                if(matrix[i][j] == '1') right[j] = std::min(right[j], curright);
                else {
                    right[j] = column;
                    curright = j;
                }
            }
            for(int j = 0; j < column; j++)
                area = std::max(area, (right[j] - left[j]) * height[j]);
        }
        return area;
    }

    //方法二的优化版
    int maximalRectangleTT(std::vector<std::vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int column = matrix[0].size();
        int area = 0;
        std::vector<int> left(column, 0);
        std::vector<int> right(column, column);
        std::vector<int> height(column, 0);
        for(int i = 0; i < row; i++) {
            int curleft = 0;
            int curright = column;
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = std::max(left[j], curleft);
                }
                else {
                    height[j] = 0;
                    left[j] = 0;
                    curleft = j + 1;
                }
                if(matrix[i][column - 1 - j] == '1') {
                    right[column - 1 - j] = std::min(right[column - 1 - j], curright);
                }
                else {
                    right[column - 1 - j] = column;
                    curright = column - 1 - j;
                }
            }
            for(int j = 0; j < column; j++)
                area = std::max(area, (right[j] - left[j]) * height[j]);
        }
        return area;
    }

    /*
     * 方法三使用的方法和（84. Largest Rectangle in Histogram）相似，也是利用栈将比当前值
     * 更小的高度压入栈中，否则就弹出栈进行计算
     */
    int maximalRectangleTTT(std::vector<std::vector<char>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int column = matrix[0].size();
        int area = 0;
        std::vector<int> height(column + 1, 0);
        std::vector<int> index;
        for(int i = 0; i < row; i++) {
            //每次循环前清除栈，非常重要
            index.clear();
            for(int j = 0; j <= column; j++) {
                if(j < column) {
                    if(matrix[i][j] == '1') height[j]++;
                    else height[j] = 0;
                }
                while(!index.empty() && height[index.back()] > height[j]) {
                    int pos = index.back();
                    index.pop_back();
                    //这是计算边长，index为空说明刚刚弹出栈的高度是第一个压进去的，也就是
                    //可以通过j来定位边长，若是非空则要通过下一个栈里的元素来获得边长
                    int bias = index.empty() ? j : (j - index.back() - 1);
                    area = std::max(area, height[pos] * bias);
                }
                index.push_back(j);
            }
        }
        return area;
    }
};
#endif //INC_85_MAXIMAL_RECTANGLE_RECTANGLE_H
