// 3,5,6,7  k=9
// 3
// 3,5
// 3,6
// 3,5,6

// 2^3=8-2^2=4

// 2,3,3,4,6,7

// 2^5=32
// 2^4=16
// 2^3=8
// 2^2=4
// 2^0=1

// 61







class Solution {
public:
    int numSubseq(vector<int>& arr, int target) {
        int n=arr.size();
        int MOD=1e9+7;
        vector<int> powerOfTwo(n+1,1);

        for(int i=1;i<=n;i++){
            powerOfTwo[i]=(powerOfTwo[i-1]*2)%MOD;
        }
        
        sort(arr.begin(),arr.end());
        int left=0,right=n-1,ans=0;
        
        while(left<=right){
            if(arr[left]+arr[right]<=target){
                ans=(ans+powerOfTwo[right-left])%MOD;
                left++;
            }
            else right--;
        }
        return ans;
    }
};
























