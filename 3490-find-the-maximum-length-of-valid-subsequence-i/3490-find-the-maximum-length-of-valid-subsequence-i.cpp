class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();

        bool first=nums[0]&1;
        int odd=first,even=!first,alter=1;
        
        for(int i=1;i<n;i++){

            int temp=nums[i]&1;

            if(temp==0)even++;
            else odd++;

            if(temp!=first){
                alter++;
                first=!first;
            }
        }
        return max({odd,even,alter});
    }
};