class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        // if( n == 1) return 1;
        if( n <= 2) return n ;
        int minI = 0 , maxI = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] > nums[maxI]) maxI = i;
            if(nums[i] < nums[minI]) minI = i;
        }
        int ff = max(minI,maxI)+1;
        int fb = n - min(minI,maxI);
        int fbs = min(minI,maxI) + 1  + n - max(minI,maxI) ;
        return min(ff,min(fb,fbs));
    }

};