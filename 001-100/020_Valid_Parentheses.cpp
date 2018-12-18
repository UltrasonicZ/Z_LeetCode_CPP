#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using std::stack;
using std::unordered_map;
using std::string;
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> hash;
        hash[')'] = '(';
        hash[']'] = '[';
        hash['}'] = '{';
        stack<char> myStack;
        myStack.push(NULL);
        for (int i = 0; i < s.length(); ++i) {
            if (hash.find(s[i]) == hash.end())
                myStack.push(s[i]);
            else {
                char ch = myStack.top();
                myStack.pop();
                if (hash[s[i]] != ch)
                    return false;
            }
        }
        if (myStack.top() == NULL)
            return true;
        else
            return false;
    }
};

int main() {
    Solution sol;
    string s = "{[]}()";
    std::cout << std::boolalpha << sol.isValid(s) << std::endl;
    return 0;
}
