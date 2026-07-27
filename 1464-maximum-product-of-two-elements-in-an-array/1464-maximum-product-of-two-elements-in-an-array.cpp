class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f = INT_MIN,s = INT_MIN;
        for(int num : nums)
        {
            if(num > f)s=f,f=num;
            else if(num > s)s = num;
        }
        return --f*--s;
    }
};