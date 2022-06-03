class NumArray {
private:
    vector<int> m;
public:
    NumArray(vector<int>& nums) : m(nums) {
        for(int i=1;i<m.size();i++){
            m[i] += m[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return m[right];
        return m[right] - m[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */