#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  void dfs(const string& digits, const vector<string>& edges,
           int level, string path, vector<string>& res) {
    if (level == digits.length()) {
      res.push_back(path);
      return;
    }

    for (auto c : edges[digits[level] - '0']) {
      dfs(digits, edges, level + 1, path + c, res);
    }
  }
public:
  vector<string> letterCombinations_dfs(string digits) {
    vector<string> res;
    if (digits.empty()) return res;
    vector<string> edges{"", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"};
    int level = 0;
    string path;

    dfs(digits, edges, level, path, res);

    return res;
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return vector<string>();
    vector<string> res{""};
    vector<string> edges{"", "", "abc", "def", 
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"};
    for (auto digit : digits) {
      vector<string> tmp;
      for (const string s : res) {
        for (auto c : edges[digit - '0']) {
          tmp.push_back(s + c);
        }
      }
      res.assign(tmp.begin(), tmp.end());
    }
    return res;
  }
};

int main() {
  Solution s;
  return 0;
}
