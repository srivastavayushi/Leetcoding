// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<bool>>dp(arr.size()+1,vector<bool>(sum+1));
        
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true;
            }
        }
        
        
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[arr.size()][sum];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends