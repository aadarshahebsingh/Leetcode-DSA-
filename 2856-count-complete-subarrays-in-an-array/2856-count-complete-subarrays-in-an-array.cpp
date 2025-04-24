class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int total=unordered_set<int> (nums.begin(),nums.end()).size();
        int result=0,left=0;
        for(int right=0;right<nums.size();right++){
            mp[nums[right]]++;
            while(left<=right && mp.size()==total){
                result+=nums.size()-right;
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                    mp.erase(nums[left]);
                left++;
            }
        }
        return result;
    }
};