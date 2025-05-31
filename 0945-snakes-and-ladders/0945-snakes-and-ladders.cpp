#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    pair<int, int> getCoordinates(int s, int n) {
        int quot = (s - 1) / n;
        int rem = (s - 1) % n;
        int row = n - 1 - quot;
        int col = (quot % 2 == 0) ? rem : (n - 1 - rem);
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> visited(n * n + 1, 0);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = 1;

        while (!q.empty()) {
            auto [s, moves] = q.front();
            q.pop();

            if (s == n * n) return moves;

            for (int i = 1; i <= 6 && s + i <= n * n; ++i) {
                int next = s + i;
                auto [r, c] = getCoordinates(next, n);

                if (board[r][c] != -1) {
                    next = board[r][c];
                }

                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};
