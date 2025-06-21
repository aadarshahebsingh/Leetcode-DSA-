class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> alpha(26,0);
        for(auto x:word){
            alpha[x-'a']++;
        }
        vector<int> freq;
        for(auto x:alpha){
            if(x)freq.push_back(x);
        }
        int ans=INT_MAX;
        sort(freq.begin(),freq.end());
        for(auto baseFreq:freq){
            int noOfDeletions=0;
            for(auto currFreq:freq){
                if(currFreq<baseFreq){
                    noOfDeletions+=currFreq;
                }
                else if(currFreq>baseFreq+k){
                    noOfDeletions+=currFreq-(baseFreq+k);
                }
            }
            ans=min(ans,noOfDeletions);
        }
        return ans;

    }
};