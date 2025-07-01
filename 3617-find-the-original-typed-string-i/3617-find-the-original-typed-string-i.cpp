class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1,n=word.size();
        if(word.size()==1)return ans;

        for(int i=1;i<n;i++){
            int cnt=0;
            while(i<n && word[i]==word[i-1]){
                cnt++;
                i++;
            }
            ans+=(cnt);
        }
        return ans;
    }
};