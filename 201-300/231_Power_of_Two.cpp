#include <iostream>
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha <<sol.isPowerOfTwo(32) << std::endl;
    return 0;
}
