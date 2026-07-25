class Solution {
public:
    int maxProduct(int n) {
        int m1  = 0, m2 = -1;
        while(n > 0)
        {
            int dig = n%10;
            if(dig >= m2)
            {
                if(dig > m1)
                {
                    m2 = m1;
                    m1 = dig;
                }
                else
                {
                    m2 = dig;
                }
            }
            n /= 10;
        }
        return m1*m2;
    }
};