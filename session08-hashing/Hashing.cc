class HashSet {
private:
	int* table;
	int capacity;
	int used;
	void grow() {
		int* temp = table;
		table = new int[capacity*2];
		for (int i = 0; i < capacity; i++)
			if (temp[i] != 0)
				table[hash(temp[i])] = temp[i];

	}
public:
	HashSet(int size) : capacity(size) {
		table = new int[capacity];
		for (int i = 0; i < capacity; i++)
			table[i] = 0;
	}
	int hash(int v) {
    return v % capacity;
	}

	void add(int v) {
		if (used + used >= capacity)
			grow();
		int i = hash(v);
		while (table[i] != 0) {
			i++;
			if (i == capacity)
				i = 0;
		}
		table[i] = v;
	}

	bool contains(int v) {

	}

};
