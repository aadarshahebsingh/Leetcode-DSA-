class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        int n = grid.size();
        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;

        while (!q.empty()) {
            auto [dist, pos] = q.front(); q.pop();
            int x = pos.first, y = pos.second;

            if (x == n - 1 && y == n - 1) return dist;

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
                    !visited[newX][newY] && grid[newX][newY] == 0) {
                    visited[newX][newY] = true;
                    q.push({dist + 1, {newX, newY}});
                }
            }
        }

        return -1;
    }
};
