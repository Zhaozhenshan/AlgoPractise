#include <cstring>
#include <iostream>
#include <string>
class string {
public:
    string(const char* src = NULL)
    {
        //TODO1:构造函数 //开始添加代码
        m_length = src ? strlen(src) : 0;
        m_data = new char[m_length + 1];
        memset(m_data, 0, m_length + 1);
        if (src) {
            memcpy(m_data, src, m_length);
        }
        //结束添加代码
    }
    ~string()
    {
        //TODO2:析构函数 //开始添加代码
        delete[] m_data;
        m_length = 0;
        //结束添加代码
    }
    int size() const
    {
        return m_length;
    }
    const char* c_str() const
    {
        return m_data;
    }
    string(const string& src)
    {
        //TODO3:拷贝构造函数 //开始添加代码
        m_length = src.size();
        m_data = new char[m_length + 1];
        memset(m_data, 0, m_length + 1);
        memcpy(m_data, src.c_str(), m_length);
        //结束添加代码
    }
    string operator+(const string& src) const
    {
        string ret;
        //TODO4:运算符+
        //开始添加代码
        ret.m_length = m_length + src.size();
        ret.m_data = new char[ret.m_length + 1];
        memset(ret.m_data, 0, ret.m_length + 1);
        memcpy(ret.m_data, m_data, m_length);
        memcpy(ret.m_data + m_length, src.c_str(), src.size());
        //结束添加代码
        return ret;
    }
    string& operator+=(const string& src)
    {
        //TODO5:运算符+=
        //TODO5:运算符+= //开始添加代码
        if (src.size() > 0) {
            int newLength = m_length + src.size();
            char* newData = new char[newLength + 1];
            memset(newData, 0, newLength + 1);
            memcpy(newData, m_data, m_length);
            memcpy(newData + m_length, src.c_str(), src.size());
            delete[] m_data;
            m_length = newLength;
            m_data = newData;
        }
        //结束添加代码 return *this;
    }
    bool operator==(const string& str) const
    {
        //TODO5:运算符== //开始添加代码
        if (m_length != str.size())
            return false;
        return strcmp(m_data, str.c_str()) ? false : true;
        //结束添加代码
    }
    void Reverse()
    {
        //TODO5:字符串反转 //开始添加代码
        char temp;
        for (int i = 0; i < m_length / 2; i++) {
            temp = m_data[i];
            m_data[i] = m_data[m_length - 1 - i];
            m_data[m_length - 1 - i] = temp;
        }
        //结束添加代码
    }
    void Sort()
    {
        //TODO6:字符串从小到大排序 //开始添加代码
        char temp;
        int index, offset;
        for (index = 0; index < m_length - 1; index++) {
            for (offset = index + 1; offset < m_length; offset++) {
                if (strcmp(m_data + index, m_data + offset) > 0) {
                    temp = *(m_data + offset);
                    *(m_data + offset) = *(m_data + index);
                    *(m_data + index) = temp;
                }
            }
        }
        //结束添加代码
    }

private:
    char* m_data;
    int m_length;
};
int main()
{
    //构造函数
    string str1 = "abcde";
    string str2("12345");
    //拷贝构造函数
    string str3 = str1;
    std::cout << (str3 == str1) << std::endl;
    //拷贝构造函数
    string str4(str2);
    std::cout << (str2 == str4) << std::endl;
    //+ 运算符
    string str5 = str1 + str2;
    std::cout << (str5 == "abcde12345") << std::endl;
    std::cout << (str5.size() == str1.size() + str2.size()) << std::endl;
    //+= 运算符
    str5 += str1;
    std::cout << (str5 == "abcde12345abcde") << std::endl;

    std::cout << (str5 == "abcde12345abcde") << std::endl;

    //反转
    string str6 = "12345678";
    str6.Reverse();
    std::cout << (str6 == "87654321") << std::endl;
    //排序
    string str7 = "202008131617";
    str7.Sort();
    std::cout << (str7 == "000111223678") << std::endl;
    return 0;
}
