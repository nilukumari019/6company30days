class Solution {
public:
int solve(int i, int j, vector<int>& nums)
{
    unordered_map<int,int>mp;
    int sum=0;
    for(int k=i;k<j;k++)
    {
        mp[nums[k]]++;
        if(mp[nums[k]]>1)
        return 0;
        else
        sum+=nums[k];
    }
    return sum;
}
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long int maxi=0;
        int i=0,j=0;
        long long int sum=0;
        unordered_set<int>st;
        while(j<n)
        {
            while(st.count(nums[j]))
            {
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            sum+=nums[j];
            st.insert(nums[j]);
            if(j-i+1==k)
            {
                maxi=max(maxi,sum);
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
            
        }
        return maxi;
            
    }
};
