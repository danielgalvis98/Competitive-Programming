#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<b;i++)
#define ALL(s) s.begin(),s.end()
#define pb push_back
#define SZ(s) int(s.size())
#define FIN ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{FIN;
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int dists [n][m];
        queue<ii> q;
        fore(i, 0, n){
            string l;
            cin>>l;
            fore(j,0,m){
                if(l[j]=='1'){
                    dists[i][j]=0;
                    q.push({i,j});
                }
                else
                    dists[i][j]=1e9;
            }
        }

        while(SZ(q)){
            ii act = q.front();
            q.pop();
            int x = act.fst;
            int y = act.snd;
            if (x != 0 && dists[x-1][y] > dists[x][y]+1){
                dists[x-1][y] = dists[x][y] + 1;
                q.push({x-1,y});
            }
            if (x != n-1 && dists[x+1][y] > dists[x][y]+1){
                dists[x+1][y] = dists[x][y] + 1;
                q.push({x+1,y});
            }
            if(y != 0 && dists[x][y-1] > dists [x][y] + 1){
                dists[x][y-1] = dists[x][y] + 1;
                q.push({x, y-1});
            }
            if (y != m-1 && dists[x][y+1] > dists[x][y]+1){
                dists[x][y+1] = dists[x][y] + 1;
                q.push({x,y+1});
            }
        }

        fore(i,0,n){
            fore(j,0,m){
                cout<<dists[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
    return 0;
}
