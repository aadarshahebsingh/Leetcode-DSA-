class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int> vis(n,0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int idx=i;
                int leftIdx=max(idx-k,0),rightIdx=min(idx+k,n-1);
                
                for(int index=leftIdx;index<=rightIdx;index++){
                    if(vis[index]==0){
                        vis[index]=1;
                        ans.push_back(index);
                    }
                }
            }
            
        }
        return ans;
    }
};