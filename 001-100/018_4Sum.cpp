#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
   	vector<vector<int> > result;
	sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < n - 3; i++) {
	    for (int j = i + 1; j < n - 2; j++) {
		int k = j + 1;
		int l = n - 1;
		while (j < k && k < l) {
		    int nums_sum = nums[i] + nums[j] + nums[k] + nums[l];
		    if (nums_sum > target)
			--l;
		    else if (nums_sum < target)
			++k;
		    else {
			result.push_back(vector<int>{nums[i], nums[j], nums[k], nums[l]});
			--l;
			++k;
		    } 
		}
	    }
	}
    }
};

void Show(int);

int main() {

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int> > result;
    int target = 0;
    Solution sol;
//    result = sol.fourSum(nums, target);
    
    for (int i = 0; i < result.size(); i++) {
    	for_each(result[i].begin(), result[i].end(), Show);
    }
    return 0;
}

void Show(int v) {
    std::cout << v << ' ';
}
