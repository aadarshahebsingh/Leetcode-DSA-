class Solution {
public:
    long rec(int i,vector<vector<int>> &ques,vector<long>&dp,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];

        long take=ques[i][0]+rec(i+ques[i][1]+1,ques,dp,n);
        long dont=rec(i+1,ques,dp,n);

        return dp[i]=max(take,dont);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long> dp(n,-1);
        return rec(0,questions,dp,n);
    }
};