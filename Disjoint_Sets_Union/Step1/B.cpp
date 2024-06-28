/* (B) Disjoint Sets Union 2 */

#include <bits/stdc++.h>

using namespace std;
struct info {
	int size;
	int mn;
	int mx;		
};
class disjoint_set {
  vector<int> sets;
  vector<struct info> meta;
  
  int root(int a) {
  	while(a != sets[a]) {
  		sets[a] = sets[sets[a]];
  		a = sets[a];
  	}
  	return a;
  }
public:
	disjoint_set (int n) {
		sets.resize(n+1);
		meta.resize(n+1);
		for(int i = 0; i <= n; i++) {
			sets[i] = i;
			meta[i] = {1, i, i};
		}
	}

	void unify(int a, int b) {
		int i = root(a);
		int j = root(b);
		if(i == j) return;
		if(meta[i].size > meta[j].size) { 
			sets[j] = i; 
			meta[i].size += meta[j].size;
			meta[i].mx = max(meta[i].mx, meta[j].mx ); 
			meta[i].mn = min(meta[i].mn, meta[j].mn ); 
		}
		else { 
			sets[i] = j; 
			meta[j].size += meta[i].size;
			meta[j].mx = max(meta[i].mx, meta[j].mx ); 
			meta[j].mn = min(meta[i].mn, meta[j].mn );
		}
	}

	void get (int a) {
		a = root(a);
		cout << meta[a].mn << ' ' << meta[a].mx << ' ' << meta[a].size << '\n';
	}
  
};

int main() {
	std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  disjoint_set dsu(n);
  while(m--) {
  	string s;
  	cin >> s;
  	int a, b;
  	if(s == "union") {
  		cin >> a >> b;
  		dsu.unify(a, b);
  	}
  	else {
  		cin >> a;
  		dsu.get(a);
  	}
  }
  return 0;
}