#include <iostream>
using namespace std;

int a[10];
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];


    int ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] > k || k == 0) continue;
        ans += k / a[i];
        k %= a[i];
    }
    
    cout << ans;
}