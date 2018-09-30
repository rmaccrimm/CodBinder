#include <iostream>
#include <vector>
using namespace std;


/* 
   Construct data structure in O(n log n)
   Search in O(1)
*/

class RMQ
{
public:
	RMQ(const vector<int> &A) : B(A)
	{
        vector<int> v;
		for (int i = 0; i < A.size(); i++) v.push_back(i);
        M.push_back(v);
		for (int i = 1, p = 1; p <= A.size(); i++, p *= 2) {
			vector<int> V;
			int m;
			for (int j = 0; j + p < M[i-1].size(); j++) {
				m = (B[M[i-1][j]] <= B[M[i-1][j+p]] ? M[i-1][j] : M[i-1][j+p]);
				V.push_back(m);
			}
			M.push_back(V);
		}
	}

	int query(int L, int R)
	{
		int n = (L == R ? 0 : 31 - __builtin_clz(R - L)); // log(R - L)
        int r = R + 1 - (1 << n);
		return B[M[n][L]] <= B[M[n][r]] ? M[n][L] : M[n][r];
	}

    vector<int> B;
	vector<vector<int>> M;
};


int main()
{
	int n, q;
	cin >> n;
	vector<int> A(n);
	for (auto &x: A) cin >> x;
	RMQ r(A);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, h;
		cin >> l >> h;
		cout << A[r.query(l, h)] << endl;
	}
}
