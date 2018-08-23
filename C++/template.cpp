/*
int sum(int* begin, int* end) {
	int *begin;
	int ans = 0;
	for(int *p = begin; p!= end;p++) {
		ans += *p;
	}
	return ans;
}
*/

template<typename T>
T sum(T* begin, T* end) {
	T *p = begin;
	T ans = 0;
	for(T *p = begin; p != end;p++)
		ans = ans + *p;
	return ans;
}

int main() {
	double a[] = {1.1, 2.2, 3.3, 4.4};
	cout << sum(a, a+4) << "\n";
	Point b[] = {Point(1,2), Point(3,4), Point(5,6), Point(7,8) };
	cout << sum(b, b+4) << "\n";
}