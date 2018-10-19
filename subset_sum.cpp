#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> D;
vector<int> A;

bool f(int n, int s) {
    if (n == 1) return A[n] == s;
    if (s == 0) return true;
    
    int &x = D[n][s];
    if (x != -1) return x;

    if (s > A[n]) 
        return x = A[n] == s || f(n-1, s) || f(n-1, s-A[n]);
    else
        return x = A[n] == s || f(n-1, s);
}

int main()
{

    D = vector<vector<int>>(101);
    for (auto &d: D) d = vector<int>(100001, -1);
        
    int n, k;
    cin >> n >> k;
    
    A = vector<int>(n+1);

    for (int i = 1; i <= n; i++) 
        cin >> A[i];
    sort(begin(A), end(A));

    // Does some subset of the last n items add to k?
    cout << f(n, k) << endl;
}
