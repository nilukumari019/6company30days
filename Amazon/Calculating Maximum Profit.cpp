class Solution {
public:
int n;
int solve(int idx,vector<int>&prices, int buy, int k,vector<vector<vector<int>>>&dp)
{
    if(idx==n || k==0)
    return 0;

    if(dp[idx][buy][k]!=-1)
    return dp[idx][buy][k];


    int profit=0;
    if(buy)
    profit=max(-prices[idx]+solve(idx+1,prices,0,k,dp),solve(idx+1,prices,1,k,dp));
    else
    profit=max(prices[idx]+solve(idx+1,prices,1,k-1,dp),solve(idx+1,prices,0,k,dp));

    return dp[idx][buy][k]= profit;
}
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,prices,1,k,dp);
    }
};
