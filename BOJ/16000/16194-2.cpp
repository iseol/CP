#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> d(n+1, -1);
	vector<int> p(n+1);
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	d[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (d[i] == -1 || d[i] > d[i-j] + p[j]) {
				d[i] = d[i-j] + p[j];
			}
	cout << d[n] << '\n';
	return 0;
}
