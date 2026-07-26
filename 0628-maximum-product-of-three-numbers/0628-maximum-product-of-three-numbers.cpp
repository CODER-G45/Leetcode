class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int fst1 = INT_MAX, sec1 = INT_MAX, trd1 = INT_MIN;
        int fst2 = INT_MIN, sec2 = INT_MIN, trd2 = INT_MIN;
        int fst3 = INT_MIN, sec3 = INT_MIN, trd3 = INT_MIN;

        int negCnt = 0;

        for (int num : nums) {

            if (num < 0) {
                negCnt++;

                // two smallest negatives
                if (num < fst1) {
                    sec1 = fst1;
                    fst1 = num;
                } else if (num < sec1) {
                    sec1 = num;
                }

                // three largest negatives (closest to zero)
                if (num > fst3) {
                    trd3 = sec3;
                    sec3 = fst3;
                    fst3 = num;
                } else if (num > sec3) {
                    trd3 = sec3;
                    sec3 = num;
                } else if (num > trd3) {
                    trd3 = num;
                }
            }

            // largest element
            if (num > trd1)
                trd1 = num;

            // three largest numbers
            if (num > fst2) {
                trd2 = sec2;
                sec2 = fst2;
                fst2 = num;
            } else if (num > sec2) {
                trd2 = sec2;
                sec2 = num;
            } else if (num > trd2) {
                trd2 = num;
            }
        }

        int ans1 = INT_MIN, ans2 = INT_MIN, ans3 = INT_MIN;

        if (negCnt >= 2)
            ans1 = fst1 * sec1 * trd1;

        ans2 = fst2 * sec2 * trd2;

        if (negCnt >= 3)
            ans3 = fst3 * sec3 * trd3;

        return max({ans1, ans2, ans3});
    }
};