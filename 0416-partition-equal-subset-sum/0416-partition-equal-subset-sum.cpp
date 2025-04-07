class Solution {
public:
    bool helper(int ind,int sum,vector<int> nums,vector<vector<int>>& dp){
        if(sum==0)return true;
        if(ind<0 || sum<0)return false;
        if(dp[ind][sum]!=-1)return dp[ind][sum];
        bool pick=helper(ind-1,sum-nums[ind],nums,dp);
        bool notPick=helper(ind-1,sum,nums,dp);

        return dp[ind][sum]=(pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n=nums.size();
        if(sum%2)return false;
        sum=sum/2;
        // vector<vector<int>> dp((nums.size()+1vector<int>(sum+1,-1));
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // return helper(nums.size()-1,sum,nums,dp);

        // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));

        vector<bool> dp(sum+1,false);

        dp[0]=true;
        for(auto x:nums){
            for(int i=sum;i>=x;i--){
                dp[i]=dp[i]||dp[i-x];
            }
        }        
        return dp[sum];
    }
};