template<typename T>
void shuffle(vector<T>& xs, Random& rnd) {
	const int n = xs.size();
	for (int i = 0; i < n - 1; ++i) {
		int j = rnd.getInt(i, n);
		swap(xs[i], xs[j]);
	}
}
