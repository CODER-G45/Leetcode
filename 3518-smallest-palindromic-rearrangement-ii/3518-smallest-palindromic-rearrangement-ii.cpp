class Solution {
public:
    long long LIM = (long long)1e6 + 5;

    long long comb(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > LIM) return LIM;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ans = 1;
        int left = rem;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) continue;
            ans *= comb(left, cnt[i]);
            if (ans > LIM) ans = LIM;
            left -= cnt[i];
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid = char('a' + i);
        }

        string left = "";
        int m = s.size() / 2;

        for (int pos = 0; pos < m; pos++) {

            bool ok = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    ok = true;
                    break;
                }

                k -= ways;
                half[c]++;
            }

            if (!ok) return "";
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};