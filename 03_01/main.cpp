// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <iostream>
#include <string>
using namespace std;

/**
 * 找出数组中重复的数字
 * @param numbers 整数数组
 * @param length 数组的长度
 * @param duplication 数组中的一个重复的数字
 * @return 是否输入有效，并且数组中存在重复的数字
 */
bool duplicate(int* numbers, int length, int* duplication)
{
    ///为空，输入无效
    if(!numbers || length <= 0)
    {
        return false;
    }

    ///数字不在[0, n-1]范围内，输入无效
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length - 1)
        {
            return false;
        }
    }

    for(int i = 0; i < length; ++i)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }

    return false;
}

//==================================测试用例=======================================

bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
        {
            return true;
        }
    }
    return false;
}

void test(const string& testName, int numbers[], int length, int expected[], int expectedLength, bool validArg)
{
    cout << testName << " begins: ";
    int duplication;
    bool validInput = duplicate(numbers, length, &duplication);
    if(validArg == validInput)
    {
        if(validArg)
        {
            if(contains(expected, expectedLength, duplication))
            {
                cout << "Passed." << endl;
            }
            else
            {
                cout << "FAILED." << endl;
            }
        }
        else
        {
            cout << "Passed." << endl;
        }
    }
    else
    {
        cout << "FAILED." << endl;
    }
}

/**
 * 重复的数字是数组中最小的数
 */
void test1()
{
    int numbers[] = {2, 1, 3, 1, 4};
    int duplications[] = {1};
    test("test-repeat number is min number in array",
         numbers,
         sizeof(numbers) / sizeof(int),
         duplications,
         sizeof(duplications) / sizeof(int),
         true);
}

/**
 * 重复的数字是数组中最大的数字
 */
void test2()
{
    int numbers[] = {2, 4, 3, 1, 4};
    int duplications[] = {4};
    test("test-repeat number is max number in array",
         numbers,
         sizeof(numbers) / sizeof(int),
         duplications,
         sizeof(duplications) / sizeof(int),
         true);
}

/**
 * 数组中存在多个重复的数字
 */
void test3()
{
    int numbers[] = {2, 3, 2, 1, 4};
    int duplications[] = {2, 4};
    test("test-much numbers in array",
         numbers,
         sizeof(numbers) / sizeof(int),
         duplications,
         sizeof(duplications) / sizeof(int),
         true);
}

/**
 * 没有重复的数字
 */
void test4()
{
    int numbers[] = {2, 1, 3, 0, 4};
    int duplications[] = {-1};;
    test("test-no repeated numbers",
         numbers,
         sizeof(numbers) / sizeof(int),
         duplications,
         sizeof(duplications) / sizeof(int),
         false);
}

/**
 * 没有重复的数字
 */
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 };
    test("test-no repeated numbers",
         numbers,
         sizeof(numbers) / sizeof(int),
         duplications,
         sizeof(duplications) / sizeof(int),
         false);
}

/**
 * 无效的输入
 */
void test6()
{
    int* numbers = nullptr;
    int duplications[] = {-1};
    test("test-invalid input",
         numbers,
         0,
         duplications,
         sizeof(duplications) / sizeof(int),
         false);
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}

