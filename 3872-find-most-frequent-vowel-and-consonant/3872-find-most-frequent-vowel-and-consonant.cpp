class Solution {
public:
    int maxFreqSum(string s) {
        int maxV = 0, maxC = 0;
        unordered_map<char,int>mp;

        for(char c: s){
            if(isVowel(c)){
                mp[c]++;
                maxV = max(maxV, mp[c]);
            }
            else{
                mp[c]++;
                maxC = max(maxC, mp[c]);
            }
        }

        return maxV + maxC;
    }
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};