#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<end;i++)
#define pb push_back
#define ALL(s), s.begin(),s.end()
#define SZ(s) int(s.size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main()
{FIN;
    int T;
    cin>>T;

    while(T--){
        int N;
        int M;
        cin>>N;
        cin>>M;
        int mat [N][M];
        int result [N][M];

        vector<ii> indMaxs;
        int maxAct = -1;
        fore(i,0,N){
            fore(j,0,M){
                cin>>mat[i][j];
                if (mat[i][j]==maxAct)
                    indMaxs.pb({i,j});
                else if (mat[i][j] > maxAct){
                    maxAct = mat[i][j];
                    indMaxs.clear();
                    indMaxs.pb({i,j});
                }
                result[i][j]=1e9;
            }
        }

        queue<ii> q;
        for(auto it: indMaxs){
            q.push(it);
            result[it.fst][it.snd]=0;
        }
        int maxHour=0;

        while (SZ(q)){
            ii ind = q.front();
            q.pop();
            int x = ind.fst;
            int y = ind.snd;
            maxHour = max(maxHour, result[x][y]);
            if (x != 0){
                if (result[x-1][y] > result[x][y]+1){
                    result[x-1][y] = result[x][y] + 1;
                    q.push({x-1,y});
                }

                if (y != 0 && result[x-1][y-1] > result[x][y] + 1){
                    result[x-1][y-1] = result[x][y] + 1;
                    q.push({x-1,y-1});
                }

                if (y != M-1 && result[x-1][y+1] > result[x][y] + 1){
                    result[x-1][y+1] = result[x][y] + 1;
                    q.push({x-1,y+1});
                }
            }

            if (x != N-1){
                if (result[x+1][y] > result[x][y]+1){
                    result[x+1][y] = result[x][y] + 1;
                    q.push({x+1,y});
                }

                if (y != 0 && result[x+1][y-1] > result[x][y] + 1){
                    result[x+1][y-1] = result[x][y] + 1;
                    q.push({x+1,y-1});
                }

                if (y != M-1 && result[x+1][y+1] > result[x][y] + 1){
                    result[x+1][y+1] = result[x][y] + 1;
                    q.push({x+1,y+1});
                }
            }

            if (y != 0 && result[x][y-1] > result[x][y] + 1){
                result[x][y-1] = result[x][y] + 1;
                q.push({x,y-1});
            }

            if (y != M-1 && result[x][y+1] > result[x][y] + 1){
                result[x][y+1] = result[x][y] + 1;
                q.push({x,y+1});
            }

        }
        cout << maxHour << "\n";
    }
    return 0;
}
