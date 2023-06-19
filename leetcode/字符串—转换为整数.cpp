//面试题67

#include <iostream>
#include <limits.h>
#include <string>
using namespace std;

class Solution {
public:
    int strToInt(string s)
    {
        int left { 0 };
        while (left < s.size()) {
            if (s[left] == ' ') {
                left++;
            } else {
                break;
            }
        }
        int right = left;
        while (right < s.size()) {
            if (isdigit(s[right + 1])) {
                right++;
            } else {
                break;
            }
        }
        long long int num { 0 };
        bool fu = false;
        if (s[left] != '+' && s[left] != '-' && !isdigit(s[left])) {
            return 0;
        }
        if (s[left] == '+') {
            left++;
        } else if (s[left] == '-') {
            fu = true;
            left++;
        }
        if (!fu) {
            while (left <= right) {
                num = num * 10 + (s[left] - '0');
                left++;
                if (num > INT_MAX) {
                    return INT_MAX;
                }
            }
        } else {
            while (left <= right) {
                num = num * 10 - (s[left] - '0');
                left++;
                if (num < INT_MIN) {
                    return INT_MIN;
                }
            }
        }
        return num;
    }
};