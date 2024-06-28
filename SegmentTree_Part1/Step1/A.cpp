#include <bits/stdc++.h>

using namespace std;

struct segtree {
	int size;
	vector<long long> sums;
	void init(int n) {
		size = 1;
		while(size < n) size <<=1;
		sums.assign(2 * size, 0LL);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			sums[x] = v;
			return;
		}
		long long mid = lx + rx >> 1;
		if(i < mid) {
			set(i, v, 2*x + 1, lx, mid);
		} else {
			set(i, v, 2*x + 2, mid, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
	long long sum(int l, int r, int x, int lx, int rx) {
		if(rx <= l || lx >= r) return 0;
		if(lx >= l && rx <= r) return sums[x];
		long long mid = lx + rx >> 1;
		return sum(l, r, 2 * x + 1, lx, mid) +  sum(l, r, 2 * x + 2, mid, rx);
	}
	long long sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}
};

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	segtree st;
	st.init(n);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.set(i, x);
	}

	for(int i = 0; i < m; i++) {
		int op;
		cin >> op;
		if(op == 1) {
			int j, v;
			cin >> j >> v;
			st.set(j, v);
		} else {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << endl;
		}
	}
	return 0;
}