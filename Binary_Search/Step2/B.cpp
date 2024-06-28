/* (B) Ropes */

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int n, k;
std::vector<int> v;

bool good (double x) {
	int sum{};
	for(int i : v) {
		sum += floor(i / x); // #include <cmath>
	}
	return sum >= k;
}
int main() {
    ios::sync_with_stdio(false); 
    
    cin >> n >> k;
    
    v.resize(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    double l = 0; // good
    double r = 1e8; // bad
    
    cout << setprecision(20); // #include <iomanip>

    for(int i = 0; i < 100; ++i) {
    	double m = (l + r) / 2;
    	if(good(m))
    		l = m;
    	else
    		r = m;
    }
    
    cout << l;
}

