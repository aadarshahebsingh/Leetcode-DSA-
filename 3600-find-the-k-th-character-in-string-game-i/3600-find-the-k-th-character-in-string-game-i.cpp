class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<k){
            string temp="";
            for(int i=0;i<s.length();i++){
                char c=s[i];
                if(c=='z'){
                    c='a';
                }
                else{
                    c++;
                }
                temp+=c;
            }
            s+=temp;
        }
        return s[k-1];
    }
};