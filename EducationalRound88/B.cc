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
    int t;
    cin >> t;
    while (t--){
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        if (2*x < y)
            y = 2*x;
        
        bool square [n][m+1];
        fore(i,0,n){
            string row;
            cin >> row;
            fore(j,0,m)
                square[i][j] = row[j] == '.';
            square[i][m] = 0;
        } 
        int totalCost = 0;
        fore(i,0,n){
            int j = 0;
            while (j < m){
                if (square[i][j]){
                    if (square[i][j+1])
                        totalCost += y;
                    else
                        totalCost += x;
                    j++;
                }
                j++;
            }
        }
        cout << totalCost << "\n";
    }


    return 0;
}
