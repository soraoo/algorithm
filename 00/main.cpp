//
// master公式
// 递归时间复杂度如果满足:T(n) = a*T(n/b) + O(pow(n, d)) 可化简求出如下时间复杂度:
// 1): log(b, a) > d -> T(n) = O(pow(n, log(b, a))
// 2): log(b, a) = d -> T(n) = O(pow(n, d)*log(n))
// 3): log(b, a) < d -> T(n) = O(pow(n, d))
// 例如：如果一个算法满足T(n) = 2*T(n/2) + O(1)
// 则有a = 2， b = 2, d = 0.
// 因为log(b, a) = 1 > d
// 所以T(n) = O(pow(n, log(b, a)) = O(pow(n, 1)) = O(n)
//
//
//
// Created by Administrator on 2020/11/25.
//

#include "sort.h"
#include "leetcode.h"

#include <iostream>
using namespace std;

int main()
{
//    int arr[] = {3, 6, 1, 5, 7, 2, 9};
//    bubble_sort(arr, sizeof(arr) / sizeof(int));
//    for(int a : arr)
//    {
//        cout << a << endl;
//    }

    numberToWords(123);

    return 0;
}