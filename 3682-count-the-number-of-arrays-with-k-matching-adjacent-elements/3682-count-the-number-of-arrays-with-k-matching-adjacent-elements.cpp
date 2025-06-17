class Solution {
public:
    vector<int> factorialArray, inverseFactorialArray;
    const int MOD = 1e9 + 7;

    int powerComputation(long long base, int power) {
        long long result = 1;
        while (power) {
            if (power & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            power >>= 1;
        }
        return result;
    }

    int modifiedInverse(int value) {
        return powerComputation(value, MOD - 2);
    }

    void computingFactorial(int n) {
        factorialArray = vector<int>(n + 1);
        factorialArray[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorialArray[i] = (1LL * i * factorialArray[i - 1]) % MOD;
        }
    }

    void computingInverseFactorial(int n) {
        inverseFactorialArray = vector<int>(n + 1);
        inverseFactorialArray[n] = modifiedInverse(factorialArray[n]);
        for (int i = n; i > 0; i--) {
            inverseFactorialArray[i - 1] = (1LL * inverseFactorialArray[i] * i) % MOD;
        }
    }

    void preComputation(int value) {
        computingFactorial(value);
        computingInverseFactorial(value);
    }

    int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return 1LL * factorialArray[n] * inverseFactorialArray[r] % MOD * inverseFactorialArray[n - r] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        preComputation(n);

        int waysToChooseEqualParts = nCr(n - 1, k);

        // Ensure m - 1 is casted to long long to avoid overflow
        int waysToArrange = 1LL * m * powerComputation(1LL * (m - 1), n - 1 - k) % MOD;

        return 1LL * waysToChooseEqualParts * waysToArrange % MOD;
    }
};
