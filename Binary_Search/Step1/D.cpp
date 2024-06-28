#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    int n{}, k{};
    cin >> n;
    std::vector<int> vec(n+2);
    vec[0] = INT_MIN;
    vec[n+1] = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    cin >> k;
    while(k--) {
        int tl{}, tr{};
        cin >> tl >> tr;
        int l{}, r{n+1};
        int ans{};
        // perform close to right for tl
        while(r > l + 1) {
            int mid = l + ((r - l) >> 1);
            if(tl > vec[mid]) 
                l = mid;
            else
                r = mid;
        }
        ans = r;
        l = 0;
        r = n + 1;
        // perform close to the left for tr
        while(r > l + 1) {
            int mid = l + ((r-l) >> 1);
            if(tr >= vec[mid])
                l = mid;
            else 
                r = mid;
        }
        ans = l - ans + 1;
        cout << ans << ' ';
    }

}

