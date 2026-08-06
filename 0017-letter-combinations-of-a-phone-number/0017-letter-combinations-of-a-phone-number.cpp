class Solution {
public:
    unordered_map<char, string> key = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void solve(int idx ,string& digits ,string& cur , vector<string>&ans)
    {
        if(idx == digits.size())
        {
            ans.push_back(cur);
        }
        for(char c : key[digits[idx]])
        {
            cur.push_back(c);
            solve(idx+1,digits,cur,ans);
            cur.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string cur = "";
        solve(0,digits,cur,ans);
        return ans;
    }
};