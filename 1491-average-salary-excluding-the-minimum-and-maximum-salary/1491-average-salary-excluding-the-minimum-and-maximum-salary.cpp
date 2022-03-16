class Solution {
public:
    double average(vector<int>& salary) {
        
        int max_salary = INT_MIN;
        int min_salary = INT_MAX;
        
        int total = 0;
        
        for(int i=0;i<salary.size();i++){
            max_salary = (salary[i]>max_salary) ? salary[i] : max_salary;
            min_salary = (salary[i]<min_salary) ? salary[i] : min_salary;
            total += salary[i];
        }
        
        total = total - (max_salary+min_salary);
        double res = double(total)/double(salary.size()-2);
        
        return res;
        
    }
};