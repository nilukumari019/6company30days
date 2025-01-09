//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& nums, int k) {
        // code here
        
        int n=nums.size();
        if(n<k)
        return {};
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<n;i++)
        {
            while(!dq.empty() && dq.front()<=i-k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[i]>nums[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i+1>=k)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
