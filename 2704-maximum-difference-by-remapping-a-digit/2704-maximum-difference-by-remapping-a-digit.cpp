class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        int i=0;
        while(s[i]=='9' && i<s.length()-1) {
            i+=1;
        }


        string mx=s;
        for(char& ch:mx) if(ch==s[i]) {
            ch='9';
        }
        
        string mn=s;
        for(char& ch:mn) if(ch==s[0]) {
            ch='0';
        }

        return stoi(mx)-stoi(mn);
    }
};