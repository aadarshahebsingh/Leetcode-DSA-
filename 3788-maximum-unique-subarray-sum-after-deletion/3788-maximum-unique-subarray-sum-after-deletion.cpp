class Solution {
public:
    int maxSum(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        set<int> uniqueNumbers;
        int maxi=INT_MIN;
        for(auto &x:nums){
            if(x>0)uniqueNumbers.insert(x);
            maxi=max(maxi,x);
        }
        vector<int> arr(uniqueNumbers.begin(),uniqueNumbers.end());
        int ans=0;
        for(auto &x:arr)ans+=x;
        if(ans)return ans;
        return maxi;

    }
};