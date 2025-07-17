class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k,vector<int> (k,0));
        for(auto x:nums){
            for(int rem=0;rem<k;rem++){
                dp[rem][x%k]=dp[x%k][rem]+1;
            }
        }

        int ans=0;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<k;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};