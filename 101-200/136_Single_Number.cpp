#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
            res ^= *it;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums{1, 1, 2, 3, 3, 4, 4};
    std::cout << sol.singleNumber(nums) << std::endl;
    return 0;
}
