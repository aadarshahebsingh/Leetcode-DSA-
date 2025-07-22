class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=0,currSum=0,n=nums.size(),left;

        unordered_set<int> alreadyVisited;
        for(int i=0;i<n;i++){
            while(alreadyVisited.find(nums[i])!=alreadyVisited.end()){
                alreadyVisited.erase(nums[left]);
                currSum-=nums[left];
                left++;
            }

            currSum+=nums[i];
            alreadyVisited.insert(nums[i]);
            ans=max(ans,currSum);

        }
        return ans;
    }
};