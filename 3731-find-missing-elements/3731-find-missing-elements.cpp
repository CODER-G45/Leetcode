class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int p = nums[0];
        for(int i = 0; i < n ; i++)
        {
            if(p != nums[i])
            {
                ans.push_back(p);
                p++;
                i--;
            }else
            {
                p++;
            }
        }
        return ans;
    }
};