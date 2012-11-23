// BEGIN CUT HERE
/*
 * バイナリ法によりx^nを求める
 * modの値が大きいときはオーバーフローが起きうるので注意
 *
 * @param x
 * @param n
 * @param mod
 * @return : (x^n) % mod
 *
 * 計算量: O(log n)
 * verify:
 *
 */
// END CUT HERE
int64 calcPow(int64 x, int64 n, int64 mod = MOD) {
	DEBUGASSERT(n >= 0, n);
	int64 ret = 1;
	for (; n; n >>= 1, x = x * x % mod) if (n&1) {
		ret = ret * x % mod;
	}
	return ret;
}
