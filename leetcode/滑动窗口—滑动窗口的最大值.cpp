#include <deque>
#include <vector>
using namespace std;
/*
滑动窗口的最大值
1. 题目与最小栈的题有一定区别：如果入队元素是最大值，需要清空数据结构里小于该元素的值；如果出队元素是最大值，也能保证下一个队首元素依然是最大值
2. 所以此题目需要用队列来解决，入队前清空队列内小于该元素的所有值，出滑动窗口时，只需要清空队首元素
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        vector<int> res;
        int high = 0;
        int low = 1 - k;
        int n = nums.size() - 1;
        while (high <= n) {
            //1.出滑窗的元素刚好是dq[0],则dp[0]出对
            if (low >= 1 && !dq.empty() && nums[low - 1] == dq[0]) {
                dq.pop_front();
            }
            //2.nums[high]入队前，删除队列里小于nums[high]的值
            while (!dq.empty() && dq[0] < nums[high]) {
                dq.pop_front();
            }
            while (!dq.empty() && dq[dq.size() - 1] < nums[high]) {
                dq.pop_back();
            }
            /* 3.nums[high]入队，此事能保证队列中的所有值是大于nums[high]
            也就间接保证了队列是一个单调非增的，dp[0]永远是最大的 */
            dq.push_back(nums[high]);
            if (low >= 0 && !dq.empty())
                res.push_back(dq[0]);
            low++;
            high++;
        }
        return res;
    }
};