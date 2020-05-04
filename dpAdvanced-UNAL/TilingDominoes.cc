#include <cstring>
#include <iostream>
#include <map>

using namespace std;
typedef long long int ll;

int n;
int m, cas;

ll dp[15][110][(1 << 10) + 1];
int cases[15][110][(1 << 10) + 1];

ll go (int mask, int i, int j){
    if (j == m)
        return 1;
    
    ll &ans = dp[i][j][mask];
    if (cases[i][j][mask] == cas) return ans;
    cases[i][j][mask] = cas;
    if (i == n)
        return ans = go(mask, 0, j+1);
    

    
    ans = 0;

    if ((mask >> i) & 1)
        return ans = go (mask & (~(1 << i)), i+1, j);
    

    if (i+1 < n && !((mask >> (i+1)) & 1 ))
        ans += go(mask, i+2, j);
    if (j + 1 < m)
        ans += go(mask | (1 << i), i+1, j);

    return ans;
}


int main()
{
    while (cin >> n){
        cin >> m;
        cas++;
        if (m < n)
            swap(n, m);
        
        cout << go(0, 0, 0) << "\n";
    }
    return 0;
}
