/*
#include <psuedocode.Orz>
*/

void fill_random_int(vector<int>& v, int cnt) {
	v.clear();
	for(int i = 0; i < cnt; i++)
		v.push_back(rand());
}

void test_sort(vector<int>& v) {
	sort(v.begin(), v.end());
	for(int i = 0;i < v.size() - 1;i++)
		assert(v[i] <= v[i+1]);
}