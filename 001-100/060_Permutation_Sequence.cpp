#include <iostream>
#include <string>
using std::string;
class Solution {
public:
    string getPermutation(int n, int k) {
        string nums(n, '0');
        int total = 1;
        for (int i = 1; i <= n; ++i) { 
            total *= i;
            nums[i - 1] += i;
        }
        --k;
        for (int i = 0; i < n; ++i) {
            total /= n - i;
            int j = i + k / total;
            char ch = nums[j];
            for (; j > i; --j)
                nums[j] = nums[j - 1];
            nums[i] = ch;
            k %= total;
        }
        return nums;
    }
};

int main() {
    Solution sol;
    std::cout << sol.getPermutation(4, 9) << std::endl;
    return 0;
}
