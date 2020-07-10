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

struct problem {
    int p, t, i;
};

bool compareProblems (problem &a, problem &b){
    return a.p*b.t < b.p*a.t;
}

problem problems [105];
ii dp[105][1005];
int n;

vector<int> solution;
void reconstructSolution(int i, int tLess){
    if (i==0) return;
    if (dp[i][tLess] == dp[i-1][tLess]){
        reconstructSolution(i-1, tLess);
    }
    else{
        solution.pb(problems[i-1].i);
        reconstructSolution(i-1, tLess - problems[i-1].t);
    }
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int tmax;
    cin >> n >> tmax;
    fore(i,0,n){
        cin >> problems[i].t;
        cin >> problems[i].p;
        problems[i].i = i+1;
    }
    sort(problems, problems+n, compareProblems);
    
    fore(i,1,n+1){
        fore(j,0,tmax+1){
            if (i == 0 || j == 0){
                dp[i][j] = {0,0};
                continue;
            }
            dp[i][j] =  dp[i-1][j];
            if  (problems[i-1].t <= j)
                dp[i][j] = max(dp[i][j], {dp[i-1][j - problems[i-1].t].first + problems[i-1].p,
                                dp[i-1][j - problems[i-1].t].second - (problems[i-1].t+tmax-j)*problems[i-1].p});
        }
    }
    
    fore(i,0,n+1){
        fore(j,0,tmax+1){
            cout << "{"<<dp[i][j].first << ", " << dp[i][j].snd << "} ";
        }
        cout << endl;
    }

    reconstructSolution(n,tmax);
    cout << SZ(solution) << "\n";
    if (SZ(solution)){
        cout << solution[0];
        fore(i,1,SZ(solution))
            cout << " " << solution[i];
        cout << "\n";
    }
    return 0;
}
