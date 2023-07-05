//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // rec : minimum energy required to reach N from 0
    int rec(vector<int>&height, int idx, vector<int>&dp){
        if(idx==0) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int l = rec(height, idx-1,dp) + abs(height[idx]-height[idx-1]);
        int r = INT_MAX;
        // (idx-2) can only be accessed if idx>1
        if(idx>1){
            r = rec(height, idx-2,dp) + abs(height[idx]-height[idx-2]);
        }
        return dp[idx] = min(l,r);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n,-1);
        return rec(height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends