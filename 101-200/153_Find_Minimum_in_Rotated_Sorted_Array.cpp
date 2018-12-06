#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }
        return nums[low];
    }
};

int main() {
    Solution sol;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    std::cout << sol.findMin(nums) << std::endl;
    return 0;
}
