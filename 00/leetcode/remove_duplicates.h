//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//
//
//
// 示例 1:
//
// 给定数组 nums = [1,1,2],
//
//函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
//
//你不需要考虑数组中超出新长度后面的元素。
//
// 示例 2:
//
// 给定 nums = [0,0,1,1,1,2,2,3,3,4],
//
//函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//
//你不需要考虑数组中超出新长度后面的元素。

#ifndef ALGORITHM_REMOVE_DUPLICATES_H
#define ALGORITHM_REMOVE_DUPLICATES_H

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int size = nums.size();
    if(size < 2) return size;

    int p = 0;
    int q = 1;
    while(q < size)
    {
        if(nums[p] < nums[q])
        {
            ++p;
            nums[p] = nums[q];
        }
        ++q;
    }
    return p + 1;
}

/**
 * 优雅的双指针
 * @param nums
 * @return
 */
int removeDuplicates2(vector<int>& nums)
{
    int size = nums.size();
    if(size < 2) return size;

    int i = 0;
    for(int j = 1; j < nums.size(); ++j)
    {
        if(nums[i] != nums[j])
        {
            ++i;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

void test_removeDuplicates()
{
    vector<int> nums{1, 1, 2};
    cout << "[1,1,2]->2, [1, 2]:   " << removeDuplicates(nums) << ", [";
    for(auto num : nums)
    {
        cout << num << ", ";
    }
    cout << "]" << endl;

    vector<int> num2s{0,0,1,1,1,2,2,3,3,4};
    cout << "[0,0,1,1,1,2,2,3,3,4]->5, [0, 1, 2, 3, 4]:  " << removeDuplicates(num2s) << ", [";
    for(auto num : num2s)
    {
        cout << num << ", ";
    }
    cout << "]" << endl;

    vector<int> num3s{1, 2};
    cout << "[0,0,1,1,1,2,2,3,3,4]->5, [0, 1, 2, 3, 4]:  " << removeDuplicates(num3s) << ", [";
    for(auto num : num3s)
    {
        cout << num << ", ";
    }
    cout << "]" << endl;
}

#endif //ALGORITHM_REMOVE_DUPLICATES_H
