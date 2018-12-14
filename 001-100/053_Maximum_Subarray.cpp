#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = 0x80000000;
        int cursum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (cursum <= 0)
                cursum = nums[i];
            else
                cursum += nums[i];
            
            if (cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};

int main() {
    Solution sol;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << sol.maxSubArray(nums)<< std::endl;
    return 0;
}
