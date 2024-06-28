#include <bits/stdc++.h>

using namespace std;

struct segtree {
	int size;
	vector<pair<int, int>> mn;
	void init(int n) {
		size = 1;
		while(size < n) size <<=1;
		mn.assign(2 * size, {INT_MAX, 0});
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			mn[x] = {v,1};
			return;
		}
		int mid = lx + rx >> 1;
		if(i < mid) {
			set(i, v, 2*x + 1, lx, mid);
		} else {
			set(i, v, 2*x + 2, mid, rx);
		}
		if(mn[2*x + 1].first < mn[2*x +2].first) mn[x] = mn[2*x + 1];
		else if(mn[2*x + 1].first > mn[2*x +2].first) mn[x] = mn[2*x + 2];
		else mn[x] = {mn[2*x+1].first, mn[2*x+1].second + mn[2*x+2].second};
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	pair<int,int> minimum(int l, int r, int x, int lx, int rx) {
		if(rx <= l || lx >= r) return {INT_MAX, 0};
		if(lx >= l && rx <= r) return mn[x];
		int mid = lx + rx >> 1;
		auto p1 = minimum(l, r, 2 * x + 1, lx, mid);
		auto p2 =  minimum(l, r, 2 * x + 2, mid, rx);
		if(p1.first == p2.first) return {p1.first, p1.second + p2.second};
		if(p1.first < p2.first) return p1;
		return p2;
	}
	pair<int, int> minimum(int l, int r) {
		return minimum(l, r, 0, 0, size);
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
			auto p = st.minimum(l, r);
			cout << p.first<< ' ' << p.second << endl;
		}
	}
	return 0;
}