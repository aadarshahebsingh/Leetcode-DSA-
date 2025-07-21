class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<2)return s;
        int i=0;
        string ans="";
        for(i=0;i<s.length()-2;i++){
            if(s[i]==s[i+1] && s[i]==s[i+2]){
                continue;
            }
            else ans+=s[i];
        }
        ans+=s[i];
        i++;
        ans+=s[i];
        return ans;
    }
};