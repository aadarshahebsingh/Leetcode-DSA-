class Solution {
public:
    // Count how many pairs (ele, num2) such that ele * num2 <= target
    long long countPairs(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long pairs = 0;

        for (int ele : nums1) {
            if (ele > 0) {
                // Positive element: binary search for max index such that ele * nums2[i] <= target
                int left = 0, right = nums2.size();
                while (left < right) {
                    int mid = (left + right) / 2;
                    if ((long long)ele * nums2[mid] <= target) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                pairs += left;
            } else if (ele < 0) {
                // Negative element: binary search for min index such that ele * nums2[i] <= target
                int left = 0, right = nums2.size();
                while (left < right) {
                    int mid = (left + right) / 2;
                    if ((long long)ele * nums2[mid] <= target) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                pairs += nums2.size() - left;
            } else {
                // ele == 0: product is 0, valid if target >= 0
                if (target >= 0) {
                    pairs += nums2.size();
                }
            }
        }
        return pairs;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countPairs(nums1, nums2, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
