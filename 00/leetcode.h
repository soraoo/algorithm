//
// Created by Administrator on 2020/11/25.
//

#ifndef ALGORITHM_LEETCODE_H
#define ALGORITHM_LEETCODE_H

#include <string>
using namespace std;

string numberToWords(int num) {
    string dic1[] = {"zero", "one", "two", "three", "four", "five", "six",
                     "seven", "eight", "nine", "ten", "eleven", "twelve"};
    string dic2[] = {"zero", "Tenth", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty",
                     "Seventy", "Eighty", "Ninety"};
    string dic3[] = {"", "Thousand", "Million", "Billion"};

    string result;
    int count = 0;
    while(num > 0) {
        int k = num % 1000;
        if(k <= 12) {
            result = dic1[k];
        } else if(k < 100) {
            result = dic2[k/10] + dic1[k % 10];
        } else {
            result = dic1[k / 100] + "Hundred";
            k = k % 100;
            result = dic2[k/10] + dic1[k % 10];
        }
        num /= 1000;
        if(num > 0) {
            result = dic3[count] + result;
            ++count;
        }
    }
    return result;
}

#endif //ALGORITHM_LEETCODE_H
