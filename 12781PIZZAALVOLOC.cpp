#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct vector2 {
	double x, y;
	vector2() {
		x = 0, y = 0;
	}
	vector2(double _x, double _y) {
		x = _x, y = _y;
	}
	//¿ÜÀû
	double cross(const vector2& other) const {
		return x*other.y - y*other.x;
	}
	vector2 operator - (vector2 other) const {
		return vector2(x - other.x, y - other.y);
	}
	bool operator < (vector2 other) const {
		return x < other.x && y < other.y;
	}
};
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}
bool sementlntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c)*ccw(a, b, d);
	double cd = ccw(c, d, a)*ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}
int main() {
	vector2 arr[4];
	for (int i = 0; i < 4; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i] = vector2(x, y);
	}
	if (sementlntersects(arr[0], arr[1], arr[2], arr[3])) puts("1");
	else puts("0");

	return 0;
}