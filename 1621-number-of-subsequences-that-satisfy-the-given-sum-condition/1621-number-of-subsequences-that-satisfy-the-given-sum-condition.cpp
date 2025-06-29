// 2,3,3,4,6,7   target=12

// sum=9 noOfSub=2^5=32
// sum=10 noOfSub=2^4=16
// sum=10 noOfSub=2^3=8
// sum=11 noOfSub=2^2=4
// sum=12 noOfSub=2^0=1
// 61


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0,MOD=1e9+7;
        int left=0,right=n-1;
        vector<int> powerOfTwo(n+1,1);
        for(int i=1;i<n+1;i++){
            powerOfTwo[i]=(powerOfTwo[i-1]*2)%MOD;
        }

        while(left<=right){
            
            if(nums[left]+nums[right]<=target){
                ans=(ans+powerOfTwo[right-left])%MOD;
                left++;
            }
            else right--;
        }
        return ans;
    }
};