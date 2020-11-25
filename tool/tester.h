// 算法对数器（检查算法用，比测试用例好用）
// 0x00 有一个想要测试的算法
// 0x01 实现一个生成随机数的方法
// 0x02 实现一个绝对正确的算法
// 0x03 实现结果比较算法
// 0x04 将生成的数作为参数去测试两个算法，并对结果进行比较
// 0x05 如果测试次数足够多，并且比较结果相同，说明该算法是正确的
// 0x06 如果测试结果不同，打印用于测试的数据，并检查问题
// 对数器可用规模较小，但测试次数足够多的方法来验证算法，因此如果算法出问题，小规模查bug更方便
// Created by Administrator on 2020/11/25.
//

#ifndef ALGORITHM_TESTER_H
#define ALGORITHM_TESTER_H

/**
 * 对数器
 */
template<typename T>
class tester
{
public:
    bool test();

protected:
    void getRandomData(T& data);
    bool compare(T& lhs, T& rhs);
};

#endif //ALGORITHM_TESTER_H
