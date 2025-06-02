class Solution {
public:
    int candy(vector<int>& a) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> b(a.size(), -1);
        for(int i = 0;i<a.size();i++){
            pq.push({a[i], i});
        } 

        while(!pq.empty()){
            auto [rating, index] = pq.top();
            pq.pop();
            int val = 1;
            if(index-1>=0){
                if(b[index-1] != -1){
                    if(a[index-1] < a[index]) val = max(val, b[index-1] + 1);
                }
            }
            if(index+1 < a.size()){
                if(b[index+1] != -1){
                    if(a[index+1] < a[index]) val = max(val, b[index+1] + 1);
                }
            }

            b[index] = val;
        }


        return accumulate(b.begin(), b.end(), 0);
    }
};