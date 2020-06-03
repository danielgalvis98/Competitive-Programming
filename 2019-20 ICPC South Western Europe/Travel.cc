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


ii stations [1010];
int Co2PerDist [105];
vector<ii> graph [1010];

int dist (int i, int j){
    return (int)(ceil(sqrt((stations[i].first-stations[j].first)*(stations[i].first-stations[j].first) + 
        (stations[i].second-stations[j].second)*(stations[i].second-stations[j].second))));
}

int dp[1010][105];

int solve (int station, int kilAvailable){
    if (kilAvailable < 0)
        return 1e9;
    if (station == 1008)
        return 0;
    int &r = dp[station][kilAvailable];
    if (r != -1) return r;

    r = 1e9;
    for(ii goTo : graph[station]){
        r= min(r,solve(goTo.first, kilAvailable - dist(station,goTo.first))
    					+ dist(station,goTo.first) * goTo.second);
    }

    return r;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    cin >> stations[0].first >> stations [0].second >> stations[1008].first >> stations[1008].second;


    int maxDist;
    cin >> maxDist;
    cin >> Co2PerDist[0];

    int T;
    cin >> T;
    fore(i,0,T)
        cin >> Co2PerDist[i+1];
    
    int N;
    cin >> N;
    fore(i,0,N){
        graph[0].pb({i+1, Co2PerDist[0]});
        int li;
        cin >> stations[i+1].first >> stations[i+1].second >> li;
        fore(k,0,li){
            int j, mj;
            cin >> j >> mj;
            graph[i+1].pb({j+1,Co2PerDist[mj]});
            graph[j+1].pb({i+1,Co2PerDist[mj]});
        }
        graph[i+1].pb({1008,Co2PerDist[0]});
    }
    graph[0].pb({1008, Co2PerDist[0]});
    memset(dp, -1, sizeof dp);

    int ans = solve(0, maxDist);
    ans = ans == 1e9 ? -1 : ans;
    cout << ans << "\n";

    return 0;
}
