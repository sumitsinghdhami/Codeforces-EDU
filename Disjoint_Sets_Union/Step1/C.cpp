/* (C) Experience */

#include <bits/stdc++.h>

using namespace std;
struct meta {
	int score;
	int size;
};
class disjoint_set {
  vector<int> sets;
  vector<struct meta> info;
  
  int root(int a) {
  	while(a != sets[a]) {
  		a = sets[a];
  	}
  	return a;
  }
public:
	disjoint_set (int n) {
		sets.resize(n+1);
		info.resize(n+1);
		for(int i = 0; i <= n; i++) {
			sets[i] = i;
			info[i] = {0, 1};
		}
	}

	void unify(int a, int b) {
		int i = root(a);
		int j = root(b);
		if(i==j) return;
		if(info[i].size > info[j].size) {
		 sets[j] = i; 
		 info[i].size += info[j].size;
		 info[j].score -= info[i].score;
		}
		else { 
		 sets[i] = j; 
		 info[j].size += info[i].size;
		 info[i].score -= info[j].score;	
		}
	}

	void add(int a, int val) {
		int j = root(a);
		info[j].score += val;
	}

	int get (int a) { 
		if(a == sets[a]) return info[a].score;
		return get(sets[a]) + info[a].score;
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
  	cin >> s;
  	if(s == "add") {
  		cin >> a >> b;
  		dsu.add(a, b);
  	} else if(s == "join") {
  		cin >> a >> b;
  		dsu.unify(a, b);
  	}
  	else {
  		cin >> a;
  		cout << dsu.get(a) << '\n';
  	}
  }
  return 0;
}