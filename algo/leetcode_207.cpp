#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
    class DGraph {
    public:
        DGraph(int numV) : numV_(numV), nexts_(numV) {}
        void addEdge(int from, int to) {
            nexts_[from].push_back(to);
        }
        int numV() { return numV_; }
        list<int> nexts(int v) { return nexts_[v]; }
    private:
        int numV_;
        vector<list<int>> nexts_;
    };
    class DGraphCycle {
    public:
        DGraphCycle(DGraph& graph) :
            graph_(graph),
            hasCycle_(false),
            onStack_(graph_.numV(),false),
            marked_(graph.numV(), false){
            for (int v = 0; v < graph.numV(); ++v) {
                if (!marked_[v]) {
                    dfs(v);
                }
            }
        }
        void dfs(int v) {
            onStack_[v] = true;
            marked_[v] = true;
            for (auto w: graph_.nexts(v)) {
                if (hasCycle()) return;
                else if (!marked_[w]) {
                    dfs(w);
                } else if (onStack_[w]) {
                    hasCycle_ = true;
                }
            }
            onStack_[v] = false;
        }
        bool hasCycle() { return hasCycle_; }
    private:
        DGraph graph_;
        bool hasCycle_;
        vector<int> onStack_;
        vector<int> marked_;
    };
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        DGraph graph(numCourses);
        for (auto edge: prerequisites) {
            graph.addEdge(edge.first, edge.second);
        }
        DGraphCycle dgc(graph);
        return !dgc.hasCycle();
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<pair<int, int>> prereq{{1, 0}, {0, 1}};
    s.canFinish(2, prereq);
    return 0;
}
