class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=1;
        int j=n-1;
        vector<int>v(n);
        while(i<n)
        {
            v[i]=nums[j];
            i+=2;
            j--;
        }
        i=0;
        while(i<n)
        {
            v[i]=nums[j];
            i+=2;
            j--;
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=v[i];
        }
    }
};
