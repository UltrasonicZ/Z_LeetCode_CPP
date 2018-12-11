#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void display2Dvector(vector<vector<int> > result) {
    for (int i = 0; i < result.size(); ++i) {
 	for (int j = 0; j < result[i].size(); ++j)
	    cout << result[i][j] << '\t';
        cout << endl;
    }
}

void display2Dvector(vector<int> result) {
    for (int i = 0; i < result.size(); ++i)
	cout << result[i] << '\t';
    cout << endl;
}
