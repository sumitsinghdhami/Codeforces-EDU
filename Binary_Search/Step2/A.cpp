/* (A) Packing Rectangles */

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    int w{}, h{}, n{};
    cin >> w >> h >> n;
    long long r = 1;
    while(true) {
        if((r/w) * (r/h) >= n)
            break;
        r = r << 1;
    }
    long long l{};
    while(r > l + 1) {
        long long m = l + ((r-l) >>1);
        if((m/w) * (m / h) >= n)
            r = m;
        else
            l = m;
    }
    cout << r;

}

