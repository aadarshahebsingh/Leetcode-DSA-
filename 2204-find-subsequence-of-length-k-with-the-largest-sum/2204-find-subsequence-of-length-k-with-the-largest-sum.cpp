class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> valueWithInd;
        for(int i=0;i<nums.size();i++){
            valueWithInd.push_back({nums[i],i});
        }
        sort(valueWithInd.begin(),valueWithInd.end(),[](pair<int, int>& a, pair<int, int>& b){
            return a.first>b.first;
        });

        vector<pair<int,int>> ans(valueWithInd.begin(),valueWithInd.begin()+k);

        sort(ans.begin(),ans.end(),[](pair<int, int>& a, pair<int, int>& b){
            return a.second<b.second;
        });

        vector<int> result;

        for(auto x:ans){
            result.push_back(x.first);
        }

        return result;
    }
};