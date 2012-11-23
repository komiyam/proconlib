template<typename T>
void shuffle(T first, T last, Random& rnd) {
	const int n = last - first;
	for (int i = 0; i < n - 1; ++i) {
		int j = rnd.getInt(i, n);
		swap(first[i], first[j]);
	}
}
