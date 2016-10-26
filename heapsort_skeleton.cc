void makesubheap(int x[], int i, int n) {
  int left = 2 * i + 1;
	int right = left + 1;
	if (left >= n)
		return;
	if (right >= n && x[left] > x[i]) {
		swap(x[left], x[i]);
		makesubheap(x, left, n);
		return;
	}

	if (x[left] > x[right]) {
		if (x[left] > x[i]) {
			swap(x[left], x[i]);
			makesubheap(x, left, n);
		}
	} else {
		if (x[right] > x[i]) {
			swap(x[right], x[i]);
			makesubheap(x, right, n);
		}
	}
}

void makeheap(int x[], int n) {
	for (int i = n/2; i >= 0; i--) {
		makesubheap(x, i, n);
	}
}
