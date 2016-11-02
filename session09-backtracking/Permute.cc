#include <vector>
#include <iostream>

using namespace std;
class Permute {
private:
	vector<int> p;
public:
	Permute(int n) {
		p.reserve(n);
		for (int i = 0; i < n; i++)
			p.push_back(i+1);
		generate(n);
	}
  void doit() {
		cout << "doit size=" << p.size() << '\n';
		for (int i = 0; i < p.size(); i++)
			cout << p[i];
		cout << '\n';
	}
	void generate(int N) {
		cout << "generate(" << N << ")\n";
    if (N == 0)
			doit();
    for (int c = 0; c < N; c++) {
			swap(p[c], p[N-1]);
			generate(N-1);
			swap(p[c], p[N-1]);
		}
	}
};


int main() {
	Permute p(4);
}
