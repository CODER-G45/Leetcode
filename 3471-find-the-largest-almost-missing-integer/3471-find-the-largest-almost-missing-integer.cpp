class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < k) return -1;
        unordered_map<int, int> freq;
        int ans = -1;
        if (k == n)
            return *max_element(nums.begin(), nums.end());
        if (k == 1) {
            for (int num : nums)
                freq[num]++;
            for (auto x : freq) {
                if (x.second == 1)
                    ans = max(ans, x.first);
            }
            return ans;
        }
        for (int num : nums)
            freq[num]++;
        if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);
        if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);
        return ans;
    }
};