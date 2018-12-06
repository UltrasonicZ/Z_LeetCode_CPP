#include <iostream>
#include <vector>
using std::vector;
using std::swap;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
	while (true) {
	    int p = partition(nums, left, right);
	    if (p == k - 1) return nums[p];
	    else if (p > k - 1) right = p - 1;
	    else left = p + 1;
	}
    }
    int partition(vector<int>& nums, int left, int right) {
      	int pivot = nums[left], l = left + 1, r = right;
	while (l <= r) {
	    if (nums[l] < pivot && nums[r] > pivot) swap(nums[l++], nums[r--]);
	    if (nums[l] >= pivot) l++;
	    if (nums[r] <= pivot) r--;
	}
	swap(nums[left], nums[r]);
	return r;
    }
};

int main() {
    vector<int> nums{4, 6, 3, 5, 2, 1};
    int k = 2;
    Solution sol;
    std::cout << sol.findKthLargest(nums, k) << std::endl;
    return 0;
}
