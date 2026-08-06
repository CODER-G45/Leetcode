class Solution {
public:
    int smallestNumber(int n, int t) {
        if(n%10 == 0) return n;
        int x = n;
        int pro = 1;
        while(x >0)pro *= x%10,x /= 10;
        x = n;
        while(1)
        {
            if(!(pro % t)|| pro == 0) return x;
            int u = x%10;
            if(u+1 >= 10) return ++x;
            x++;
            pro = (pro / u)*(u+1);
        }
        return 0;
    }
};