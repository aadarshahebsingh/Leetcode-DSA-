class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int, vector<int>, greater<int>> minPlayers;
        priority_queue<int, vector<int>, greater<int>> minTrainers;

        for(auto x:players)minPlayers.push(x);
        for(auto x:trainers)minTrainers.push(x);

        int ans=0;
        while(!minPlayers.empty() && !minTrainers.empty()){
            int x=minPlayers.top(),y=minTrainers.top();
            if(y>=x){
                minPlayers.pop();minTrainers.pop();
                ans++;
            }
            else{
                minTrainers.pop();
            }
        }
        return ans;
    }
};