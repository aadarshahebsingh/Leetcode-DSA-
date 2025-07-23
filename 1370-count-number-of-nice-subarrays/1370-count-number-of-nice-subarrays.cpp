class Solution {
public:
    int helper(vector<int> nums,int n,int k){
        int ans=0,start=0,ending=0,odd=0;

        while(ending<nums.size()){
            if(nums[ending]%2==1)odd++;
            while(odd>k){
                if(nums[start]%2==1)odd--;
                start++;
            }
            ans+=(ending-start+1);
            ending++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return helper(nums,n,k)-helper(nums,n,k-1);
    }
};