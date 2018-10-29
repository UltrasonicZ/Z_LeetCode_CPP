#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); i++) {
            int numberToFind = target - numbers[i];
            //if numberToFind is found in map, return them
            if (hash.find(numberToFind) != hash.end()) {
                //+1 because indices are NOT zero based
                result.push_back(hash[numberToFind] + 1);
                result.push_back(i + 1);
                return result;
            }
            //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> a;
//        for(int i = 0; i < nums.size(); i++){
//            for(int j = i + 1; j < nums.size(); j++)
//                if(nums[j] == target - nums[i]) {
//                    a.push_back(i);
//                    a.push_back(j);
//                    return a;
//                }
//        }
//    }
};

//int main()
//{
//    Solution sol;
//    vector<int> abb;
//    abb.push_back(1);
//    abb.push_back(2);
//    abb.push_back(3);
//    abb.push_back(4);
//
//    int ac = 6;
//
//    cout << sol.twoSum(abb, ac).front() << endl;
//    cout << sol.twoSum(abb, ac).back() << endl;
//
//    return 0;
//}
//int main()
//{
//    Solution ts;
//    int a[4] = {2, 7, 11, 15};
//    vector<int> v(a, a+4);
//    for(int i = 0; i < 4; i++){
//        cout << v[i] << endl;
//    }
//    cout<<ts.twoSum(v, 9)<<endl;
//    while(1);
//    return 0;


//}
//
// Created by gz on 18-10-26.
//

