//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//
//
// 示例 1:
//
// 给定 nums = [3,2,2,3], val = 3,
//
//函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
//
//你不需要考虑数组中超出新长度后面的元素。
//
//
// 示例 2:
//
// 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
//
//函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
//
//注意这五个元素可为任意顺序。
//
//你不需要考虑数组中超出新长度后面的元素。

#ifndef ALGORITHM_REMOVE_ELEMENT_H
#define ALGORITHM_REMOVE_ELEMENT_H

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    if(nums.empty()) return 0;

    int p = 0;
    for(int q = 0; q < nums.size(); ++q)
    {
        if(nums[p] != val)
        {
            ++p;
        }
        else if(nums[q] != val)
        {
            int tmp = nums[p];
            nums[p] = nums[q];
            nums[q] = tmp;
            ++p;
        }
    }
    return p;
}

/**
 * 优雅的解法
 * @param nums
 * @param val
 * @return
 */
int removeElement2(vector<int>& nums, int val)
{
    int p = 0;
    for(int q = 0; q < nums.size(); ++q)
    {
        if(nums[q] != val)
        {
            nums[p] = nums[q];
            ++p;
        }
    }
    return p;
}

/**
 * 效率更高的解法（改变了元素顺序）
 * @param nums
 * @param val
 * @return
 */
int removeElement3(vector<int>& nums, int val)
{
    int n = nums.size();
    int i = 0;
    while(i < n)
    {
        if(nums[i] == val)
        {
            nums[i] = nums[n - 1];
        }
        else
        {
            ++i;
        }
    }
    return n;
}

void test_removeElement()
{
    vector<int> nums{3,2,2,3};
    cout << "[3,2,2,3], 3->2, [2, 2]:   " << removeElement(nums, 3) << ", [";
    for(auto num : nums)
    {
        cout << num << ", ";
    }
    cout << "]" << endl;

    vector<int> num2s{0,1,2,2,3,0,4,2};
    cout << "[0,1,2,2,3,0,4,2], 2->5, [0, 1, 3, 0, 4]:  " << removeElement(num2s, 2) << ", [";
    for(auto num : num2s)
    {
        cout << num << ", ";
    }
    cout << "]" << endl;

    vector<int> num3s{2};
    cout << "[2], 3->1, [2]:  " << removeElement(num3s, 3) << ", [";
    for(auto num : num3s)
    {
        cout << num << ", ";
    }
    cout << "]" << endl;
}

#endif //ALGORITHM_REMOVE_ELEMENT_H
