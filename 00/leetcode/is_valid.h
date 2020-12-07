//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
// 有效字符串需满足：
//
//
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
//
//
// 注意空字符串可被认为是有效字符串。
//
// 示例 1:
//
// 输入: "()"
//输出: true
//
//
// 示例 2:
//
// 输入: "()[]{}"
//输出: true
//
//
// 示例 3:
//
// 输入: "(]"
//输出: false
//
//
// 示例 4:
//
// 输入: "([)]"
//输出: false
//
//
// 示例 5:
//
// 输入: "{[]}"
//输出: true
// Related Topics 栈 字符串

#include <iostream>
#include <string>
#include <stack>
using namespace std;

char get(char l) {
    switch (l)
    {
        case '[':
            return ']';
        case '{':
            return '}';
        case '(':
            return ')';
        default:
            return ' ';
    }
}

bool isValid(string s) {
    if(s.empty()) return true;
    stack<char> cstack;
    for(char &c : s) {
        if(c == '[' || c == '{' || c == '(') {
            cstack.push(c);
        } else {
            if(cstack.empty()) return false;
            char pop = cstack.top();
            if(get(pop) != c) return false;
            cstack.pop();
        }
    }
    return cstack.empty();
}

/**
 * 简洁版本 思路挺巧妙的
 * @param s
 * @return
 */
bool isValid_1(string s) {
    stack<char> cstack;
    for(const char& c : s) {
        if(c == '(') cstack.push(')');
        else if(c == '[') cstack.push(']');
        else if(c == '{') cstack.push('}');
        else if(cstack.empty() || c != cstack.top()) return false;
        else cstack.pop();
    }
    return cstack.empty();
}

void test_isValid() {
    cout << "() -> true: " << (isValid("()") ? "true" : "false") << endl;
    cout << "()[]{} -> true: " << (isValid("()[]{}") ? "true" : "false") << endl;
    cout << "(] -> false: " << (isValid("(]") ? "true" : "false") << endl;
    cout << "([)] -> false: " << (isValid("([)]") ? "true" : "false") << endl;
    cout << "{[]} -> true: " << (isValid("{[]}") ? "true" : "false") << endl;
    cout << "}[]{ -> false: " << (isValid("}[]{") ? "true" : "false") << endl;
}