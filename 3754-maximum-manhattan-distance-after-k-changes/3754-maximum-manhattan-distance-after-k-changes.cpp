




class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0,north=0,south=0,east=0,west=0;
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(c=='N')north++;
            else if(c=='S')south++;
            else if(c=='W')west++;
            else east++;

            int canPairs=min(north,south)+min(east,west);

            int distHealedByk=0;
            int distanceTillNow=i+1;
            if(canPairs<=k){
                distHealedByk=distanceTillNow;
            }
            else{
                int distCanBeAffected=distanceTillNow-2*canPairs;
                distHealedByk=distCanBeAffected+2*k;
            }
            ans=max(distHealedByk,ans);
        }
        return ans;
    }
};