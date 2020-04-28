#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;

auto rnd=bind(uniform_int_distribution<long long>(1,1e13), mt19937(time(0)));

const int MAXN = 3*1e5 + 10;

map<ll, ll> functionResults;

vector<vi> graph (MAXN);
vl nodeValues (MAXN);

ll f(ll x){
    if (!functionResults.count(x))
        functionResults[x] = rnd();
    
    return functionResults[x];
}

ll dfs (int v, int parent = -1){
    ll sum = 0;
    vi node = graph[v];
    fore(i,0, SZ(node)){
        int child = node[i];
        if (child != parent)
            sum += dfs (child, v);
    }
    nodeValues[v] = f(sum);
    return nodeValues[v];
}

set <ll> ans;
void solve(int v, int par = -1, ll hashPar = 0){
    ll sum =  hashPar;
    vi node = graph[v];
    fore(i,0,SZ(node)){
        int child = node[i];
        if (child != par)
            sum += nodeValues[child];
    }
    ans.insert(f(sum));
    
    fore(i,0,SZ(node)){
        int child = node[i];
        if (child != par)
            solve(child, v, f(sum - nodeValues[child]));
    }

}

int main()
{

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n;
    cin >> n;
    fore(i,0,n-1){
        int a, b;
        cin >> a >> b;
        graph[--a].pb(--b);
        graph[b].pb(a);
    }

    dfs(0);
    solve(0);
    cout << SZ(ans) << "\n";

    return 0;
}
