class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n-i-1;j++){
                temp.push_back((ans[j]+ans[j+1])%10);
            }
            ans=temp;
        }
        return ans[0];
    }
};