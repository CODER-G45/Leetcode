class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        int ans = k;
        for(int x : nums)
        {
            if(x % k == 0){
                s.insert(x);
                if(x == ans){
                    int i = x / k;
                    while(s.count(i++*k));
                    ans = --i*k;
                }
            }
        }
        return ans;
    }
};