// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#include <cstring>
#include <cstdio>
using namespace std;

class CMyString
{
public:
    explicit CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString();

    CMyString& operator=(const CMyString& rhs);

    void Print();

private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = {'\0'};
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy_s(m_pData, length + 1, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy_s(m_pData, length + 1, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    if(this != &rhs)
    {
        CMyString copy(rhs);
        char* temp = copy.m_pData;
        copy.m_pData = m_pData;
        m_pData = temp;
    }
    return *this;
}

//==============================测试代码================================
void CMyString::Print()
{
    printf("%s", m_pData);
}

/**
 * 普通赋值
 */
void Test1()
{
    printf("Test1 begins:\n");
    char* text = "Hello World";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;
    printf("The Expected result is: %s.\n", text);
    printf("The actual result is: ");
    str2.Print();
    printf(".\n");
}

/**
 * 自赋值
 */
void Test2()
{
    printf("Test1 begins:\n");
    char* text = "Hello World";
    CMyString str1(text);
    str1 = str1;
    printf("The Expected result is: %s.\n", text);
    printf("The actual result is: ");
    str1.Print();
    printf(".\n");
}

/**
 * 连续赋值
 */
void Test3()
{
    printf("Test3 begins:\n");

    char* text = "Hello world";

    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.Print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.Print();
    printf(".\n");
}

int main()
{
    Test1();
    Test2();
    Test3();

    return 0;
}
