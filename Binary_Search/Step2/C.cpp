/* (C) Very Easy Task */

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

long long n, x, y;

bool good (long long t) {
    if(x < y)
        t -= x;
    else
        t -= y;
    if(t < 0 || (t/x + t/y < n-1))
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); 
    
    cin >> n >> x >> y;
    long long l = 0; // bad
    long long r = n * x; // good
    while( r > l + 1) {
        long long m = (l+r) >> 1;
        if(good(m))
            r = m;
        else
            l = m;
    }
    cout << r;
}

