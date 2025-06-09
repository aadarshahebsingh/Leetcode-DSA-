class Solution {
public:
    int helper(int prefix,int n){
        long long first=prefix,next=prefix+1;
        int totalCnt=0;
        while(first<=n){
            totalCnt+=static_cast<int> (std::min(n+1LL,next)-first);
            first*=10;
            next*=10;
        }
        return totalCnt;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int cnt=helper(curr,n);
            if(k>=cnt){
                k-=cnt;
                curr++;
                
            }
            else{
                curr*=10;
                --k;
            }
        }
        return curr;
    }
};