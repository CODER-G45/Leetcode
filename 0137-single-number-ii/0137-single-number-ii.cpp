class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int x : nums)freq[x]++;
        for(auto [first , sec] : freq)
            if(sec != 3) return first;
        return 0;
    }
};