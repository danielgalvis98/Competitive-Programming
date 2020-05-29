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

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int t,p;
    cin >> t >> p;
    double strengths [t-1];
    double difficulty[p];
    
    double dp [t-1][p+1];

    fore(i,0,t-1)
        cin >> strengths[i];

    fore (i,0,p)
        cin >> difficulty[i];
    
    memset(dp, 0, sizeof dp);

    fore(i,0,t-1){
        dp[i][0] = 1;
        fore(j,0,p){
            double probSolved=0;
            char stateProblem;
            cin >> stateProblem;
            if (stateProblem == 'X')
                probSolved = 1;
            else if (stateProblem == '-')
                probSolved = 0;
            else
                probSolved = strengths[i]*difficulty[j];
            for (int k = p; k >= 0; k--){
                dp[i][k] *= (1-probSolved);
                if (k != 0)
                    dp[i][k] += dp[i][k-1]*probSolved;
            }

        }
    }
    int totSolved = 0;
    fore(i,0,p){
        char act;
        cin >> act;
        totSolved += act == 'X';
    }

    double probWin = 1;

    fore(i,0,t-1){
        double probSumTeam = 0;
        fore(j,totSolved+1, p+1)
            probSumTeam += dp[i][j];
        
        probWin *= 1-probSumTeam;
    }

    cout << fixed << setprecision(6) << probWin <<"\n";

    return 0;
}
