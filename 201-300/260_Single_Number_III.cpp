#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int val = 0;
        for (auto n : nums)
            val ^= n;
        int diff = (val & (-val));
        vector<int> res(2, 0);
        for (auto n : nums)
            if (n & diff)
                res[0] ^= n;
            else
                res[1] ^= n;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int > nums{1,2,1,3,2,5};
    vector<int > res = sol.singleNumber(nums);
    std::cout << res[0] << std::endl;
    std::cout << res[1] << std::endl;
    return 0;
}
