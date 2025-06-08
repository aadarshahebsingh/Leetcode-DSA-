class Solution {
public:
    void dfs(vector<int>& ans,int curr,int  n){
        if(curr>n)return;
        ans.push_back(curr);

        for(int i=0;i<=9;i++){
            if(curr*10+i>n)break;
            dfs(ans,curr*10+i,n);
        }
        
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int  i=1;i<=9;i++){
            dfs(ans,i,n);
        }
        return ans;
    }
};