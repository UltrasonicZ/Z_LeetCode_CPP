#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::reverse;
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        int storeIndex = 0, start = 0, i = 0;
        while (i < len) {
            while (s[i] == ' ')
                ++i;
            if (i >= len)
                break;
            if (start)
                s[storeIndex++] = ' ';
            while (s[i] != ' ' && i < len)
                s[storeIndex++] = s[i++];
//            reverse(s, start, storeIndex - 1);
            reverse(s.begin()+start, s.begin()+storeIndex);
            start = storeIndex + 1;
        }
        s.erase(storeIndex);
//        reverse(s, 0, storeIndex-1);

        reverse(s.begin(), s.begin()+storeIndex);
    }
//    void reverse(string &s, int start, int end) {
//        while (start < end) {
//            char tmp = s[start];
//            s[start++] = s[end];
//            s[end--] = tmp;
//        }
//    }
};
int main() {
    Solution sol;
    string s = "  a   ";
    std::cout << s << std::endl;
    sol.reverseWords(s);
    std::cout << s << std::endl;
    return 0;
}


