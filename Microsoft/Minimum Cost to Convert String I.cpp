#define ll long long
class Solution {
public:
void flyodWarshall(vector<vector<ll>>&adj)
{
    for(int k=0;k<26;k++)
    {
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>adj(26,vector<ll>(26,INT_MAX));
        for(int i=0;i<original.size();i++)
        {
            int u=original[i]-'a';
            int v=changed[i]-'a';
            adj[u][v]=min(adj[u][v],(ll)cost[i]);
        }
        flyodWarshall(adj);

        ll cnt=0;
        for(int i=0;i<source.length();i++)
        {
            if(source[i]==target[i])
            continue;
            if(adj[source[i]-'a'][target[i]-'a']==INT_MAX)
            return -1;
            else
            cnt+=adj[source[i]-'a'][target[i]-'a'];
        }
        return cnt;
    }
};
