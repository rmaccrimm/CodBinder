#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;

/* 
    DP solution the the travelling salesman problem. 
    O(2^n * n^2)    
*/  

const int MAX = 18;
int D[MAX][1 << MAX];
int N;
vector<vector<int>> A;

const int inf = numeric_limits<int>::max();

int f(int n, int mask)
{
    if (mask == 0) return A[0][n];  

    int &x = D[n][mask];
    if (x != -1) return x;

    int m = inf;
    for (int i = 1; i < N; i++) {
        if (mask & (1 << i)) {
            int s = mask & ~(1 << n); 
            m = min(m, f(i, s) + A[i][n]);
        }
    }
    return x = m;
}

int main()
{
    for (int i =0; i < MAX; i++) {
        for (int j = 0; j < (1 << MAX); j++) {
            D[i][j] = -1;
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<int> v;
        for (int j = 0; j < N; j++) {
            int w;
            cin >> w;
            v.push_back(w);
        }
        A.push_back(v);
    }
    int s = 0;
    for (int i = 1; i < N; i++) 
        s |= (1 << i);
    int m = inf; 
    for (int i = 1; i < N; i++) 
        m = min(m, f(i, s) + A[i][0]);
    cout << m << endl;
}