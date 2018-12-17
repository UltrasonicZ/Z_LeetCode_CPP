#include <iostream>
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.size() < 1)
            return res;
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] < target)
                start = mid + 1;
            else
                end = mid;
        }
        if (nums[start] != target)
            return res;
        else
            res[0] = start;
        end = nums.size() - 1;
        while (start < end) {
            int mid = (start + end) / 2 + 1;
            if (nums[mid] > target)
                end = mid - 1;
            else
                start = mid;
        }
        res[1] = end;
        return res;
    }
};

int main() {
    Solution sol;
    vector<int > nums{5,7,7,8,8,10};
    vector<int > result = sol.searchRange(nums, 8);
    std::cout << result[0] << std::endl;
    std::cout << result[1] << std::endl;
    return 0;
}


