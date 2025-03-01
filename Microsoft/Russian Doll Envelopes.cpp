class Solution {
public:
static bool cmp(vector<int>&a,vector<int>&b)
{
    if(a[0]==b[0])
    {
        return a[1]>b[1];
    }
    return a[0]<b[0];
}
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        sort(env.begin(),env.end(),cmp);
        vector<int>lis;
        for(int i=0;i<n;i++)
        {
            int idx=lower_bound(lis.begin(),lis.end(),env[i][1])-lis.begin();
            if(idx>=lis.size())
            lis.push_back(env[i][1]);
            else
            lis[idx]=env[i][1];
        }
        return lis.size();
    }
};
