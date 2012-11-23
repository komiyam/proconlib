// BEGIN CUT HERE
/*
 * Xorshiftによる疑似乱数生成器
 */
// END CUT HERE
struct Random {
	unsigned int x, y, z, w, t;

	unsigned int rand(){
		t = x ^ (x << 11);
		x = y; y = z; z = w;
		return w = ( (w ^ (w>>19)) ^ (t ^ (t>>8)));
	}

	//[0, n)
	int getInt(int n){
		return rand()%n;
	}

	//[from, to)
	int getInt(int from, int to){
		return rand()%(to - from) + from;
	}

	//[0, 1)
	double uniform(){
		return (double)rand() / (1LL<<32);
	}

	//[from, to)
	double uniform(double from, double to){
		return uniform()*(to - from) + from;
	}

	Random():x(123456789U), y(362436069U), z(521288629U), w(88675123U) {
		for (int _ = 0; _ < 538; ++_) {
			rand();
		}
	}

	Random(unsigned int w):x(123456789U), y(362436069U), z(521288629U), w(w) {
		for (int _ = 0; _ < 538; ++_) {
			rand();
		}
	}

};
