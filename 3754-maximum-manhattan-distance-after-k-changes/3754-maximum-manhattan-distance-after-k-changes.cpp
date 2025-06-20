class Solution {
public:
    int maxDistance(string s, int k) {
        int result=0;
        int north=0,south=0,east=0,west=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='N')north++;
            else if(s[i]=='S')south++;
            else if(s[i]=='E')east++;
            else west++;

            int xCoor=abs(south-north);
            int yCoor=abs(east-west);

            int manDis=xCoor+yCoor;
            int dist=manDis+min(2*k,i+1-manDis);
            result=max(result,dist);
        }
        return result;

    }
};