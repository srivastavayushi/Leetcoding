//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    // maximumPoints : Returns maximum merit points that geek can get if he starts training from day 0 to int "day" (mentioned in parameter)
    int maximumPoints(vector<vector<int>>&points, int day, int last_task, vector<vector<int>>&dp){
        if(day == 0){
            int maxi = INT_MIN;
            for(int i=0; i<3;i++){
                // dont include the task done at last day
                if(i != last_task) maxi = max(maxi, points[0][i]);
            }
            return maxi;
        }
        
        if(dp[day][last_task] != -1) return dp[day][last_task];
        
        int maxi = INT_MIN;
        
        for(int i=0;i<3;i++){
            if(i != last_task){
                // total points till now = points earned by doing ith task on day + maximum points earned till now
                int point = points[day][i] + maximumPoints(points,day-1,i,dp);
                maxi = max(maxi,point);
            }
        }
        
        return dp[day][last_task] = maxi;
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return maximumPoints(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends