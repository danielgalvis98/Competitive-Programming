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

    int n;
    cin >> n;
    int max_pizzas = 0;
    int max_taxis = 0;
    int max_girls = 0;
    
    vector<string> pizzas;
    vector<string> taxis;
    vector<string> girls;

    while (n--){
        int si;
        cin >> si;
        string name;
        cin >> name;
        
        int hisPiz = 0;
        int hisTax = 0;
        int hisGirl = 0;
        while (si--){
            string numb;
            cin >> numb;
            
            if (numb[0] == numb[1] && numb[3] == numb[0] && numb[4] == numb[0]
                && numb[6] == numb[0] && numb[7] == numb[0]) hisTax++;
            else if (numb[1] < numb[0] && numb[3] < numb[1] && numb[4] < numb[3]
                && numb[6] < numb[4] && numb[7] < numb[6]) hisPiz++;
            else hisGirl++;

        }

        if (hisPiz > max_pizzas){
            max_pizzas = hisPiz;
            pizzas = {name};
        } else if (hisPiz == max_pizzas)
            pizzas.pb(name);
        
        if (hisTax > max_taxis){
            max_taxis = hisTax;
            taxis = {name};
        } else if (hisTax == max_taxis)
            taxis.pb(name);
        
        if (hisGirl > max_girls){
            max_girls = hisGirl;
            girls = {name};
        } else if (hisGirl == max_girls)
            girls.pb(name);
    }

    cout << "If you want to call a taxi, you should call: ";
    fore (i,0, SZ(taxis) - 1)
        cout << taxis[i] + ", ";
    cout << taxis[SZ(taxis) - 1] << ".\n";

    cout << "If you want to order a pizza, you should call: ";
    fore (i,0, SZ(pizzas) - 1)
        cout << pizzas[i] + ", ";
    cout << pizzas[SZ(pizzas) - 1] << ".\n";

    cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    fore (i,0, SZ(girls) - 1)
        cout << girls[i] + ", ";
    cout << girls[SZ(girls) - 1] << ".\n";

    return 0;
}
