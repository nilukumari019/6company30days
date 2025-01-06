class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
        return 0;
        int ans=0;
        int start=-1, end=-1;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]>arr[i])
            {
                if( end!=-1)
                {
                    start=-1;
                    end=-1;
                }
                if(start==-1)
                start=i;
            }else  if(arr[i+1]<arr[i])
            {
                 if(start!=-1)
                    {
                         end=i+1;
                       ans=max(ans,end-start+1);
                    }
                      
            }
            else if(arr[i]==arr[i+1])
            {
                start=-1;
                end=-1;
            }


        }
        return ans;
    }
};
