#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

set<int> reachableBy [100005];
vi inversedGraph[100005];

void dfs(int n, int r){
    if (reachableBy[n].count(r)) return;
    if (SZ(reachableBy[n]) == 2) return;
    reachableBy[n].insert(r);
    for(int neigh: inversedGraph[n])
        dfs(neigh, r);
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n,m,t;
    cin >> n >> m >> t;
    vi neighborsT;
    fore(i,0,m){
        int n1, n2;
        cin >> n1 >> n2;
        if (n2 == t)
            neighborsT.pb(n1);
        else 
            inversedGraph[n2].pb(n1);
    }

    for (int neigh: neighborsT)
        dfs(neigh, neigh); 

    set<int> toPrint;
    for (int neigh : neighborsT){
        if (SZ(reachableBy[neigh]) == 1)
            toPrint.insert(neigh);
    }
    cout << SZ(toPrint) << "\n";
    for (int inSet : toPrint)
        cout << inSet << "\n";

    return 0;
}
