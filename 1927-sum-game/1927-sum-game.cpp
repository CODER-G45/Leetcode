class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int leftQ = 0 ,rightQ = 0;
        int leftSum = 0,rightSum = 0;
        for(int i = 0; i < n/2;i++)
        {
            if(num[i] == '?')leftQ++;
            else leftSum += num[i] - '0';
        }
        for(int i = n/2; i < n ;i++)
        {
            if(num[i] == '?')rightQ++;
            else rightSum += num[i] - '0';
        }
        int totalQ = leftQ + rightQ;
        if(totalQ % 2 == 1) return true;//hint 1
        if(totalQ == 0 || leftQ == rightQ) return leftSum != rightSum;//hint 2 & 3
        // if(abs(leftQ - rightQ) % 2 == 0)//hint 4
        // {
        //     if(leftQ > rightQ) return leftSum - rightSum != 9;
        //     else return rightSum - leftSum  != 9;
        // }
        return leftSum - rightSum != (rightQ - leftQ)*9/2;
    }
};