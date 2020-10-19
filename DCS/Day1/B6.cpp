//https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cout << "Original array\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << "\nReversed array";
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}