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
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;


const int MAX_V = 305;

const int MAX_P = 35;

int pos [MAX_V];

ll dp [MAX_V][MAX_P];


ll dist[MAX_V][MAX_V];

ll distTwoPosts (int i, int l){
    ll ans = 0;
    fore(j, l+1, i){
            ans += min(pos[j] - pos[l], pos[i] - pos[j]);
    }

    return ans;
}

ll go(int i, int p, int v){
    ll &r = dp[i][p];
    if (r != -1) return r;

    if (i == v) return 0;
    if (p==0) return r = dist[i][v];

    r = 1e18;
    fore(j, i+1, v)
        r = min(r, dist[i][j] + go(j, p-1, v));
    
    return r;

}

int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int v, p;
    cin >> v >> p;

    memset(dp, -1, sizeof(dp));

    pos[0] = -1e9;
    fore (i, 0, v)
        cin >> pos [i+1];

    pos[v + 1] = 1e9;
    
    fore(i,0,v+2){
        fore(j,i, v+2){
            dist[i][j] = distTwoPosts(j,i);
        }
    }
    
    cout << go (0, p, v+1) << "\n";
    return 0;
}