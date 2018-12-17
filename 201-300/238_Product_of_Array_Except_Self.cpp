#include <iostream>
#include <vector>
#include "show.h"
using std::vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums);
        result[0] = 1;
        for (int i = 1; i < nums.size(); ++i)
            result[i] = nums[i - 1] * result[i - 1];
        int tmp = 1;
        for (int i = nums.size() - 1; i > 0; --i) {
            tmp *= nums[i];
            result[i - 1] *= tmp;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int > nums{2, 3, 4, 5};
    vector<int > result = sol.productExceptSelf(nums);
    display1Dvector(result);
    return 0;
}

