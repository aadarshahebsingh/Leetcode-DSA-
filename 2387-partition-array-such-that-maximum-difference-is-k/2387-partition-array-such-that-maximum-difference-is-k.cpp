class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int ans=0;
        for(int i=0;i<nums.size();){
            int j=i;
            while(j<nums.size() && (nums[j]-nums[i]<=k)){
                j++;
            }
            i=j;
            ans++;
        }
        return ans;
    }
};