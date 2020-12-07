//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
// 示例:
//
// 输入: [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

#ifndef ALGORITHM_MAX_SUB_ARRAY_H
#define ALGORITHM_MAX_SUB_ARRAY_H

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums)
{
    int pre = 0;
    int sum = nums[0];
    for(const int& num : nums)
    {
        pre = max(pre + num, num);
        sum = max(pre, sum);
    }

    return sum;
}

void test_maxSubArray()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "[-2,1,-3,4,-1,2,1,-5,4] -> 6:     " << maxSubArray(nums) << endl;
}

#endif //ALGORITHM_MAX_SUB_ARRAY_H
