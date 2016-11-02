void badmagic3() {
	const int rowsum = 15;
	for (int a = 1; a <= 9; a++)
		for (int b = 1; b <= 9; b++) {
			if (a == b)
				continue;
			int c = rowsum - a - b;
			if (c < 1 || c > 9)
				continue;
			if (c == b || c == a)
				continue;
			// UGLY!
		}
}

void badmagic3b() {
	const int rowsum = 15;
	for (int a = 1; a <= 9; a++) {
		const int bmax = rowsum - a - 1;
		const int bmin = rowsum - a - bmax;
		for (int b = bmin; b <= bmax; b++) {
			if (a == b)
				continue;
			int c = rowsum - a - b;
			if (c == b || c == a)
				continue;
		}


}
