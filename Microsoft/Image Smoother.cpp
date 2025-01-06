class Solution {
public:
int n,m;
int solve(int i,int j,vector<vector<int>>& img)
{
    // int dx={-1,0,1,1,1,0,-1,-1,0};
    // int dy={1,1,1,0,-1,-1,-1,0,0};
    int temp=0;
    int cnt=0;
    // top
    if(i-1>=0)
    {
        temp+=img[i-1][j];
        cnt++;
    }
    //right
    if(j+1<m)
    {
        temp+=img[i][j+1];
        cnt++;
    }
    //bottom
    if(i+1<n)
    {
        temp+=img[i+1][j];
        cnt++;
    }

    //left
    if(j-1>=0)
    {
        temp+=img[i][j-1];
        cnt++;
    }
    //upper left diag
    if(i-1>=0 && j-1>=0)
    {
        temp+=img[i-1][j-1];
        cnt++;
    }
    // upper right diag
    if(i-1>=0 && j+1<m)
    {
        temp+=img[i-1][j+1];
        cnt++;
    }
    //lower right diag
    if(i+1<n && j+1<m)
    {
        temp+=img[i+1][j+1];
        cnt++;
    }
    //lower left diag
    if(i+1<n && j-1>=0)
    {
        temp+=img[i+1][j-1];
        cnt++;
    }

    temp+=img[i][j];
    cnt++;

    return temp/cnt;


}
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        n=img.size();
        m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int cal=solve(i,j,img);
                ans[i][j]=cal;
            }
        }
        return ans;
    }
};
