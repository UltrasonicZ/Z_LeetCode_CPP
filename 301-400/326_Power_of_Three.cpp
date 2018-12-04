#include <iostream>
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && !(1162261467 % n);
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha <<sol.isPowerOfThree(27) << std::endl;
    return 0;
}
