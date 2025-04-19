class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long pair=0;
        for(int i=0;i<nums.size();i++){
            long long up=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            long long low=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();

            if(up==n || nums[i]+nums[up]>upper)continue;
            if(up==low && up!=i){
                pair++;
                continue;
            }
            pair+=(low-up);
        }
        return pair;
        
    }
};