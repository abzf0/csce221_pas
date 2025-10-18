#include <vector>
#include <iostream>

using namespace std;

int find_max_value(const vector<int> & v, int ind = 0) {
	if(ind == v.size()-1) {
		return v[ind];
	}
	
	int max = find_max_value(v, ind + 1);
    
	if(v[ind] > max) {
		return v[ind];
	} else {
		return max;
	}
}