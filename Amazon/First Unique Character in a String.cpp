class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0);
        for(auto it:s)
        {
            freq[it-'a']++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(freq[s[i]-'a']==1)
            return i;
        }
        return -1;
        
    }
};
