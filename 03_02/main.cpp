// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

#include <iostream>
using namespace std;

/**
 * 空间换时间的算法，空间效率优先
 * 会创建一个辅助空间，空间复杂度O(n) = n 时间复杂度O(n) = n
 * @param arr
 * @param length
 * @param result
 * @return
 */
bool duplicate(const int* arr, int length, int* result)
{
    if(!arr || length <= 0)
    {
        return false;
    }
    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = 0;
    }
    for(int i = 0; i < length; ++i)
    {
        ++copy[arr[i]];
    }
    for(int i = 0; i < length; ++i)
    {
        if(copy[i] > 1)
        {
            *result = copy[i];
            delete[] copy;
            return true;
            break;
        }
    }
    delete[] copy;
    return false;
}

int count_range(const int* arr, int length, int start, int end)
{
    if(!arr)
    {
        return 0;
    }

    int count = 0;
    for(int i = 0; i < length; ++i)
    {
        if(arr[i] >= start && arr[i] <= end)
        {
            ++count;
        }
    }
    return count;
}

/**
 * 时间换空间算法
 * 利用二分查找，空间复杂度O(n)=1 时间复杂度O(n)=n*logn
 * @param arr
 * @param length
 * @return
 */
int duplicate_2(const int* arr, int length)
{
    if(!arr || length <= 0)
    {
        return -1;
    }

    int start = 1;
    int end = length - 1;
    while(end >= start)
    {
        int mid = ((end - start) >> 1) + start;
        int count = count_range(arr, length, start, mid);
        if(start == end)
        {
            if(count > 1)
            {
                return start;
            }
            else
            {
                break;
            }
        }
        if(count > (mid - start + 1))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

bool contains(const int* arr, int length, int item)
{
    for(int i = 0; i < length; ++i)
    {
        if(arr[i] == item)
        {
            return true;
        }
    }
    return false;
}

void test(const char* name, const int* arr, int length, const int* expected, int expectedLength)
{
    cout << name << " begin: ";
    int result = duplicate_2(arr, length);
    if(result > 0)
    {
        if(contains(expected, expectedLength, result))
        {
            cout << "result is " << result << endl;
        }
        else
        {
            cout << "Failed." << endl;
        }
    }
    else
    {
        cout << "invalid input." << endl;
    }
}

void test1()
{
    int arr[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int expected[] = {2, 3};
    test("test1", arr, sizeof(arr) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

void test2()
{
    int* arr = nullptr;
    int expected[] = {-1};
    test("test2", arr, sizeof(arr) / sizeof(int), expected, sizeof(expected) / sizeof(int));
}

int main()
{
    test1();
    test2();
    return 0;
}