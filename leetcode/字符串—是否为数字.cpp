#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s)
    {

        int len = s.length();

        //remove spaces
        int start = 0;
        int end = len - 1;
        while (start <= end) {
            if (s[start] == ' ')
                start++;
            if (s[end] == ' ')
                end--;
            if (start > end)
                return false;
            if (s[start] != ' ' && s[end] != ' ')
                break;
        }

        int ePos = -1;
        for (int i = start; i <= end; i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                ePos = i;
                break;
            }
        }
        if (ePos == -1)
            return check(s, start, end, false);

        return check(s, start, ePos - 1, false) && check(s, ePos + 1, end, true);
    }

    bool check(string& str, int start, int end, bool mustInt)
    {
        if (str[start] == '+' || str[start] == '-')
            start++;

        bool point = false;
        bool hasInt = false;

        while (start <= end) {
            if (str[start] == '.') {
                if (point || mustInt)
                    return false;
                point = true;
            } else if (!isdigit(str[start])) {
                return false;
            } else {
                hasInt = true;
            }
            start++;
        }
        return hasInt;
    }
};

int main()
{
    Solution s;
    std::cout << s.isNumber(".456") << std::endl;
}