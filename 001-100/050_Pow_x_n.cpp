#include <iostream>
#include <cmath>

//class Solution {
//public:
//    double myPow(double x, int n) {
//        if (fabs(x) < 0.0000001)
//            return 0.0;
//        double result = 1.0;
//        for (int i = 0; i < abs(n); ++i)
//            result *= x;
//        if (n < 0)
//            result = 1.0 / result;
//        return result;
//    }
//};

//class Solution {
//public:
//    double myPow(double x, int n) {
//        if (fabs(x) < 0.0000001)
//            return 0.0;
//	int absn = n < 0 ? -n: n;
//        double result = myPowWithUnsignedExponent(x, absn);
//        if (n < 0)
//            result = 1.0 / result;
//        return result;
//   }
//    
//    double myPowWithUnsignedExponent(double x, int n) {
//        if (n == 0) return 1;
//        if (n == 1) return x;
//        double result = myPow(x, n >> 1);
//        result *= result;
//       if (n & 0x1 == 1)
//            result *= x;
//        return result;
//    }
//};

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) 
            return 1;
        if (n < 0) {
            if (n == -2147483648) return 1 / (x * myPow(x, 2147483647));
            n = -n;
            x = 1 / x;
        }
        return (n & 0x1) ? x*myPow(x*x, n >> 1): myPow(x*x, n >> 1);
    }
};
int main() {
    Solution sol;
    
    std::cout << sol.myPow(2.0, -2147483648) << std::endl;
    return 0;
}
