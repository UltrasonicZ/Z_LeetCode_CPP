#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

class Solution {
public:
    vector<int> countBits(int num) {
	vector<int> result(num+1, 0);
      	for (int i = 0; i <= num; i++) {
	    int n = i;
	    int count = 0;
	    while (n) {
		++count;
		n = (n - 1) & n;
	    }
	    result[i] = count;
	}    
	return result;
    }
};
void Show(int);
int main() {
    Solution sol;
    vector<int> result;
    result = sol.countBits(10);
    for_each(result.begin(), result.end(), Show);
    std::cout << std::endl;
    return 0;
}

void Show(int v) {
    std::cout << v << ' ';
}
