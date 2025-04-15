class Solution {
public:
    using ll = long long;
    vector<ll> seg_tree;

    //Update segment tree at index query_idx
    void updateSegTree(int st_idx, int s, int e, int query_idx) {
        if(query_idx < s || query_idx > e){
            return;
        }

        if(s == e){
            seg_tree[st_idx]++;
            return;
        }

        int mid = s + (e - s) / 2;
        int leftChild = 2 * st_idx;
        int rightChild = leftChild + 1;

        updateSegTree(leftChild, s, mid, query_idx);
        updateSegTree(rightChild, mid + 1, e, query_idx);

        seg_tree[st_idx] = seg_tree[leftChild] + seg_tree[rightChild];
    }

    //Query sum in range [qs, qe]
    ll rangeSumQuery(int st_idx, int s, int e, int qs, int qe) {
        if(qs > e || qe < s){
            return 0;
        }
        if(qs <= s && e <= qe){
            return seg_tree[st_idx];
        }

        int mid = s + (e - s) / 2;
        int leftChild= 2 * st_idx;
        int rightChild = leftChild + 1;

        ll left = rangeSumQuery(leftChild, s, mid, qs, qe);
        ll right = rangeSumQuery(rightChild, mid + 1, e, qs, qe);

        return left + right;
    }

    // Count number of good triplets
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        seg_tree.assign(4 * n, 0);

        unordered_map<int, int> posInNums2;
        for(int i = 0; i < n; i++){
            posInNums2[nums2[i]] = i;
        }

        ll totalTriplets = 0;
        updateSegTree(1, 0, n - 1, posInNums2[nums1[0]]);

        for(int i = 1; i < n - 1; ++i){
            int idx = posInNums2[nums1[i]];
            ll leftCommon = rangeSumQuery(1, 0, n - 1, 0, idx - 1);
            ll righTCommon = (n - idx - 1) - (i - leftCommon);

            totalTriplets += leftCommon  * righTCommon;
            updateSegTree(1, 0, n - 1, idx);
        }

        return totalTriplets;
    }
};