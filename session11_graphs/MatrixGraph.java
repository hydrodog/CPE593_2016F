public class MatrixGraph {
	private double [] w;
	private int v;

	public final double INF = Double.POSITIVE_INFINITY;// represent no connection

	public MatrixGraph(int v) {
		w = new double[v*v];
		this.v = v;
		for (int i = 0; i < w.length; ++i)
			w[i] = INF;
	}
	public void setWeight(int from, int to, double w) {
		this.w[from*v + to] = w;
	}
	public double getWeight(int from, int to) { //O(1)
		return this.w[from*v + to];
	}
	public void Bellman(int from) {
		double[] dist = new double[v];
		int from[] = new int[v];
		for (int k = 0; k < v; k++) {
			for (int i = 0; i < v; i++)
				for (int j = 0; j < v; j++) {
					double wt = getWright(from,i);
 					if (dist[i] + wt < dist[j])
						dist[j] = dist[i] + wt;
				}
		}
	}
}
	
	
