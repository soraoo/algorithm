// 排序算法
// Created by Administrator on 2020/11/25.
//

#ifndef ALGORITHM_SORT_H
#define ALGORITHM_SORT_H

/**
 * 冒泡排序
 * @param arr 数组
 * @param length 长度
 */
void bubble_sort(int* arr, int length)
{
    if(arr == nullptr || length < 2)
    {
        return;
    }

    //经典写法
//    for(int i = 0; i < length - 1; ++i)
//    {
//        for(int j = 0; j < length - i - 1; ++j)
//        {
//            if(arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }

    //炫酷写法[仅仅限于正整数比较
    for(int end = length - 1; end > 0; --end)
    {
        for(int i = 0; i < end; ++i)
        {
            if(arr[i] > arr[i + 1])
            {
                arr[i] ^= arr[i + 1];
                arr[i + 1] ^= arr[i];
                arr[i] ^= arr[i + 1];
            }
        }
    }
}

#endif //ALGORITHM_SORT_H
