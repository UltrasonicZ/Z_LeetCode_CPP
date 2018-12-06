#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != val) 
                nums[j++] = nums[i];           
        return j;
    }
};

int main() {
    Solution sol;
    vector<int> nums{3, 2, 2, 3};
    int val = 2;
    std::cout << sol.removeElement(nums, val) << std::endl;
    return 0;
}
