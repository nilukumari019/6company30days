class Solution {
public:
    string convertToTitle(int colNum) {
        string ans="";
        while(colNum)
        {
            colNum--;
            int n=colNum%26;
            char ch='A'+n;
            ans+=ch;
            colNum/=26;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
