#include <iostream>
using namespace std;

int D[2001][2001];
int s[2001];
int v[2001];
int S;
int N;

int f(int n, int w) {
	if (n <= 0) return 0;

	int &x = D[n][w];
	if (x != -1) return x;

	if (s[n] > w)
		x = f(n-1, w);
	else
		x = max(f(n-1, w), v[n] + f(n-1, w - s[n]));
	return x;
}

int main()
{
	cin >> S >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < S; j++) {
			D[i+1][j+1] = -1;
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> s[i+1] >> v[i+1];
	}
	cout << f(N, S) << endl;
}
