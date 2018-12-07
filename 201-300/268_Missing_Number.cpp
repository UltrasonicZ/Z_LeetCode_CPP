#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i = 0;
        for(int num : nums) {
            result ^= num;
            result ^= i;
            ++i;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int result = 0;
    vector<int> nums{9, 6, 4, 2, 3, 5, 7, 0, 1};
    result = sol.missingNumber(nums);
    std::cout << result << std::endl;
    return 0;
}
