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
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        map<int, int> options;
        for(char act: s){
            if(options.count(act - 'a'))
                options[act-'a']++;
            else
                options[act-'a'] = 1;
        }
        int m;
        cin >> m;
        int difs [m];
        char ans [m];
        vi posZeroes;
        fore(i,0,m){
            cin >> difs[i];
            if(!difs[i])
                posZeroes.pb(i);
        }
        for (auto it = options.rbegin(); it != options.rend(); ++it){
            if ((it -> second) >= SZ(posZeroes)){
                vi newPosZeroes;
                for(int pos: posZeroes){
                    ans[pos] = (it -> first) + 'a';
                    fore(i,0,m){
                        if(difs[i]){
                            difs[i] -= abs(i-pos);
                            if (!difs[i])
                                newPosZeroes.pb(i);
                        }
                    }
                }
                posZeroes = newPosZeroes;
            }
            if(!SZ(posZeroes))
                break;
        }
        for(char act: ans)
            cout << act;
        cout << "\n";
    }
    return 0;
}