class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = min(firstPlayer, secondPlayer);
        int right = max(firstPlayer, secondPlayer);

        // base condition
        if (left + right == n + 1)
            return {1, 1};
        if (n == 3 || n == 4)
            return {2, 2};

        // mirror transformation
        if (left - 1 > n - right) {
            int mirrorLeft = n + 1 - left;
            left = n + 1 - right;
            right = mirrorLeft;
        }

        int nextRound = (n + 1) / 2;
        int earliest = n, latest = 1;

        // Case 1: both players in left half
        if (right * 2 <= n + 1) {
            int playersLeft = left - 1;
            int playersBetween = right - left - 1;
            for (int i = 0; i <= playersLeft; i++) {
                for (int j = 0; j <= playersBetween; j++) {
                    auto ans = earliestAndLatest(nextRound, i + 1, i + j + 2);
                    earliest = min(earliest, 1 + ans[0]);
                    latest = max(latest, 1 + ans[1]);
                }
            }
        } 
        // Case 2: mirrored / across sides
        else {
            int mirroredRight = n + 1 - right;
            int playersBeforeLeft = left - 1;
            int midGap = mirroredRight - left - 1;
            int centerGap = right - mirroredRight - 1;

            for (int i = 0; i <= playersBeforeLeft; i++) {
                for (int j = 0; j <= midGap; j++) {
                    int pos1 = i + 1;
                    int pos2 = i + j + 1 + (centerGap + 1) / 2 + 1;
                    auto ans = earliestAndLatest(nextRound, pos1, pos2);
                    earliest = min(earliest, 1 + ans[0]);
                    latest = max(latest, 1 + ans[1]);
                }
            }
        }

        return {earliest, latest};
    }
};
