//the most naive solution to add two vectors

#include <bits/stdc++.h>
using namespace std;

struct Vec {
	int len
	float *v;
	Vec(int len) : len(len) {
		v = new float[len];
	}
	Vec(const Vec& x) : len(src.len) {
		v = new float[len];
		memcpy(v, x.v, sizeof(float)*len);
	}
	inline Vec operator+(const Vec&x, const Vec&y) {
		assert(x.len == y.len);
		Vec res(x.len);
		for(int i = 0; i < len; i++) 
			res[i] = x[i] + y[i];
		return res;
	}
	~Vec(void) {
		delete [] v;
	} 
};

int main() {

	Vec x(5), y(5);
	x[0] = 0;
	x[1] = 1;
	x[2] = 2;
	x[3] = 3;
	x[4] = 4;
	y[0] = 5;
	y[1] = 6;
	y[2] = 7;
	y[3] = 8;
	y[4] = 9;
	Vec z = x + y;

	for(int i = 0; i < 5; i++) {
		cout << x[i] << '+' << y[i] << '=' << z[i] << endl;
	}
	return 0;
}
