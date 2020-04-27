#include <bits/stdc++.h>
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,hola=b;i<hola;i++)

using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int main()
{FIN;
    int T;
    cin >> T;
    int x = 0;
    while (T--){
        x++;
        int N;
        cin >> N;
        int mat [N][N];
        fore(i,0,N)
            fore(j,0,N)
                cin >> mat[i][j];
        int k = 0;
        int r = 0;
        int c = 0;
        fore(i,0,N){
            k += mat[i][i];
            bool countedRow = false;
            bool countedCol = false;

            set<int> row;
            set<int> col;
            fore(j,0,N){
                if(!countedRow){
                    if (row.count(mat[i][j])){
                        r++;
                        countedRow = true;
                    }
                    else
                        row.insert(mat[i][j]);
                }

                if (!countedCol){
                    if (col.count(mat[j][i])){
                        c++;
                        countedCol = true;
                    }
                    else
                        col.insert(mat[j][i]);
                }
            }
        }
        cout << "Case #" << x << ": " << k << " " << r << " " << c << "\n";
    }
    return 0;
}
