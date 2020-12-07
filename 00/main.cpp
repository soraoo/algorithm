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

//#include "leetcode/roman_to_int.h"
//#include "leetcode/longest_common_prefix.h"
//#include "leetcode/is_valid.h"
//#include "leetcode/merge_two_lists.h"
//#include "leetcode/remove_duplicates.h"
//#include "leetcode/remove_element.h"
//#include "leetcode/str_str.h"
//#include "leetcode/search_insert.h"
//#include "leetcode/count_and_say.h"
#include "leetcode/max_sub_array.h"

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

    //cout << numberToWords(1000000000) << endl;
//    bool result = isPalindrome(1000000000);
//    cout << result << endl;

    //罗马数字转int
    //test_romanToInt();

    //最长公共前缀
//    test_longestCommonPrefix();

    //有效的括号
//    test_isValid();

    //合并两个有序链表
//    test_mergeTwoLists();

    //删除排序数组中的重复项
//    test_removeDuplicates();

    //移除元素
//    test_removeElement();

    //实现strStr()
//    test_strStr();

    //搜索插入位置
//    test_searchInsert();

    //外观数列
    //test_countAndStudy();

    //最大子序和
    test_maxSubArray();

    return 0;
}