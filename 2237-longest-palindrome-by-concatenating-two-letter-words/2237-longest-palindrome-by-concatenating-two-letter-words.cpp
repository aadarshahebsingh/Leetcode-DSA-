class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        int cnt[26][26]={};
        
        for(auto x:words){
            int a=x[0]-'a',b=x[1]-'a';

            if(cnt[b][a]>0){
                ans+=4;
                cnt[b][a]--;
            }
            else{
                cnt[a][b]++;
            }
        }

        for(int i=0;i<26;i++){
            if(cnt[i][i]>0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};