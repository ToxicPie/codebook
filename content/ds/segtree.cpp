template<typename T> struct tree {
	static const T ID; // identity element
	T f(T, T);  // associative operator
	int n;
	vector<T> v;
	tree(vector<T> &a) : n(a.size()), v(2 * n, ID) {
		copy_n(a.begin(), n, v.begin() + n);
		for(int i = n - 1; i > 0; i--)
			v[i] = f(v[i << 1], v[i << 1 | 1]);
	}
	void update(int pos, T val) {
		for(v[pos += n] = val; pos > 1; pos >>= 1)
			v[pos >> 1] = f(v[pos & -2], v[(pos & -2) ^ 1]);
	}
	T query(int l, int r) {
		T tl = ID, tr = ID;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l & 1) tl = f(tl, v[l++]);
			if(r & 1) tr = f(v[--r], tr);
		}
		return f(tl, tr);
	}
};
