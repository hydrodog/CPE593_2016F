#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int a[] = {1, 2, 3, 4};
	while (next_permutation(a, a+4)) {
		for (int i = 0; i < 4; i++)
			cout << a[i];
		cout << "\n";
	}
	char b[] = "abc";
	while (next_permutation(b, b+3))
		cout << b << "\n";

	vector<int> c;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	while (next_permutation(c.begin(), c.end())) {
		for (int i = 0; i < c.size(); i++)
			cout << c[i] << " ";
		cout << '\n';
	}
	return 0;
}
