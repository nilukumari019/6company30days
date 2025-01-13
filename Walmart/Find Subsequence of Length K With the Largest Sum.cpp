class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({nums[i],i});
        }
        sort(arr.rbegin(),arr.rend());

        vector<pair<int,int>>topK(arr.begin(),arr.begin()+k);

        sort(topK.begin(),topK.end(),[](pair<int,int>&a,pair<int,int>&b){
            return a.second<b.second;
        });

        vector<int>ans;
        for(auto it:topK)
        ans.push_back(it.first);
        return ans;

    }
};
