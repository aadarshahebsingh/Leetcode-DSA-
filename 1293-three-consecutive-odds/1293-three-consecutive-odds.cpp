class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(ans==3)return true;
            if(arr[i]%2==0)ans=0;
            else ans++;
        }
        if(ans==3)return true;
        return false;
    }
};