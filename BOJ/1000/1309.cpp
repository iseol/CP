#include <iostream>
using namespace std;

int d[100001][3];
const int mod = 9901;

int main(void) {
	d[1][0] = d[1][1] = d[1][2] = 1;
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % mod;
		d[i][1] = (d[i-1][0] + d[i-1][2]) % mod;
		d[i][2] = (d[i-1][0] + d[i-1][1]) % mod;
	}
	
	int ans = (d[n][0] + d[n][1] + d[n][2]) % mod;
	
	cout << ans << '\n';
}
