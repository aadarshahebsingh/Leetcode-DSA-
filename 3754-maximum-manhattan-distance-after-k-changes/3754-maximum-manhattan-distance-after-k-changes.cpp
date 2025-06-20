class Solution {
public:
    int maxDistance(string s, int k) {
        int ans=0,dist=0;
        int north=0,south=0,east=0,west=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='N')north++;
            else if(s[i]=='S')south++;
            else if(s[i]=='E')east++;
            else west++;

            int l=i+1;

            int diff=min(north,south)+min(east,west);
            if(diff<=k)dist=l;
            else{
                int temp=l-2*diff;
                dist=temp+2*k;
            }
            ans=max(ans,dist);
        }
        return ans;

    }
};