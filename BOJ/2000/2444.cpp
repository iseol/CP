#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	
	for (int i = 1; i <= n; i++) {
		for (int j = n-1; j >= i; j--) {
			cout << ' ';
		}
		for (int j = 2*i-1; j >= 1; j--) {
			cout << '*';
		}
		cout << '\n';
	}
	for (int i = 1; i < n; i++) {
		
		for (int j = 0; j < i; j++) cout << ' ';
		for (int j = 1; j <= 2*n-1-2*i; j++) {
			 cout << '*';
		}
		cout << '\n';
	}
}
