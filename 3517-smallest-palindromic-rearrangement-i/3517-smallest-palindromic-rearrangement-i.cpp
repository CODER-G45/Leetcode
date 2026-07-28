class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        unordered_map<char,int>m;
        for(char c : s)
        {
            m[c]++;
        }
        int oddCount = 0;
        string ans = "";
        char x = 'a';
        char last;
        bool odd = false;
        for(int i = 0; i < 26; i++)
        {
            if(m.find(x) != m.end())
            {
                if(m[x] % 2 == 1) last = x , odd = true;
                ans.append(m[x]/2,x);
            }
            x = x + 1;
        }
        if(odd)
        {
            string rev = ans;
            reverse(rev.begin(),rev.end());
            return ans + last + rev;
        }
        string rev = ans;
        reverse(rev.begin(),rev.end());
        return ans + rev;
    }
};