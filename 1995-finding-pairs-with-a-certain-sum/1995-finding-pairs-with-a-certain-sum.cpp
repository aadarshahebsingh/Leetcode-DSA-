class FindSumPairs {
public:
    unordered_map<int,int> freq;
    vector<int> arr1,arr2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1=nums1;
        arr2=nums2;

        for(auto x:arr2){
            freq[x]++;
        }
    }
    
    void add(int index, int val) {
        freq[arr2[index]]--;
        arr2[index]+=val;
        freq[arr2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto x:arr1){
            ans+=freq[tot-x];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */