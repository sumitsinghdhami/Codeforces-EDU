/* (E) Equation */

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double c;

bool good (double x) {
    if( x*x + sqrt(x) >= c) 
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); 
    cin >> c;
    // f(x) is good if  x + sqrt(x) >= c
    double l = 0; //bad
    double r = c; // good
    for(int i = 0; i < 100; ++i) {
        double m = (l+r)/2;
        if(good(m))
            r = m;
        else
            l = m;
    }
    cout << setprecision(20) << r;
    return 0;
}
