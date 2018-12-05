#include <iostream>
#include <cmath>
class Solution {
public:
    bool isPowerOfFour(int num) {
        return !(fmod(log10(num)/log10(4), 1));
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha <<sol.isPowerOfFour(256) << std::endl;
    return 0;
}
