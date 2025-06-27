// 2 <= n < k * 8

// length of the answer < k*8


// aabbaacio
// k=2


// letsleetcode

// a=4
// b=2

// c=1
// i=1
// o=1








class Solution {
public:
    bool checkSub(string  source,string pattern,int k){
        int patternIndex=0,count=0;
        for(auto x:source){
            if(x==pattern[patternIndex]){
                patternIndex++;

                if(patternIndex==pattern.length()){
                    patternIndex=0;
                    count++;
                    if(count==k)return true;
                }
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> freq(26,0);

        for(char x:s){
            freq[x-'a']++;
        }

        
        vector<char> character;

        for(int i=25;i>=0;i--){
            if(freq[i]>=k){
                character.push_back(i+'a');
            }
        }
        

        queue<string> bfsQueue;
    
        for(auto x:character){
            
            bfsQueue.push(string(1,x));
            cout<<string(1,x)<<endl;
            
        }
        string ans="";
        while(!bfsQueue.empty()){
            string curr=bfsQueue.front();
            bfsQueue.pop();
            if(curr.length()>ans.length()){
                ans=curr;
            }

            for(char x:character){
                string temp=curr+x;
                if(checkSub(s,temp,k)){
                    bfsQueue.push(temp);
                }
            }
        }
        return ans;
    }
};