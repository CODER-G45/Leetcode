class Solution {
public:
    long long sumAndMultiply(int n) {
        string a = to_string(n);
        string b ="";
        int sum = 0;
        for(char c : a)
        {
            if(c != '0')
            {
                b = b+c;
                sum += c - '0';
            }
        }
        if(b.empty()) return 0;
        long long ans = 1LL * stoi(b) * sum;
        return ans;
    }
};