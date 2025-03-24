
using namespace std;

class Solution {
public:
    int countDays(int totalDays, vector<vector<int>>& schedules) {
        if (schedules.empty()) return totalDays;

        sort(schedules.begin(), schedules.end());

        vector<pair<int, int>> mergedSchedules;
        int currentStart = schedules[0][0];
        int currentEnd = schedules[0][1];

        for (int i = 1; i < schedules.size(); ++i) {
            if (schedules[i][0] <= currentEnd + 1) {
                currentEnd = max(currentEnd, schedules[i][1]);
            } else {
                mergedSchedules.push_back({currentStart, currentEnd});
                currentStart = schedules[i][0];
                currentEnd = schedules[i][1];
            }
        }
        mergedSchedules.push_back({currentStart, currentEnd});

        int availableDays = 0;

        if (mergedSchedules[0].first > 1) {
            availableDays += mergedSchedules[0].first - 1;
        }

        for (int j = 1; j < mergedSchedules.size(); ++j) {
            availableDays += mergedSchedules[j].first - mergedSchedules[j - 1].second - 1;
        }

        if (mergedSchedules.back().second < totalDays) {
            availableDays += totalDays - mergedSchedules.back().second;
        }

        return availableDays;
    }
};