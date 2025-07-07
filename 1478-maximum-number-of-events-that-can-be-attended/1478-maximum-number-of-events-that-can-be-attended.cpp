class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());

        int  n=events.size();
        priority_queue<int,vector<int>,greater<int>>pq;

        int iter=0,ans=0;

        for(int i=1;i<=1e5;i++){
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }

            while(iter<n && events[iter][0]==i){
                pq.push(events[iter][1]);
                iter++;
            }

            if(pq.empty())continue;
            ans++;
            pq.pop();
        }
        return  ans;
    }
};