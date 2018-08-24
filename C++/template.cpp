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

template <typename T>

struct Point {
	T x, y;
	Point(T x=0, T y=0):x(x), y(y) {}//x(x) stands this.x = x;
};

Point<T> operator + (const Point<T>& A, const Point<T>& B) {
	return Point<T>(A.x+B.x, A.y+B.y);
}

ostream& operator << (ostream &out, const Point<T>& P) {
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

T sum(T* begin, T* end) {
	T *p = begin;
	T ans = 0;
	for(T *p = begin; p != end;p++)
		ans = ans + *p;
	return ans;
}

int main() {
	Point<int> a(1,2), b(3,4);
	Point<double> c(1.1,2.2), d(3.3, 4.4);
	cout << a+b << "" << c+d << "\n";
	return 0;
}

