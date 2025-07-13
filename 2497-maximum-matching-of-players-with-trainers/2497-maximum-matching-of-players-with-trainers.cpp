class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Min Heaps for players and trainers
        priority_queue<int, vector<int>, greater<int>> minPlayers;
        priority_queue<int, vector<int>, greater<int>> minTrainers;

        for (int p : players) minPlayers.push(p);
        for (int t : trainers) minTrainers.push(t);

        int ans = 0;

        while (!minPlayers.empty() && !minTrainers.empty()) {
            int player = minPlayers.top();
            int trainer = minTrainers.top();

            if (trainer >= player) {
                // Trainer can train the player
                ++ans;
                minPlayers.pop();
                minTrainers.pop();
            } else {
                // Trainer too weak, discard trainer
                minTrainers.pop();
            }
        }

        return ans;
    }
};
