// 1,3,3,5,7,9,2,2,5,2,3,7
// 1 2 2 2
// 3 2 2 2 3

// 1 2 2 2 3 3 5 7


class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int ind=0,ans=0;
        for(int i=0;i<nums.size();i++){
            while(nums[i]-nums[ind]>1){
                ind++;

            }
            if(nums[i]-nums[ind]==1){
                ans=max(ans,i-ind+1);
            }
        }
        return ans;
    }
};