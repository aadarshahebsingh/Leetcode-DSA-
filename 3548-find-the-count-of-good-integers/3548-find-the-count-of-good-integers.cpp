#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long factorials[11];

    Solution() {
        factorials[0] = 1;
        for (int i = 1; i <= 10; ++i) {
            factorials[i] = factorials[i - 1] * i;
        }
    }

    vector<long long> generatePalindromes(int length) {
        vector<long long> palindromes;
        if (length == 0) return palindromes;
        
        int halfLength = (length + 1) / 2;
        long long startValue = pow(10, halfLength - 1);
        long long endValue = pow(10, halfLength) - 1;

        if (length == 1) startValue = 0;

        for (long long halfPart = startValue; halfPart <= endValue; ++halfPart) {
            string halfStr = to_string(halfPart);
            string fullStr;

            if (length % 2 == 0) {
                string reversedHalf = halfStr;
                reverse(reversedHalf.begin(), reversedHalf.end());
                fullStr = halfStr + reversedHalf;
            } else {
                string reversedHalf = halfStr.substr(0, halfStr.size() - 1);
                reverse(reversedHalf.begin(), reversedHalf.end());
                fullStr = halfStr + reversedHalf;
            }

            if (fullStr.size() == length) {
                long long num = stoll(fullStr);
                palindromes.push_back(num);
            }
        }

        return palindromes;
    }

    vector<int> getDigitCounts(long long number, int length) {
        vector<int> counts(10, 0);
        string numStr = to_string(number);
        
        while (numStr.size() < length) numStr = "0" + numStr;

        for (char digit : numStr) {
            counts[digit - '0']++;
        }
        
        return counts;
    }

    long long countNumbersWithDigitCounts(vector<int> digitCounts, int length) {
        long long total = 0;

        for (int digit = 1; digit <= 9; ++digit) {
            if (digitCounts[digit] == 0) continue;

            vector<int> updatedCounts = digitCounts;
            updatedCounts[digit]--;

            bool valid = all_of(updatedCounts.begin(), updatedCounts.end(), [](int count) { return count >= 0; });
            if (!valid) continue;

            long long arrangements = factorials[length - 1];
            for (int i = 0; i < 10; ++i) {
                arrangements /= factorials[updatedCounts[i]];
            }
            total += arrangements;
        }

        return total;
    }

    long long countGoodIntegers(int n, int k) {
        vector<long long> palindromes = generatePalindromes(n);

        vector<long long> filteredPalindromes;
        for (long long num : palindromes) {
            if (num % k == 0) {
                filteredPalindromes.push_back(num);
            }
        }

        set<vector<int>> uniqueDigitCounts;
        for (long long num : filteredPalindromes) {
            vector<int> counts = getDigitCounts(num, n);
            uniqueDigitCounts.insert(counts);
        }

        long long result = 0;
        for (const vector<int>& counts : uniqueDigitCounts) {
            result += countNumbersWithDigitCounts(counts, n);
        }

        return result;
    }
};
