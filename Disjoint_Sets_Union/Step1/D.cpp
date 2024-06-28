/* (D) Cutting a graph */

#include <bits/stdc++.h>

using namespace std;
struct meta {
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
			info[i] = {1};
		}
	}

	void unify(int a, int b) {
		int i = root(a);
		int j = root(b);
		if(i==j) return;
		if(info[i].size > info[j].size) {
		 sets[j] = i; 
		 info[i].size += info[j].size;
		}
		else { 
		 sets[i] = j; 
		 info[j].size += info[i].size;
		}
	}

	bool find(int a, int b) {
		return root(a) == root(b);
	}
  
};

int main() {
	std::ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  int x1, x2;
  for(int i = 0; i < m; i++) cin >> x1 >> x2;
  vector<vector<int>> v(k, vector<int> (3));
  for(int i = 0; i < k; i++) {
  	string s; 
  	cin >> s;
  	if(s == "ask") v[i][0] = 0; // 0 for ask
  	else v[i][0] = 1; // 1 for cut
  	cin >> v[i][1] >> v[i][2];
  }	
 	disjoint_set dsu(n+1);
 	stack<int> st; 
  for(int i = k-1; i >= 0; i--) {
  	if(v[i][0]) dsu.unify(v[i][1], v[i][2]);
		else st.push(dsu.find(v[i][1], v[i][2])); 
  }
  while(!st.empty()) {
  	if(st.top()) cout << "YES\n";
	  else cout << "NO\n";
  	st.pop();
  }
  return 0;
}