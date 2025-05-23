class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<long long> delta;
        long long ans=0;
        for(auto x:nums){
            long long temp=x^k;
            delta.push_back(temp-x);
            ans+=x;
        }
        
        sort(delta.begin(),delta.end());
        int n=delta.size();
        for(int i=n-1;i>0;i--){
            long long temp=delta[i]+delta[i-1];
            if(temp > 0){
                ans+=temp;
                i--;
            }
            else break;
        }
        return ans;

    }
};