class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // Prefix sum of digits
        vector<long long> prefSum(n + 1, 0);

        // Position of non-zero digits
        vector<int> pos;
        vector<int> digit;

        // Mapping from original index -> compressed index
        vector<int> leftIdx(n, -1), rightIdx(n, -1);

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        // leftIdx[i] = first non-zero digit >= i
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < m && pos[p] < i) p++;
            if (p < m) leftIdx[i] = p;
        }

        // rightIdx[i] = last non-zero digit <= i
        p = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (p >= 0 && pos[p] > i) p--;
            if (p >= 0) rightIdx[i] = p;
        }

        // Powers of 10
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        // Prefix concatenated value
        vector<long long> prefNum(m + 1, 0);
        for (int i = 0; i < m; i++)
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int L = leftIdx[l];
            int R = rightIdx[r];

            long long x = 0;

            if (L != -1 && R != -1 && L <= R) {
                int len = R - L + 1;
                x = (prefNum[R + 1] - prefNum[L] * pow10[len]) % MOD;
                if (x < 0) x += MOD;
            }

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};