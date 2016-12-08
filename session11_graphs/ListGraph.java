public class MatrixGraph {
	private double [] w;
	private int v;

	//use Double.POSITIVE_INFINITY to represent no connection

	public MatrixGraph(int v) {
		w = new double[v*v];
		this.v = v;
		for (int i = 0; i < w.length; ++i)
			w[i] = Double.POSITIVE_INFINITY;
	}
	public void setWeight(int from, int to, double w) {
		this.w[from*v + to] = w;
	}
	public double getWeight(int from, int to) { //O(1)
		return this.w[from*v + to];
	}

	
	
