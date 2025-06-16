// [7,8,2,9]

// [2,1]
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int initialValue=nums[0],maximumDifference=-1;

        for(int index=1;index<nums.size();index++){
            if(nums[index]<=initialValue){
                initialValue=nums[index];
            }
            else{
                maximumDifference=max(maximumDifference,nums[index]-initialValue);
            }
        }
        return maximumDifference;
    }
};