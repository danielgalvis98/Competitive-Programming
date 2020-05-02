// #include <bits/stdc++.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <cstring>

#define fst first
#define snd second
#define fore(i, a, b) for (int i = a, end = b; i < end; i++)
#define ALL(s) s.begin(), s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;

const int MAX_N = 20005;
vi tree [MAX_N];
int ans [MAX_N];

int dfs(int n, int idx = 1, int par = -1)
{
    int tot = 1;
    int maxi = 0;
    fore(i,0,SZ(tree[idx])){
        int son = tree[idx][i];
        if (son != par){
            int par = dfs(n, son, idx);
            tot += par;
            maxi = max(maxi, par);
        }
    }
    if (par != -1)
        maxi = max(maxi, n - tot);
    ans[idx] = maxi;
    

    return tot;
}

int main()
{FIN;

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        fore(i,0,n+2){
            tree[i].clear();
        }
        fore(i, 0, n - 1)
        {
            int a, b;
            cin >> a >> b;
            tree[a].pb(b);
            tree[b].pb(a);
        }

        dfs(n);
        int idx = 0;
        int min = 1e9;
        fore(i,1,n+1){
            if (ans[i] < min){
                idx = i;
                min = ans[i];
            }
        }

        cout << idx << " " << min << "\n";
    }
    return 0;
}