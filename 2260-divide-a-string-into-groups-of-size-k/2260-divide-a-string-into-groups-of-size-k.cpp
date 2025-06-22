class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> arr;

        int len=0;
        string str="";
        for(int i=0;i<s.length();i++){
            str+=s[i];
            len++;
            if(len==k){
                arr.push_back(str);
                str="";
                len=0;
            }
        }

        if(len){
            while(len!=k){
                str+=fill;
                len++;
            }
            arr.push_back(str);
        }
        
        return arr;
    }
};