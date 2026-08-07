class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        int x = n;
        set<int>s;
        while(x != 1)
        {
            s.insert(x);
            int a = x;
            int sum = 0;
            while(a > 0)
            {
                sum += (a%10)*(a%10);
                a /= 10;
            }
            if(sum == 1) return true;
            if(s.count(sum)) return false;
            x = sum;
        }
        return x == 1;
    }
};