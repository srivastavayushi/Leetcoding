class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if(nums2.size()==0){
            return;
        }
        
        for(int i=0;i<m;i++){
            
            if(nums1[i]>nums2[0]){
                int temp = nums1[i];
                nums1[i]=nums2[0];
                nums2[0]=temp;
                sort(nums2.begin(),nums2.end());
            }
        }

        int index=0;
        for(int i=m;i<nums1.size();i++){
            nums1[i]=nums2[index];
            index++;
        }
    }
};