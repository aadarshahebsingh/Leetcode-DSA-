class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        int vowel=0,consonent=0;

        string vo="aeiouAEIOU";
        for(auto c:word){
            if(isalpha(c)){
                if(vo.find(c)!=string::npos){
                    vowel++;
                }
                else consonent++;
            }
            else{
                if(!isdigit(c)){
                    return false;
                }
            }
        }
        return vowel&&consonent;
    }
};