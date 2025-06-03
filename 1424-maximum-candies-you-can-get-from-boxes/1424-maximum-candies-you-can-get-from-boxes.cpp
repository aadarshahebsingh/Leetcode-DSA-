class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        vector<bool> hasBox(n, false);
        vector<bool> hasKey(n, false);
        vector<bool> visited(n, false);
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }

        for (int box : initialBoxes) {
            if (status[box] == 1) {
                q.push(box);
                visited[box] = true;
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front();
            q.pop();
            totalCandies += candies[box];

            for (int key : keys[box]) {
                hasKey[key] = true;
                if (hasBox[key] && !visited[key]) {
                    q.push(key);
                    visited[key] = true;
                }
            }

            for (int contained : containedBoxes[box]) {
                hasBox[contained] = true;
                if ((status[contained] == 1 || hasKey[contained]) && !visited[contained]) {
                    q.push(contained);
                    visited[contained] = true;
                }
            }
        }

        return totalCandies;
    }
};
