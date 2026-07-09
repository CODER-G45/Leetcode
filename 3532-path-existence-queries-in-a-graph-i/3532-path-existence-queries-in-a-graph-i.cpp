class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> comp(n,0);
        for (int i = 1; i < n; i++)
        {
            comp[i] = comp[i - 1];
            if (nums[i] - nums[i - 1] > maxDiff) comp[i]++;
        }
        for (auto &q : queries)
        {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }
        return ans;
    }
};