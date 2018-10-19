#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* 
   Dijoint set data structure with path compression
   Find is worst case ~O(n)
*/

class DS
{
	DS(const vector<int> &V) {
		for (auto v: V)
			p[v] = v;
	}
	
	void join(int a, int b) { p[a] = p[b]; }

	int find(int x)
	{
		if (p[x] != x)
			p[x] = find(p[x]);
		return p[x];
	}

	map<int, int> p;
};

int main()
{
	int n;
	cin >> n;
	for (int i =0; i < n; i++) {
		string s;
		cin >> s;
		int x = s - 'A';
		vector<int> A(x);
		DS(A);
		
	}
}

	
