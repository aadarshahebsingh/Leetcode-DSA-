class Solution {
public:
    bool isPowerOfTwo(int n) {
        // bool flag=;
        if(n<=0)return false;
        return n>0 && (n&(n-1))==0;
    }
};