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
        char ans [N];
        set<pair<ii,int>> times;
        fore(i,0,N){
            int S;
            int E;
            cin >> S;
            cin >> E;
            times.insert({{S,E},i});
        }
        int C=0;
        int J=0;
        bool possible = true;
        for (auto act: times){
            if (act.fst.fst >= C){
                ans[act.snd] = 'C';
                C = act.fst.snd;
            }
            else if (act.fst.fst >= J){
                ans[act.snd] = 'J';
                J = act.fst.snd;
            } else {
                possible = false;
                break;
            }
        }
        cout << "Case #" << x << ": ";
        if (!possible)
            cout << "IMPOSSIBLE\n";
        else{
            fore(i,0,N)
                cout << ans[i] << "";
            cout << "\n";
        }
    }
    return 0;
}
