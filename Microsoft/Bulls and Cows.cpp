class Solution {
public:
    string getHint(string secret, string guess) {
        int n=guess.length();
        int bull=0;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                bull++;
                secret[i]='$';
                guess[i]='$';
            }
        }

        vector<int>g(10,0);
        vector<int>s(10,0);
        for(int i=0;i<n;i++)
        {
            if(guess[i]=='$')
            continue;
            else
            g[guess[i]-'0']++;
        }
        for(int i=0;i<n;i++)
        {
            if(secret[i]=='$')
            continue;
            else
            s[secret[i]-'0']++;
        }

        int cow=0;
        for(int i=0;i<10;i++)
        {
            if(g[i]!=0 && g[i]<=s[i])
            cow+=g[i];
            else if(g[i]>s[i])
            cow+=s[i];
        }
        return to_string(bull)+"A"+to_string(cow)+"B";
    }
};
