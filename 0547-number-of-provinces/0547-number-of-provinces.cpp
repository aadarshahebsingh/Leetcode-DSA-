class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
        if (visited[node] == 1) return;
        visited[node] = 1;

        for (auto adj : graph[node]) {
            if (!visited[adj]) {
                dfs(adj, graph, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                }
            }
        }

        int ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis);
                ans++;
            }
        }
        return ans;
    }
};
