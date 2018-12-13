#include "show.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(nums, 0, result);
        return result;
    }
    void helper(vector<int>& nums, int index, vector<vector<int>>& result) {
        if (index == nums.size() - 1) { 
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            int tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
            
            helper(nums, index + 1, result);            
            
            tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
        }   
    }
};

int main() {
    Solution sol;
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = sol.permute(nums);
    display2Dvector(result);
    return 0;
}
