/* (E) Monkeys */

#include <bits/stdc++.h>

using namespace std;
struct meta {
	int size;
	int time;
};
class disjoint_set {
  vector<int> sets;
  vector<struct meta> info;
public:
	disjoint_set (int n) {
		sets.resize(n+1);
		info.resize(n+1);
		for(int i = 0; i <= n; i++) {
			sets[i] = i;
			info[i] = {1, -1};
		}
	}
  
  int root(int a) {
  	while(a != sets[a]) {
  		a = sets[a];
  	}
  	return a;
  }

	void unify(int a, int b) {
		int i = root(a);
		int j = root(b);
		if(i==j) return;
		if(i == 1) {
			sets[j] = 1;
			info[i].size += info[j].size;
		} else if( j == 1) {
			sets[i] = 1;
			info[j].size += info[i].size;
		} else {
			if(info[i].size > info[j].size) {
			 sets[j] = i; 
			 info[i].size += info[j].size;
			} else { 
			 sets[i] = j; 
			 info[j].size += info[i].size;
			}
		}
	}

	bool find(int a, int b) {
		return root(a) == root(b);
	}
  void set_falling_time(int target, int time) {
  	info[target].time = time; 
  }
  int set_falling_time_tree(int target) {
  	if(sets[target] == target || info[target].time != -1) {
  		return info[target].time;
  	}
		info[target].time = set_falling_time_tree(sets[target]);
		return info[target].time;   	
  }
  void print_time() {
  	for(int i = 1; i < sets.size(); i++) {
  		cout << info[i].time  << '\n';
  	}
  }
};

int main() {
	std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> adj(n+1);
  // adj[i][0] stores left and adj[i][1] stores right;
  for(int i = 1; i <= n; i++) {
  	cin >> adj[i].first >> adj[i].second;
  };

  vector<pair<int, int>> minutes(m);
  auto adj_rem = adj;

  for(int i = 0; i < m; i++) {
  	cin >> minutes[i].first >> minutes[i].second;
  	if(minutes[i].second == 1) {
  		adj_rem[minutes[i].first].first = -1;
  	} else {
  		adj_rem[minutes[i].first].second= -1;
  	}
  }	

 	disjoint_set dsu(n);
  for(int i = 1; i <= n; i++) {
  	if(adj_rem[i].first != -1)
  	dsu.unify(i, adj_rem[i].first);
  	if(adj_rem[i].second != -1)
  	dsu.unify(i, adj_rem[i].second);
  }
  for(int i = m-1; i >= 0; i--) {
  	int a = minutes[i].first, b{};
  	if (minutes[i].second == 1) {
  		b = adj[a].first;
  	} else {
  		b = adj[a].second;
  	}
  	if ( (!dsu.find(1, a)) && (!dsu.find(1, b)) ){
  		dsu.unify(a, b);
  	} else if (dsu.find(1, a) && (!dsu.find(1, b))) {
  		dsu.set_falling_time(dsu.root(b), i);
  		dsu.unify(a, b);
  	} else if (dsu.find(1, b) && (!dsu.find(1, a))) {
  		dsu.set_falling_time(dsu.root(a), i);
  		dsu.unify(a, b);
  	}

  }
	for(int i = 1; i <= n; i++) {
		dsu.set_falling_time_tree(i);	
	}
	dsu.print_time();



  return 0;
}