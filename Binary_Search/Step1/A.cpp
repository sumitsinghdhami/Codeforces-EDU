#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
    int n{}, k{};
    cin >> n >> k;
    vector<int> vec(n+2);
    vec[0] = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    vec[n+1] = INT_MAX;
    while(k--) {
        int target;
        cin >> target;
        int l{}, r{n+1};
        while( r > l + 1) {
            int mid = l + ( (r-l) >> 1);
            if(vec[mid] < target)
                l = mid;
            else
                r = mid;
        }
        if(vec[r] == target)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

