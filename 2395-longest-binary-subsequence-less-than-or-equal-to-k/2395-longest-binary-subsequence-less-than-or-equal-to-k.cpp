// 1001010

// zeros=4  3  2
// len 0 1 3 
// number += 2^1=2<=k
// 2^3=8 + 2 =10>k

// 3+2=5



class Solution {
public:
    int longestSubsequence(string s, int k) {
        int zeroes=0,n=s.length(),len=0,idx=0;
        long long number=0;
        for(auto x:s){
            if(x=='0')zeroes++;
        }
        for(int i=n-1;i>=0;i--){
            cout<<len<<endl;
            if(s[i]=='0'){
                len++;
                zeroes--;
            }
            else{
                if(idx<32){
                    number+=(1LL<<idx);
                    if(number<=k){
                        len++;
                    }
                    else{
                        len+=zeroes;
                        break;
                    }
                }
            }
            idx++;
        }
        return len;
    }
};