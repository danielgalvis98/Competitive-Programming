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
typedef pair<int, int> ii;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int MAXN= 150*2 + 10;
const int INF = 1e9;

vvi graph (MAXN);
vvl costs (MAXN, vl(MAXN, INF));
vvi cap (MAXN, vi(MAXN, 0));


void shortest_path(int n, int s, vl &d, vi &p){
    d.assign(n, 1e18);
    d[s] = 0;
    p.assign(n, -1);
    vector<bool> inq (n, 0);
    queue<int> q;
    q.push(s);
    while (SZ(q))
    {
        int u = q.front();
        q.pop();
        inq[u] = 0;
        for(int adj : graph[u]){
            if (cap[u][adj] > 0 && d[adj] > d[u] + costs[u][adj]){
                d[adj] = d[u] + costs[u][adj];
                p[adj] = u;
                if (!inq[adj]){
                    inq[adj] = 1;
                    q.push(adj);
                }
            }
        }
    }
    
}


ll min_cost_max_flow (int n, int s, int t){
    vl d;
    vi p;
    ll cost = 0;
    while (1)
    {
        shortest_path(n, 0, d, p);
        if (d[t] == 1e18) break;

        int v = t;
        while (v != s){
            int par = p[v];
            cap[par][v] -= 1;
            cap[v][par] += 1;
            v = par;
        }

        cost += d[t];
        
    }
    return cost;
    
}


int main()
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int n, m;
    cin >> n >> m;
    fore(i,1,n+1){
        graph[0].pb(i);
        graph[i].pb(0);
        cap[0][i]=1;
        costs[0][i] = costs[i][0] = 0;

        graph[n + i].pb(2*n + 1);
        graph[2*n + 1].pb(n + i);
        cap[n+i][2*n + 1]=1;
        costs[n+i][2*n + 1] = costs[2*n + 1][n+i] = 0;

        graph[i].pb(n + i);
        graph[n + i].pb(i);
        cap[i][n + i] = 1;
        costs[i][n + i] = costs[n + i][i] = 0;
        
    }

    fore(i,0,m){
        int f, h, c;
        cin >> f >> h >> c;
        graph[f].pb(n + h);
        graph[n + h].pb(f);
        costs[f][n + h] = -c;
        costs[n + h][f] = c;
        cap[f][n + h] = 1;
    }

    int cost = -min_cost_max_flow(2*n + 2, 0, 2*n + 1);
    double gained = cost * 0.05;
    cout << fixed << setprecision(10) << gained << "\n";


    return 0;
}
