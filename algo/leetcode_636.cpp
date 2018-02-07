#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int, int>> call;
        for (auto log: logs) {
            int idx, t;
            char cmd[10];
            sscanf(log.c_str(), "%d:%[a-z]:%d", &idx, cmd, &t);
            if (call.empty()) {
                call.emplace(idx, t);
                continue;
            }
            if (string(cmd) == string("start")) {
                res[call.top().first] += t - call.top().second;
                call.top().second = t;
                call.emplace(idx, t);
            } else { // "stop"
                res[call.top().first] += ++t - call.top().second;
                call.pop();
                if (!call.empty())
                    call.top().second = t;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> logs{"0:start:0","1:start:2","1:end:5","0:end:6"};
    auto res = s.exclusiveTime(2, logs);
    for_each(res.begin(), res.end(), [](int s){
            cout << s << "\n";
        });
    return 0;
}
