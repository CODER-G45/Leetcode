class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        int i = 0 , l = 0;
        vector<int>freq(3,0);
        while(l < n)
        {
            freq[s[l] - 'a']++;
            l++;
                while(freq[0] && freq[1] && freq[2])
                {
                    ans += n - l + 1;
                    freq[s[i]-'a']--;
                    i++;
                }
        }
        return ans;
    }
};