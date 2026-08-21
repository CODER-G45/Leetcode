class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        bool odd = (m+n)%2 == 0 ? false : true;
        if(!odd)
        {
            int mid1 , mid2;
            int cnt =  (m+n)/2+1;
            int i = 0, j= 0;
            while(i < m && j < n)
            {   
                if(cnt == 0)break;
                if(nums1[i]<=nums2[j])
                {
                    mid2 = mid1;
                    mid1 = nums1[i++];
                }
                else
                {
                    mid2 = mid1;
                    mid1 = nums2[j++];
                }
                cnt--;
            }
            while(i < m)
            {
                if(cnt == 0)break;
                mid2 = mid1;
                mid1 = nums1[i++];
                cnt--;
            }
            while(j < n)
            {
                if(cnt == 0)break;
                mid2 = mid1;
                mid1 = nums2[j++];
                cnt--;
            }
            return (mid1+mid2)/2.0;
        }
        else
        {
            int mid1;
            int cnt =  (m+n)/2+1;
            int i = 0, j= 0;
            while(i < m && j < n)
            {   
                if(cnt == 0)break;
                if(nums1[i]<=nums2[j])
                {
                    // mid2 = mid1;
                    mid1 = nums1[i++];
                }
                else
                {
                    // mid2 = mid1;
                    mid1 = nums2[j++];
                }
                cnt--;
            }
            while(i < m)
            {
                if(cnt == 0)break;
                // mid2 = mid1;
                mid1 = nums1[i++];
                cnt--;
            }
            while(j < n)
            {
                if(cnt == 0)break;
                // mid2 = mid1;
                mid1 = nums2[j++];
                cnt--;
            }
            // return (mid1+mid2)/2.0;
            return mid1;
        }
        return 0;
    }
};