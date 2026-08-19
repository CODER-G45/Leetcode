class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> seat;
        for(auto &x : reservedSeats) {
            int r = x[0];
            int c = x[1];
            seat[r].push_back(c);
        }
        int ans = (n - seat.size()) * 2;
        for(auto &[row, v] : seat) {
            vector<int> s(10, 0);
            for(int col : v)
                s[col - 1] = 1;
            bool f = false;
            bool c = false;
            bool l = false;
            if(s[1] == 0 && s[2] == 0 && s[3] == 0 && s[4] == 0)
                f = true;
            if(s[3] == 0 && s[4] == 0 && s[5] == 0 && s[6] == 0)
                c = true;

            if(s[5] == 0 && s[6] == 0 && s[7] == 0 && s[8] == 0)
                l = true;
            if(f && l)
                ans += 2;
            else if(f || c || l)
                ans++;
        }
        return ans;
    }
};