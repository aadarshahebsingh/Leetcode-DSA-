#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    long long createPalindrome(long long n, bool odd) {
        long long res = n;
        if (odd) n /= 10;
        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }
        return res;
    }

    bool checkPalindrome(long long n, int base) {
        string str = "";
        while (n > 0) {
            str += to_string(n % base);
            n /= base;
        }
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        for (int i = 1; n > 0; i *= 10) {
            for (int j = i; n > 0 && j < i * 10; j++) {
                long long p = createPalindrome(j, true);
                if (checkPalindrome(p, k)) {
                    ans += p;
                    n--;
                }
            }
            for (int j = i; n > 0 && j < i * 10; j++) {
                long long p = createPalindrome(j, false);
                if (checkPalindrome(p, k)) {
                    ans += p;
                    n--;
                }
            }
        }
        return ans;
    }
};
