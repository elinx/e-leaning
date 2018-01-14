#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3;) {
      for (int j = i + 1; j < nums.size() - 2;) {
        int k = j + 1, l = nums.size() - 1;
        while (k < l) {
          int sum = nums[i] + nums[j] + nums[k] + nums[l];
          if (sum == target) {
            vector<int> t{nums[i], nums[j], nums[k++], nums[l--]};
            res.push_back(t);
            while (nums[k] == nums[k-1]) ++k;
            while(nums[l] == nums[l+1]) --l;
          } else if (sum < target) {
            ++k;
            while (nums[k] == nums[k-1]) ++k;
          } else {
            --l;
            while(nums[l] == nums[l+1]) --l;
          }
        }
        ++j;
        while (nums[j] == nums[j-1]) ++j;
      }
      ++i;
      while (nums[i] == nums[i-1]) ++i;
    }
    return res;
  }
};

int main() {
  Solution s;
  // Vector<int> nums{1,0,-1,0,-2,2}; // -2 -1 0 0 1 2
  vector<int> nums{-3, -2, -1, 0, 0, 1, 2, 3}; // -2 -1 0 0 1 2
  auto vecs = s.fourSum(nums, 0);
  for (auto vec : vecs) {
    for (auto e : vec) {
      cout << e << ", ";
    }
    cout << endl;
  }
}
