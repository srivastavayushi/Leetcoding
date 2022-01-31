class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = INT_MIN;
        
        for(int i=0;i<accounts.size();i++){
            int sum=0;
            for(int j=0;j<accounts[i].size();j++){
                sum=sum+accounts[i][j]; 
            }
            if(sum>res){
                res=sum;
            }
        }
        
        return res;
    }
};