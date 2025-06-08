class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> str;
        for(int i=1;i<=n;i++){
            str.push_back(to_string(i));
        }
        sort(str.begin(),str.end());
        vector<int> arr;
        for(auto x:str){
            arr.push_back(stoi(x));
        }
        return arr;
    }
};