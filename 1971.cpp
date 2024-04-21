// 21.4.2024
// 1971. Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/1238117618/

class Solution {
public:
    int getParent(int node, vector<int>& parent){
        return parent[node] == node ? node : (parent[node] = getParent(parent[node], parent));
    }
    void unify(int u, int v, vector<int>& parent){
        parent[getParent(u, parent)] = getParent(v, parent);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(auto edge : edges){
            unify(edge[0], edge[1], parent);
        }
        return getParent(source, parent) == getParent(destination, parent);

    }
};