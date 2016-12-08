class MatrixGraph {
private:
	double* w;
	int v;
	static double INF = std::numeric_limits<double>::infinity();

public:
	MatrixGraph(int v) { //O(v*v)
		w = new double[v*v];
		for (int i = 0; i < v*v; i++)
			w[i] = INF;
		this->v = v;
	}
	~MatrixGraph() { //O(1)
    delete[] w;
	}

	double operator()(int from, int to, double w) const {
		w[from*v + to] = w;
	}

	double& operator()(int from, int to, double w) {
		w[from*v + to] = w;
	}

};
	
	
