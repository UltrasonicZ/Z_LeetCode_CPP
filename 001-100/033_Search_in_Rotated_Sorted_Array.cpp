#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    int search(vector<int>& nums, int target) {
	int n = nums.size();
	int low = 0, high = n - 1;
  	while (low < high) {
	    int mid = (low + high) / 2;
	    if (nums[mid] > nums[high])
		low = mid + 1;
	    else 
                high = mid;
	}	 
	int rot = low;
        low = 0; high = n - 1; 
	while (low <= high) {
	    int mid = (low + high) / 2;
	    int realmid = (mid + rot) % n;
	    if (nums[realmid] == target)
		return realmid;
            else if (nums[realmid] < target)
		low = mid + 1;
	    else
		high = mid - 1;
	}
	return -1;
    }
};

int main() {
    vector<int> nums1{4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    vector<int> nums2{4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    Solution sol;
    std::cout << sol.search(nums1, target1) << std::endl;
    std::cout << sol.search(nums2, target2) << std::endl;
    return 0;
}
