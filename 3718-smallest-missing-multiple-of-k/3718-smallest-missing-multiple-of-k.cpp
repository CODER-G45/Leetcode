class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int>s;
        int ans = k;
        sort(nums.begin(),nums.end());
        for(int x : nums)
        {
            if(x % k == 0){
                s.insert(x);
                if(x == ans){
                    int i = x / k;
                    while(s.count(i*k))i++;
                    ans = i*k;
                }
            }
        }
        return ans;
    }
};