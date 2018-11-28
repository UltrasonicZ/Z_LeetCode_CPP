#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int index = m + n - 1;
 	int i = m - 1;
	int j = n - 1;
 	while (i >= 0 && j >= 0)
	    if (nums1[i] >= nums2[j]) 
		nums1[index--] = nums1[i--];
	    else
		nums1[index--] = nums2[j--];
	while (j >= 0)
       	    nums1[index--] = nums2[j--];
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;

    sol.merge(nums1, m, nums2, n);
    ostream_iterator<int, char> out_iter (cout, " ");
    copy(nums1.begin(), nums1.end(), out_iter);
    cout << endl;
   
    return 0;
}
