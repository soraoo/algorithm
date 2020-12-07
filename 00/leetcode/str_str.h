//实现 strStr() 函数。
//
// 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
//果不存在，则返回 -1。
//
// 示例 1:
//
// 输入: haystack = "hello", needle = "ll"
//输出: 2
//
//
// 示例 2:
//
// 输入: haystack = "aaaaa", needle = "bba"
//输出: -1
//
//
// 说明:
//
// 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
// 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

#ifndef ALGORITHM_STR_STR_H
#define ALGORITHM_STR_STR_H

#include <string>
#include <iostream>
using namespace std;

int strStr(const string& haystack, const string& needle)
{
    if(needle.empty()) return 0;

    int p = 0;
    int q = 0;
    for(; p < haystack.size() && q < needle.size(); ++p)
    {
        if(haystack[p] == needle[q])
        {
            ++q;
        }
        else
        {
            p -= q;
            q = 0;
        }
    }

    return q < needle.size() ? -1 : p - q;
}

/**
 * 用位运算掩码
 * @param haystack
 * @param needle
 * @return
 */
int strStr2(const string& haystack, const string& needle)
{
    return 0;
}

void test_strStr()
{
    cout << "[hello, ll]->2:   " << strStr("hello", "ll") << endl;
    cout << "[aaaaa, bba]->-1:   " << strStr("aaa", "bba") << endl;
    cout << "[wllllcf, llc]->3:   " << strStr("wllllcf", "llc") << endl;
}

#endif //ALGORITHM_STR_STR_H
