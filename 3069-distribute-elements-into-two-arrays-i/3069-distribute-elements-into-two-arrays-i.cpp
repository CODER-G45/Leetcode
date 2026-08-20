class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 0 , j = 0;
        int idx = 2;
        while(idx < nums.size())
        {
            if(arr1[i]>arr2[j]) arr1.push_back(nums[idx++]),i++;
            else arr2.push_back(nums[idx++]),j++;
        }
        arr1.reserve(arr1.size()+arr1.size());
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};