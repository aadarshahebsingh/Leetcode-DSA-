class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxDist = weights[0] + weights[weights.size()-1];
        long long minDist = weights[0] + weights[weights.size()-1];
        priority_queue<int> maxpq; // Max heap for largest values
        priority_queue<int, vector<int>, greater<int>> minpq; // Min heap for smallest values
        
        for(int i = 1; i < weights.size(); i++) {
            maxpq.push(weights[i] + weights[i-1]);
            minpq.push(weights[i] + weights[i-1]);
        }
        
        for(int i = 1; i < k; i++) {
            maxDist += maxpq.top(); maxpq.pop();
            minDist += minpq.top(); minpq.pop();
        }
        
        return maxDist - minDist;
    }
};