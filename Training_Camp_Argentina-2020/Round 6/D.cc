#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
 
using namespace std;
typedef pair<int,int> ii;
const int MAXN=300005;
int n,m;
vector<int> dp[MAXN];
vector<ii> g[MAXN];
int go(int u,int w){ 
    int sum = 0;
    int idx = 0;
	for(ii edge: g[u]){
        if (edge.ss > w){
            int toSum = 0;
            if (dp[u][idx] != -1){
                toSum = dp[u][idx];
            } else {
                dp[u][idx] = toSum =1 + go(edge.ff, edge.ss);
            }
            sum = max(sum, toSum);
        }
        idx++;
    }
    return sum;
}
int main(){FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
	cin >> n >> m;
	fore(i,0,m){
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].pb(ii(v,w));
        dp[u].pb(-1);
	}
    //Es el mismo tuyo solo modifique el metodo
    //Pero se está quedando corriendolo infinitamente no je por que. juy. juy. Ve este codigo está raro no me pasa del main
	int maximo=1;
	fore(i,0,n){
		maximo=max(maximo,go(i,0));
	}
	cout << maximo << "\n";
	return 0;
}