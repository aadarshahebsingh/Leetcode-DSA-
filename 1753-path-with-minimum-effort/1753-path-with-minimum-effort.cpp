class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<>> pq;

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [curEffort, pos] = pq.top();
            pq.pop();

            int x = pos.first;
            int y = pos.second;
            if (x == n - 1 && y == m - 1) return curEffort;

            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int newEffort = max(curEffort, abs(heights[newX][newY] - heights[x][y]));
                    if (newEffort < effort[newX][newY]) {
                        effort[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};
