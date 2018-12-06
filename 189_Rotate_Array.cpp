#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums1 = nums;
        k = k % nums.size();
        for (int i = 0; i < nums.size(); ++i)
            nums[(i + k) % nums.size()] = nums1[i];
    }
};
void Show(int );

int main() {
    vector<int> nums{-1, -100, 3, 99};
    int k = 2;
    Solution sol;
    sol.rotate(nums, k);
    for_each(nums.begin(), nums.end(), Show);
    std::cout << std::endl;
    return 0;
}

void Show(int v) {
    std::cout << v << ' ';
}
