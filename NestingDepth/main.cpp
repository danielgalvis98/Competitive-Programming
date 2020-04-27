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
        string s;
        cin >> s;
        s = "0"+s+"0";
        string newS = "";
        fore(i,0,s.size()-1){
            if (i != 0) newS += s[i];
            char act = s[i];
            char next = s[i+1];
            if (act == next) continue;
            if (act > next){
                int dif = act - next;
                fore(j,0,dif)
                    newS += ")";
            } else {
                int dif = next - act;
                fore(j,0,dif)
                    newS += "(";
            }

        }
        cout << "Case #" << x  << ": " << newS << "\n";
    }
    return 0;
}
