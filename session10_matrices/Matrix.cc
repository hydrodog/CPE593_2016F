#include <iostream>
#include <fstream>
using namespace std;

class Matrix {
private:
	double* m;
	int rows, cols;
public:
	Matrix() :rows(0), cols(0), m(nullptr) {}
	Matrix(int r, int c) : rows(r), cols(c), m(new double[r*c]) { //O(n*n)
		//    for (int i = 0; i < r; i++)
		//			for (int j = 0; j < c; j++)
		//				m[i*cols + j] = 0;
    for (int i = 0; i < r*c; i++)
				m[i] = 0;
	}
	~Matrix() {
		delete [] m;  //O(1)
	}
	Matrix(Matrix&& orig) { //O(1)
		rows = orig.rows;
		cols = orig.cols;
		m = orig.m;
		orig.m = nullptr;
	}
	Matrix(const Matrix& orig) : rows(orig.rows), cols(orig.cols) { //O(n*n)
		m = new double[rows*cols];
    for (int i = 0; i < rows*cols; i++)
			m[i] = orig.m[i];
	}
	double operator ()(int i, int j) const { return m[i * cols + j]; }
	double& operator ()(int i, int j) { return m[i * cols + j]; }
	friend Matrix operator +(const Matrix& a, const Matrix& b) {
		if (a.rows != b.rows || a.cols != b.cols)
			throw "Bad size for add";
		Matrix ans(a.rows, a.cols);
		//    for (int i = 0; i < rows; i++)
		//			for (int j = 0; j < cols; j++)
		//				ans(i,j) = a(i,j) + a(i,j);

		for (int i = 0; i < a.rows*a.cols; i++)
			ans.m[i] = a.m[i] + b.m[i];
		return ans;
	}

	friend Matrix operator *(const Matrix& a, const Matrix& b) { //O(a.rows*a.cols*b.cols)
		if (a.cols != b.rows)
			throw "Bad size";
		Matrix ans(a.rows, b.cols);  //O(a.rows*b.cols)
		for (int k = 0; k < b.cols; k++) { //O(b.cols)
			for (int j = 0; j < a.rows; j++) { //O(a.rows)
				double dot = 0;
				for (int i = 0; i < a.cols; i++) // O(a.cols)
					dot = dot + a(j, i) * b(i, k); 
				ans(j, k) = dot;
			}
		}
		return ans;
	}
	friend ostream& operator <<(ostream& s, const Matrix& m) {
		for (int i = 0; i < m.rows; i++) {
			for (int j = 0; j < m.cols; j++)
				s << m(i,j) << '\t';

			s << '\n';
		}
		return s;
	}
	friend istream& operator >>(istream& s, Matrix& m) {
		int r, c;
		s >> r >> c;
		Matrix temp(r,c);
		for (int i = 0; i < r*c; i++)
			s >> m.m[i];
		return s;
	}
	// print out the solution to n variables using Gaussian Partial Pivoting
	void solve() {
		
	}
};

int main() {
	Matrix m1(100, 20); //O(r*c)
  Matrix m2(3,4);
	cout << m2(0,0); // calls operator () const
	m2(0,0) = 5.0; // calls operator ()
	Matrix m3(3,4);
	m3(0,0) = 3.5;
	m3(0,1) = 2.5;

	
	Matrix m4 = m2 + m3; // O(r*c)
	// dot product of row*col = O(N)
	Matrix m5(2,3); // O(M, N)
	m5(0,0) = 1; m5(0,1)=0; m5(0,2) = 2;
	m5(1,0) = 0; m5(1,1)=2; m5(1,2) = 1;

	Matrix m6(3,2); //O(N, P)
	m6(0,0) = 1; m6(0,1)=0;
	m6(1,0) = 0; m6(1,1)=2;
	m6(2,0) = 3; m6(2,1)=-1;

	Matrix m7 = m5 * m6; //O(N*M*P)
	// if M=N=P  O(N^3)
	cout << '\n';
	cout << m7 << '\n';

	ifstream f("solve.dat");
	Matrix m8;
	f >> m8;
	m8.solve();
}
