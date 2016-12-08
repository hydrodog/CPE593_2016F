#include <iostream>
using namespace std;

int main() {
	for (float x = 0; x < 10; x += 0.1)
		cout << x << ' ';
	float x = .1;
	float sum = 0;
	for (int i = 0; i < 10; i++)
		sum += x;
	cout << "\nis sum=1.0?" << (sum == 1.0) << '\n';
}
