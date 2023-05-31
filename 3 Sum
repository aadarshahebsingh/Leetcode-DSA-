class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int first=nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                int second=nums[j];
                int last=nums[k];
                vector<int> temp;
                if(first+second+last==0){
                    temp.push_back(first);
                    temp.push_back(second);
                    temp.push_back(last);
                    j++;
                    k--;
                    ans.push_back(temp);
                }
                else if(first+second+last>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }return ans;
    }
};
