//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
// 你可以假设数组中无重复元素。
//
// 示例 1:
//
// 输入: [1,3,5,6], 5
//输出: 2
//
//
// 示例 2:
//
// 输入: [1,3,5,6], 2
//输出: 1
//
//
// 示例 3:
//
// 输入: [1,3,5,6], 7
//输出: 4
//
//
// 示例 4:
//
// 输入: [1,3,5,6], 0
//输出: 0

#ifndef ALGORITHM_SEARCH_INSERT_H
#define ALGORITHM_SEARCH_INSERT_H

#include <vector>
#include <iostream>
using namespace std;

int searchInsert(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
        {
            return mid;
        }
        else if(nums[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

void test_searchInsert()
{
    vector<int> num1s{1,3,5,6};
    cout << "[1,3,5,6], 5 -> 2:   " << searchInsert(num1s, 5) << endl;

    vector<int> num2s{1,3,5,6};
    cout << "[1,3,5,6], 2 -> 1:   " << searchInsert(num2s, 2) << endl;

    vector<int> num3s{1,3,5,6};
    cout << "[1,3,5,6], 7 -> 4:   " << searchInsert(num3s, 7) << endl;

    vector<int> num4s{1,3,5,6};
    cout << "[1,3,5,6], 0 -> 0:   " << searchInsert(num2s, 0) << endl;

    vector<int> num5s{1};
    cout << "[1], 1 -> 0:   " << searchInsert(num5s, 1) << endl;

    vector<int> num6s{1};
    cout << "[1], 10 -> 1:   " << searchInsert(num6s, 10) << endl;
}

#endif //ALGORITHM_SEARCH_INSERT_H
