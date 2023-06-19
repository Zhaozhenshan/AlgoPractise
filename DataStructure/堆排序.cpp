#include <iostream>
#include <vector>

using namespace std;

void adjust(vector<int>& nums, const int parent, const int size)
{
    int child = 2 * parent + 1;
    if (child >= size)
        return;
    child += child + 1 < size && nums[child + 1] > nums[child] ? 1 : 0;
    if (nums[parent] < nums[child]) {
        swap(nums[parent], nums[child]);
        adjust(nums, child, size);
    }
}

void createHeap(vector<int>& nums)
{
    int n = nums.size();
    for (int i = n / 2; i >= 0; i--) {
        adjust(nums, i, n);
    }
}

void heapSort(vector<int>& nums)
{
    createHeap(nums);
    for (size_t end = nums.size() - 1; end != 0; end--) {
        swap(nums[0], nums[end]);
        adjust(nums, 0, end);
    }
}

int main()
{
    vector<int> nums { 1, 2, 3, 4, 5, 6 };
    heapSort(nums);
    for (auto x : nums) {
        cout << x << " ";
    }
    cout << endl;
}
