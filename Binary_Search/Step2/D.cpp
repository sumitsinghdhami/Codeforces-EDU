/* (D) Children Holiday */

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

long long m, n;
std::vector<long long> t;
std::vector<long long> z;
std::vector<long long> y;
bool good (long long T) {
    long long sum{};
    for(int i =0; i < n; ++i) {
        // "inflate and rest" cycle runs for x times
        long long x = T / (t[i]*z[i] + y[i]);
        sum += x * z[i]; // no. of cycles * balloons inflated in one cycle
        // time taken for x cycles
        x *= (t[i]*z[i] + y[i]);  
        // in remaining time we can inflate upto z[i] extra balloons
        sum += min(z[i],  (T - x ) / t[i]);
    }
    if(sum >= m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); 
    cin >> m >> n;
    
    t.resize(n);
    z.resize(n);
    y.resize(n);

    for(int i = 0; i < n; ++i) cin >> t[i] >> z[i] >> y[i];
    if(m == 0 ) {
        cout << "0\n";
        for(int i = 0; i < n; ++i) cout << "0 "; 
        return 0;
    }
    long long l = 0; // bad
    long long r = ((m  + z[0]) /z[0])* (t[0]*z[0] + y[0]);  // good
    while( r > l + 1) {
        long long m = (l+r) >> 1;
        if(good(m))
            r = m;
        else
            l = m;
    }

    cout << r << '\n';
    long long remaining = m;
    for(int i = 0; i < n; ++i) {
        if(remaining == 0) {
            cout << "0 ";
            continue;
        }
        long long count{};
        long long x = r / (t[i]*z[i] + y[i]);
        count += x * z[i]; // no. of cycles * balloons inflated in one cycle
        // time taken for x cycles
        x *= (t[i]*z[i] + y[i]);  
        // in remaining time we can inflate upto z[i] extra balloons
        count += min(z[i],  (r - x ) / t[i]);
        if(count > remaining){
            cout << remaining << ' ';
            remaining = 0;
        }
        else {
            cout << count << ' ';
            remaining -= count;
        }
    }
    cout << '\n';
}

