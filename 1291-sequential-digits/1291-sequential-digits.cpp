class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        string ls = to_string(low);
        string hs = to_string(high);
        int dl = ls.size();
        int dh = hs.size();
        vector<int>ans;
        for(int i = dl; i <= dh; i++)
        {
            for(int j = 0; j <= 9 - i; j++)
            {
                string n = s.substr(j,i);
                int num = stoi(n);
                if(low <= num && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};