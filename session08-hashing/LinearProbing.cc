#include <iostream>
#include <vector>
using namespace std;

class HashSetLinearProbing {
private:
	vector<int> data;
	int used;
	
	int hash(int x) {
		return x % data.size();
	}
	// ideally double in size?
	void grow() {

	}
public:
	HashSetLinearProbing(int size = 16) {
		data.reserve(size);
		used = 0;
		for (int i = 0; i < data.size(); ++i)
			data[i] = 0;
	}

	void add(int v) {
		used++;
		if (used > data.size())
			grow();
		int i = hash(v);
		while (data[i] != 0) {
			i++;
			if (i == data.size())
				i = 0;
		}
		data[i] = v;

	}

	bool contains(int v) {
		int i = hash(v);
		while(data[i] != 0) {
			if (data[i] == v)
				return true;
			i++;
		}
		return false;
	}
}
