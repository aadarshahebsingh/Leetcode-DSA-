class Solution {
public:
    unordered_map<int, int> mp;

    void bfs(int start, const vector<int>& edges) {
        vector<bool> visited(edges.size(), false);
        queue<pair<int, int>> q;
        q.push({start, 0});

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (visited[node]) continue;
            visited[node] = true;
            mp[node] = dist;

            if (edges[node] != -1 && !visited[edges[node]]) {
                q.push({edges[node], dist + 1});
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        bfs(node1, edges);

        vector<bool> visited(edges.size(), false);
        queue<pair<int, int>> q;
        q.push({node2, 0});

        int result = -1;
        int minDist = INT_MAX;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (visited[node]) continue;
            visited[node] = true;

            if (mp.count(node)) {
                int maxDist = max(mp[node], dist);
                if (maxDist < minDist || (maxDist == minDist && node < result)) {
                    minDist = maxDist;
                    result = node;
                }
            }

            if (edges[node] != -1 && !visited[edges[node]]) {
                q.push({edges[node], dist + 1});
            }
        }

        return result;
    }
};
