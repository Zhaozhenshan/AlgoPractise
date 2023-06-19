#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums)
    {
        vector<string> temp;
        for (auto x : nums) {
            temp.push_back(to_string(x));
        }
        //字符串比较规则：依据ascii码的大小进行比较，有提前结束的情况，认为短者更小
        sort(temp.begin(), temp.end(), [&](const string& s1, const string& s2) { return s1 + s2 < s2 + s1; });
        string res;
        for (auto x : temp)
            res += x;
        return res;
    }
};