class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> suffixArray(n,0);

        int maximumElement=0;

        for(int index=n-1;index>=0;index--){
            suffixArray[index]=maximumElement;
            maximumElement=max(nums[index],maximumElement);
        }

        int maximumDifference=-1;
        for(int index=0;index<n;index++){
            if(suffixArray[index]>nums[index]){
                maximumDifference=max(maximumDifference,suffixArray[index]-nums[index]);
            }
        }
        return maximumDifference;
    }
};