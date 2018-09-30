#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 
   O(n log n)
*/

vector<int> A;
vector<int> M;
vector<int> P;
bool comp(int a, int b) { return A[M[a]] < b; }

int main()
{
	int n;
	cin >> n;
	A = vector<int>(n);
	M = vector<int>(n);
	P = vector<int>(n);
	int L = 0;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		int l = lower_bound(begin(M), begin(M) + L, A[i], comp) - 1 - begin(M);
		P[i] = M[l-1];
		M[l] = i;
		if (l > L)
			L = l;
	}
	cout << L << endl;
}
