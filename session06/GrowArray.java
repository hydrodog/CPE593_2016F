public class GrowArray {
	private int[] data;
	private int used;

	// double in size when out of room
	private void grow() {

	}
	public GrowArray(int initialSize) {}

	// 1 + 1 + 1 + 2 + 1 + 1 +  4 + 1 + 1 + 1+1
  // 1
  //
  // n/8
  // n/4
	// n/2  n( 1/2 + 1/4 + 1/8 + ...) = n*1

	
	public void addEnd(int v) {  //O(1)
		if (used >= data.length)
			grow();
		//		...
	}
	public void shrink() {}
	
	public void addStart(int v) {} //O(n)
	public void removeEnd() {} // O(1)
	public int removeStart() {} //O(n)


}
