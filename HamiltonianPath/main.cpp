#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define pb push_back
#define SZ(s) int(s.size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<ii>> nodes(n);
    int limitMask = pow(2,n);
    int dp [limitMask][n];
    fore(i,0,m){
        int x,y,z;
        cin>>x>>y>>z;
        nodes[x-1].pb({y-1,z});
        nodes[y-1].pb({x-1,z});
    }

    fore(mask,0,limitMask){
        fore(i,0,n){
            if((mask&(1<<i)) && __builtin_popcount(mask)==1)
                dp[mask][i]=0;
            else if (mask&(1<<i)) {
                int minEdge = 1e9;
                int adjacent = -1;
                for(auto pa: nodes[i]){
                    int j = pa.fst;
                    int edge = pa.snd;
                    if (mask&(1<<j) && dp[mask ^ (1<<i)][j] != 1e9 && dp[mask ^ (1<<i)][j] + edge < minEdge){
                        minEdge = dp[mask ^ (1<<i)][j] + edge;
                        adjacent=j;
                    }
                }
                if (adjacent == -1)
                    dp[mask][i]=1e9;
                else
                    dp[mask][i]=minEdge;
            } else
                dp[mask][i]=1e9;
        }
    }

    int mini = 1e9;
    fore(i,0,n)
        mini = min(mini, dp[limitMask-1][i]);

    cout<<mini<<"\n";
    return 0;
}
