class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        else if(n == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        long long f = LLONG_MIN;
        long long s = LLONG_MIN;
        long long t = LLONG_MIN;
        for(auto x : nums)
        {
            if(x == f || x == s || x == t)continue;
            if(x > f) t = s, s = f,f =x;
            else if(x > s) t = s, s = x;
            else if(x > t) t = x;
        }
        return t == LLONG_MIN ? f : t;
    }
};