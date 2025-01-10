class Solution {
public:
int niceSubArray_lessthan_k(vector<int>&nums,int k)
{
    int n=nums.size();
    int i=0,j=0;
    int cnt=0;
    int sum=0;
    while(j<n)
    {
        sum+=nums[j];
        while(sum>k)
        {
            sum-=nums[i];
            i++;
        }

        cnt+=(j-i+1);
        j++;
    }
    return cnt;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=nums[i]%2;
        }
        return niceSubArray_lessthan_k(nums,k)-niceSubArray_lessthan_k(nums,k-1);
    }
};
