class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        int f = 0, s = 1;
        for(int i = 2 ; i < n; i++)
        {
            if(nums[f]>nums[s])
            {
                int x = nums[i];
                int idx = i;
                while(idx > f + 1)nums[idx--] = nums[idx - 1];
                nums[idx] = x;
                f++,s++;
            }
            else s++;
        }
        return nums;
    }
};