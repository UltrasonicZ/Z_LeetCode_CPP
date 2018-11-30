#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     	vector<vector<int>> result;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n - 2; ++i) {
	    int j = i + 1;
	    int k = n - 1;
	    while (j < k) {
	        int nums_sum = nums[i] + nums[j] + nums[k]; 
		if (nums_sum < 0) ++j; 
		else if (nums_sum > 0) --k;
		else {
		    result.push_back(vector<int>{nums[i], nums[j], nums[k]});
		    ++j;
		    --k;
                    while (nums[j] == nums[j - 1] && j < k) ++j;
		    while (nums[k] == nums[k + 1] && j < k) --k;
	        }		   
	    }
	}
    }
};
void Show(int);

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result;

    Solution sol;
    result = sol.threeSum(nums);
    for (int i = 0; i < result.size(); ++i) { 
	for_each(result[i].begin(), result[i].end(), Show);
        std::cout << std::endl;
    }
    return 0;
}

void Show(int v) {
    std::cout << v << ' ';
}
