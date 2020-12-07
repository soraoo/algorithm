//罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
//
// 字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//
// 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做 XXVII, 即为 XX + V + I
//I 。
//
// 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5
// 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//
// I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
// X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
// C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
//
//
// 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
//
//
//
// 示例 1:
//
// 输入: "III"
//输出: 3
//
// 示例 2:
//
// 输入: "IV"
//输出: 4
//
// 示例 3:
//
// 输入: "IX"
//输出: 9
//
// 示例 4:
//
// 输入: "LVIII"
//输出: 58
//解释: L = 50, V= 5, III = 3.
//
//
// 示例 5:
//
// 输入: "MCMXCIV"
//输出: 1994
//解释: M = 1000, CM = 900, XC = 90, IV = 4.
//
//
//
// 提示：
//
//
// 题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
// IC 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
// 关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics 。
//
// Related Topics 数学 字符串

#ifndef ALGORITHM_ROMAN_TO_INT_H
#define ALGORITHM_ROMAN_TO_INT_H

#include <iostream>
#include <string>
#include <map>
using namespace std;

/**
 * 这个比构造一个map快
 * @param c
 * @return
 */
int get_value(const char& c) {
    switch(c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(const string& s) {
//    int result = 0;
//    int p = 0;
//    map<char, int> r2iMap;
//    r2iMap['I'] = 1;
//    r2iMap['V'] = 5;
//    r2iMap['X'] = 10;
//    r2iMap['L'] = 50;
//    r2iMap['C'] = 100;
//    r2iMap['D'] = 500;
//    r2iMap['M'] = 1000;
//
//    while(p < s.size()) {
//        char c = s[p];
//        if(p + 1 < s.size()) {
//            bool spe1 = c == 'I' && (s[p + 1] == 'V' || s[p + 1] == 'X');
//            bool spe2 = c == 'X' && (s[p + 1] == 'L' || s[p + 1] == 'C');
//            bool spe3 = c == 'C' && (s[p + 1] == 'D' || s[p + 1] == 'M');
//            if(spe1 || spe2 || spe3) {
//                result += r2iMap[s[p + 1]] - r2iMap[c];
//                p+=2;
//            } else {
//                result += r2iMap[c];
//                ++p;
//            }
//        } else {
//            result += r2iMap[c];
//            ++p;
//        }
//    }
//    return result;

    //有个更牛逼的思路，罗马计数法 本质是：把一个小值放在大值的左边，就是做减法，否则为加法
    //另外 用switch比map快很多
    int cur = get_value(s[0]);
    int result = 0;
    for(int i = 1; i < s.size(); ++i) {
        int next = get_value(s[i]);
        if(cur >= next) result += cur;
        else result -= cur;
        cur = next;
    }
    result += cur;
    return result;
}

void test_romanToInt() {
    cout << "III -> 3: " << romanToInt("III") <<endl;
    cout << "IV -> 4: " << romanToInt("IV") <<endl;
    cout << "IX -> 9: " << romanToInt("IX") <<endl;
    cout << "LVIII -> 58: " << romanToInt("LVIII") << endl;
    cout << "MCMXCIV -> 1994: " << romanToInt("MCMXCIV") << endl;
    cout << "CMXCIX -> 999: " << romanToInt("CMXCIX") << endl;
}

#endif //ALGORITHM_ROMAN_TO_INT_H
