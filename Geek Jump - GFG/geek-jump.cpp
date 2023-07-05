//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // rec : minimum energy required to reach N from 0
    // Tabulation solution
    // Time complexity : O(n)
    // Space complexity : O(1)
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n,0);
        int prev = 0;
        int sprev = 0;
        
        for(int i=1;i<dp.size();i++){
            int l = prev + abs(height[i]-height[i-1]);
            int r = INT_MAX;
            if(i>1) r = sprev + abs(height[i]-height[i-2]);
            
            int curr = min(l,r);
            
            sprev = prev;
            prev = curr;
        }
        return prev;
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