//
// Created by Administrator on 2020/11/27.
//

#ifndef ALGORITHM_LONGEST_COMMON_PREFIX_H
#define ALGORITHM_LONGEST_COMMON_PREFIX_H

//编写一个函数来查找字符串数组中的最长公共前缀。
//
// 如果不存在公共前缀，返回空字符串 ""。
//
// 示例 1:
//
// 输入: ["flower","flow","flight"]
//输出: "fl"
//
//
// 示例 2:
//
// 输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
//
//
// 说明:
//
// 所有输入只包含小写字母 a-z 。
// Related Topics 字符串
// 👍 1359 👎 0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

///====================扫描法求解===================================
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) {
        return "";
    }

    int length = strs[0].size();
    int count = strs.size();
    for(int i = 0; i < length; ++i) {
        char c = strs[0][i];
        for(int j = 1; j < count; ++j) {
            if(i == strs[j].size() || c != strs[j][i]) {
                return strs[0].substr(0, i);
            }
        }
    }
    return strs[0];
}

///====================分治法求解===================================

string compare(const string& lhs, const string& rhs) {
    int length = min(lhs.size(), rhs.size());
    for(int i = 0; i < length; ++i) {
        if(lhs[i] != rhs[i]) {
            return lhs.substr(0, i);
        }
    }
    return lhs.substr(0, length);
}

string longestCommonPrefix_2(vector<string>& strs, int start, int end) {
    if(end == start) {
        return strs[start];
    }

    int mid = (start + end) / 2; //start + (end - start) >> 1
    const string& lhs = longestCommonPrefix_2(strs, start, mid);
    const string& rhs = longestCommonPrefix_2(strs, mid + 1, end);
    return compare(lhs, rhs);
}

string longestCommonPrefix_2(vector<string>& strs) {
    if(strs.empty()) {
        return "";
    }

    return longestCommonPrefix_2(strs, 0, strs.size() - 1);
}

void test_longestCommonPrefix() {
    vector<string> v = {"flower", "flow", "flight"};
    vector<string> v1 = {"dog","racecar","car"};

    cout << "normal method:" << endl;
    cout << R"(["flower", "flow", "flight"] -> fl: )" << longestCommonPrefix(v) << endl;
    cout << R"(["dog","racecar","car"] -> "": )" << longestCommonPrefix(v1) << endl;

    cout << "Divide and Conquer method:" << endl;
    cout << R"(["flower", "flow", "flight"] -> fl: )" << longestCommonPrefix_2(v) << endl;
    cout << R"(["dog","racecar","car"] -> "": )" << longestCommonPrefix_2(v1) << endl;

}

#endif //ALGORITHM_LONGEST_COMMON_PREFIX_H
