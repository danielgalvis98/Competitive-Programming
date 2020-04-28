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

const int MAXR = 15;
const int MAX_TEAMS = 1 << MAXR;

ll dp [1 << 15][15];
int skill [MAX_TEAMS];

ll costToBeat(int i, int j){
    if (skill[i] > skill[j]) return 0;
    return ((ll)(skill[j] - skill[i])) * ((ll)(skill[j] - skill[i]));
}


int main()
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    
    memset(dp, -1, sizeof(dp));
    int r;
    cin >> r;
    int n = 1 << r;

    fore(i,0,n){
        cin >> skill[i];
        dp[i][0] = 0;
    }

    fore(i,1,r+1){
        fore(j,0,n) dp[j][i] = 1e18;
        for(int j = 0; j < n; j += 1 << i){
            int l = j;
            int r = j + (1 << i);
            int mid = (r + l) / 2;
            fore(t1, l, mid){
                fore(t2, mid, r){
                    dp[t1][i] = min(dp[t1][i], dp[t1][i-1] + dp[t2][i-1] + costToBeat(t1, t2));
                    dp[t2][i] = min(dp[t2][i], dp[t1][i-1] + dp[t2][i-1] + costToBeat(t2, t1));
                }
            }
        }
    }
    cout << dp[0][r] << "\n";
    return 0;
}
