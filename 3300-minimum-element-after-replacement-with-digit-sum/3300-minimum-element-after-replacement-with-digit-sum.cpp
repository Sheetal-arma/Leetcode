class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int num:nums){
            int sum=0;
            while(num){
                sum += (num%10);
                num /= 10;
            }
            ans.push_back(sum);
        }
        return *min_element(ans.begin(), ans.end());
    }
};