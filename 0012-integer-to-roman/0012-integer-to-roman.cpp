class Solution {
public:
    string intToRoman(int num) {
        // unordered_map<int,char> val = {
        //     {1,'I'},
        //     {5,'V'},
        //     {10,'X'},
        //     {50,'L'},
        //     {100,'C'},
        //     {500,'D'},
        //     {1000,'M'}
        // };
        string ans = "";
        int m = num/1000;
        if(m == 3) ans += "MMM";
        if(m == 2) ans += "MM";
        if(m == 1) ans += "M";
        // int x = 100;
        num = num%1000;
        int d = num/100;
        // int h = 100*d;
        num =num%100;
        if(d == 9)
        {
            ans += "CM";
        }else if(d == 5)
        {
            ans += "D";
        }
        else if(d < 9 && d > 5)
        {
            int t = d - 5;
            if(t == 3) ans += "DCCC";
            if(t == 2) ans+="DCC";
            if(t == 1) ans+="DC";
        }
        else
        {
            int t = 5 - d;
            if(t == 4) ans+="C";
            if(t == 3) ans+="CC";
            if(t == 2) ans+="CCC";
            if(t == 1) ans+="CD";
        }
        d = num/10;
        // int h = 100*d;
        num = num%10;
        if(d == 9)
        {
            ans += "XC";
        }else if(d == 5)
        {
            ans += "L";
        }
        else if(d < 9 && d > 5)
        {
            int t = d - 5;
            if(t == 3) ans+="LXXX";
            if(t == 2) ans+="LXX";
            if(t == 1) ans+="LX";
        }
        else
        {
            int t = 5 - d;
            if(t == 4) ans+="X";
            if(t == 3) ans+="XX";
            if(t == 2) ans+="XXX";
            if(t == 1) ans+="XL";
        }
        int t = num;
        if(t == 1) ans+="I";
        if(t == 2) ans+="II";
        if(t == 3) ans+="III";
        if(t == 4) ans+="IV";
        if(t == 5) ans+="V";
        if(t == 6) ans+="VI";
        if(t == 7) ans+="VII";
        if(t == 8) ans+="VIII";
        if(t == 9) ans+="IX";
        return ans;
    }
};