/* (A) Disjoint Sets Union */

#include <bits/stdc++.h>

using namespace std;

class disjoint_set {
  vector<int> sets;
  vector<int> sizes;
  
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
		sizes.resize(n+1);
		for(int i = 0; i <= n; i++) {
			sets[i] = i;
			sizes[i] = 1;
		}
	}

	void unify(int a, int b) {
		int i = root(a);
		int j = root(b);
		if(i==j) return;
		if(sizes[i] > sizes[j]) { sets[j] = i; sizes[i] += sizes[j]; }
		else { sets[i] = j; sizes[j] += sizes[i]; }
	}

	bool get (int a, int b) {
		return root(a) == root(b);
	}
   
};

int main() {
	std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  disjoint_set dsu(n);
  while(m--) {
  	string s; 
  	int a, b;
  	cin >> s >> a >> b;
  	if(s == "union") {
  		dsu.unify(a, b);
  	}
  	else {
  		if(dsu.get(a, b)) {
  			cout << "YES\n";
  		} else {
  			cout << "NO\n";
  		}
  	}
  }
  return 0;
}