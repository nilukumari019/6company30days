//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<string>> bracket(n, vector<string>(n));
    
        // Initialize the matrix names
        char matrixName = 'A';
        for (int i = 1; i < n; ++i) {
            bracket[i][i] = string(1, matrixName++);
        }
    
        for (int len = 2; len < n; ++len) {
            for (int i = 1; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
    
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        bracket[i][j] = "(" + bracket[i][k] + bracket[k + 1][j] + ")";
                    }
                }
            }
        }
    
        return bracket[1][n - 1];
    }
};

//{ Driver Code Starts.

int get(vector<int> &p, int n) {
    int m[n][n], ans = 1e9;
    for (int i = 1; i < n; i++)
        m[i][i] = 0;
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            m[i][i + L - 1] = INT_MAX;
            for (int k = i; k <= i + L - 2; k++) {
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i - 1] * p[k] * p[i + L - 1];
                if (q < m[i][i + L - 1]) {
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int find(string s, vector<int> &p) {
    vector<pair<int, int>> arr;
    int ans = 0;
    for (auto t : s) {
        if (t == '(') {
            arr.push_back({-1, -1});
        } else if (t == ')') {
            pair<int, int> b = arr.back();
            arr.pop_back();
            pair<int, int> a = arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first, b.second});
            ans += a.first * a.second * b.second;
        } else {
            arr.push_back({p[int(t - 'A')], p[int(t - 'A') + 1]});
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> p;
        int x;
        while (ss >> x) {
            p.push_back(x);
        }
        Solution ob;
        string result = ob.matrixChainOrder(p);
        if (find(result, p) == get(p, p.size())) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
// } Driver Code Ends
