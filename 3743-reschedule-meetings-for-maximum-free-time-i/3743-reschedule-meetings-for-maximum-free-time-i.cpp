// eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]



// eventTime=10
// k=2

// 0,1
// 2,4
// 8,9

// 0,1
// 1,2    k=1
// 9,10   k=1


class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        
        vector<int> gaps;
        gaps.push_back(startTime[0]);
        for(int i=1;i<n;i++){
            gaps.push_back(startTime[i]-endTime[i-1]);
            cout<<gaps[i]<<endl;
        }
        gaps.push_back(eventTime-endTime[n-1]);

        int windowSize=min(k+1,(int)gaps.size());
        long long currSum=0,ans=0;
        for(int i=0;i<windowSize;i++){
            currSum+=gaps[i];
        }

        ans=currSum;
        for(int i=windowSize;i<gaps.size();i++){
            currSum+=gaps[i]-gaps[i-windowSize];
            ans=max(ans,currSum);
        }
        return (int)ans;
    }
};