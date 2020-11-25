// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <iostream>
#include <string>
using namespace std;

/**
 * 思路，先从右上角开始，如果小于目标数字，则可以排除掉第一行。因为它是所在行最大的。
 * 后续同理
 * 空间复杂度O(n)=1 时间复杂度O(n) = n(rows) + m(cols)
 * @param matrix
 * @param rows
 * @param cols
 * @param num
 * @return
 */
bool find(const int* matrix, int rows, int cols, int num)
{
    if(!matrix || rows <= 0 || cols <= 0)
    {
        return false;
    }

    int row = 0, col = cols - 1;
    while(row < rows && col >= 0)
    {
        int n = matrix[row * cols + col];
        if(n == num)
        {
            return true;
        }
        else
        {
            if(n < num)
            {
                ++row;
            }
            else
            {
                --col;
            }
        }
    }
    return false;
}

// ==============================test code==================================
void test(const string& testName, int* matrix, int rows, int cols, int num, bool expected)
{
    cout << testName << " begin: ";
    bool result = find(matrix, rows, cols, num);
    if(result == expected)
    {
        cout << "Passed." << endl;
    }
    else
    {
        cout << "Failed." << endl;
    }
}

/**
 * 1  2  8   9
 * 2  4  9   12
 * 4  7  10  13
 * 6  8  11  15
 * the num in matrix
 */
void test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    test("test1", (int*)matrix, 4, 4, 7, true);
}

int main()
{
    return 0;
}

