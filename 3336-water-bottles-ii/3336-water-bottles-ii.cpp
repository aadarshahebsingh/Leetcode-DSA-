class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=0;
        ans+=numBottles;
        while(numBottles>=numExchange){
            ans+=1;
            numBottles=numBottles-numExchange+1;
            numExchange=numExchange+1;
        }
        return ans;
    }
};