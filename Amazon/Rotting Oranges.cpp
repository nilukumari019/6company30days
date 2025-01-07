class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int, int>,int>>q;
        int tmax=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            tmax=max(tmax,time);
            int drow[4]={-1,0,+1,0};
            int dcol[4]={0,+1,0,-1};
            for(int i=0;i<4;i++)
            {
                int delrow=row+drow[i];
                int delcol=col+dcol[i];
                if(delrow>=0 && delrow<n && delcol>=0 && delcol<m && grid[delrow][delcol]==1 && vis[delrow][delcol]!=2)
                {
                    q.push({{delrow,delcol},time+1});
                    vis[delrow][delcol]=2;
                }
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2)
                return -1;
            }
        }
        return tmax;
    }
};
