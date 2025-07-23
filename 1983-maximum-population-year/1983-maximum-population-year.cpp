class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> pop(101,0);
        for(auto x:logs){
            pop[x[0]-1950]++;
            pop[x[1]-1950]--;
        }
        int currPopulation=0,year=0,maxPop=0;
        for(int i=0;i<101;i++){
            currPopulation+=pop[i];
            if(currPopulation>maxPop){
                maxPop=currPopulation;
                year=i+1950;
            }
        }
        return year;
    }
};