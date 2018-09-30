#include <iostream>
using namespace std;

/* 
   O(log n)
   For "binary searching the answer" problems with condition defined by f
*/

int N;

bool f(int n)
{
	return n > N;
}

int main()
{
	cin >> N;
	int lo = 0, hi = 1;
	while(!f(hi)) hi *= 2;
	while (hi - lo > 5) {
		int mid = hi - (hi - lo)/2;
		(f(mid) ? hi : lo) = mid;
	}
	while (!f(lo)) lo++;
	cout << lo << endl; 
}
