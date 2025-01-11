class Solution {
public:
unordered_map<string,int>mp;
int solve(int idx,int k, int flag,int jump)
{
    if(idx>k+1)
    return 0;

    string key=to_string(idx)+"-"+to_string(flag)+"-"+to_string(jump);
    if(mp.find(key)!=mp.end())
    return mp[key];

    int ways=0;
    if(idx==k)
    ways++;

    if(flag==1)
    ways+=solve(idx-1,k,0,jump);

    ways+=solve((idx+pow(2,jump)),k,1,jump+1);

    return mp[key]= ways;
}
    int waysToReachStair(int k) {

       return  solve(1,k,1,0);
        
    }
};
