// [5,4,3]   -1
// [9,4,3,2]

// [7,11,5,4,2,7]


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minimumElement=nums[0],maximumDifference=-1,n=nums.size();

        for(int index=1;index<n;index++){
            if(nums[index]>minimumElement){
                maximumDifference=max(maximumDifference,nums[index]-minimumElement);
            }
            else{
                minimumElement=nums[index];
            }
        }
        return maximumDifference;
    }
};