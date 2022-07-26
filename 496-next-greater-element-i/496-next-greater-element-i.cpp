class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        stack<int>st;
        vector<int> res;
        
        for(int i=nums2.size()-1;i>=0;i--){
            if(st.empty()) mpp[nums2[i]] = -1;
            else if(st.top()>nums2[i]) mpp[nums2[i]] = st.top();
            else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                if(st.empty()) mpp[nums2[i]] = -1;
                else mpp[nums2[i]] = st.top();
                
                }
                st.push(nums2[i]);
            }
        
        for(auto it:nums1) res.push_back(mpp[it]);
        
        return res;
        
    }
};