#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>

using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int sz = nums.size();
        int i = sz - 1;
        int j = i;
        // find the first number that invalidate the
        // increasing order backwardly named PivotValue.
        while (i > 0 && nums[i] <= nums[i-1]) --i;
        i--;
        if (i >= 0) {
            // find the smallest number that larger than PivotValue
            // named SwapValue, then swap the PivotValue and PivotValue
            while (j > 0 && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        // reverse the numbers on the left side of PivotValue
        reverse(begin(nums) + i + 1, end(nums));
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> nums{1, 2};
    s.nextPermutation(nums);
    for_each(nums.begin(), nums.end(), [] (int num) {
            cout << num << " ";
        });
    return 0;
}

