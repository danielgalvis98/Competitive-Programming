#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int bin2int(string binary){
    int ans = 0;
    fore(i,0,32){
        if (binary[i] == '1')
            ans += (1 << i);
    }
    return ans;
}

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    int q;
    cin >> q;
    vector<int> l, r, tot;
    l.pb(-1);r.pb(-1);tot.pb(0);
    tot[0]++;
    int actPos = 0;
    cout << "a\n";
    for (int i = 31; i >= 0; i--){
        r[actPos] = SZ(r);
        l.pb(-1);r.pb(-1);tot.pb(0);
        actPos = r[actPos];
        tot[actPos]++;
    }
    cout << "b\n";
    fore(i,0,q){
        char mov; int numb;
        cin >> mov >> numb;
        int actPos = 0;
        if (mov == '+'){
            tot[0]++;
            for(int i = 31; i >= 0; i--){
                if (numb & (1 << i)){
                    if(l[actPos] == -1){
                        l[actPos] = SZ(l);
                        l.pb(-1);r.pb(-1);tot.pb(0);
                    }
                    actPos = l[actPos];
                    tot[actPos]++;
                } else {
                    if(r[actPos] == -1){
                        r[actPos] = SZ(r);
                        l.pb(-1);r.pb(-1);tot.pb(0);
                    }
                    actPos = r[actPos];
                    tot[actPos]++;
                }
            }
        } else if (mov == '-'){
            tot[0]--;
            for(int i = 31; i >= 0; i--){
                if (numb & (1 << i)){
                    actPos = l[actPos];
                    tot[actPos]--;
                } else {
                    actPos = r[actPos];
                    tot[actPos]--;
                }
            }
        } else {
            int actPos = 0;
            string ans = "";
            for(int i = 31; i >= 0; i--){
                //cout << actPos << "\n";
                bool isOne = numb & (1 << i);
                if ((isOne && r[actPos] != -1 && tot[r[actPos]] > 0) || (!isOne && (l[actPos] == -1 || tot[l[actPos]] == 0))){
                    ans.pb('0');
                    actPos = r[actPos];
                } else {
                    ans.pb('1');
                    actPos = l[actPos];
                }
            }
            int output = bin2int(ans);
            int toPrint = numb ^ output;
            cout << output << "\n";
            cout << toPrint << "\n";
        }
    }

    return 0;
}
