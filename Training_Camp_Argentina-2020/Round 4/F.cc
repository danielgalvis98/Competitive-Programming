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
ii obj_coordinates [30];

ll dp[(1 << 24) + 5];
int n;
int x0,y0;
vector<int> camino;
ll go(int mask){
    if (mask == (1 << n)-1)
        return 0;
    ll &r = dp[mask];
    if (r != -1)
        return r;
    ll act_min = 1e18;
    for (int i = 0; i < n; i++){
        if (mask & (1 << i))
            continue;
        for (int j = i+1; j < n; j++){
            if (mask & (1 << j))
                continue;
            ll dist_to_recover = (x0-obj_coordinates[i].ff)*(x0-obj_coordinates[i].ff) + (y0-obj_coordinates[i].ss)*(y0-obj_coordinates[i].ss)
                + (x0-obj_coordinates[j].ff)*(x0-obj_coordinates[j].ff) + (y0-obj_coordinates[j].ss)*(y0-obj_coordinates[j].ss)
                + (obj_coordinates[j].ff-obj_coordinates[i].ff)*(obj_coordinates[j].ff-obj_coordinates[i].ff) + (obj_coordinates[j].ss-obj_coordinates[i].ss)*(obj_coordinates[j].ss-obj_coordinates[i].ss);
            
            dist_to_recover += go((mask | (1 << i)) | (1 << j));
            act_min = min(act_min, dist_to_recover);
        }
        ll dist_to_recover = 2*((x0-obj_coordinates[i].ff)*(x0-obj_coordinates[i].ff) + (y0-obj_coordinates[i].ss)*(y0-obj_coordinates[i].ss));
        dist_to_recover += go(mask | (1 << i));
        act_min = min(act_min, dist_to_recover);
        break;
    }
    return r = act_min;
}

ll construir_solucion (int mask){
     if (mask == (1 << n) -1)
        return 0;
    
    ll &r  = dp[mask];
    bool found = 0;
    for (int i = 0; i < n; i++){
        if (mask & (1<<i))
            continue;
        for (int j = i+1; j < n; j++){
            if (mask & (1 << j))
                continue;
            ll dist_to_recover = (x0-obj_coordinates[i].ff)*(x0-obj_coordinates[i].ff) + (y0-obj_coordinates[i].ss)*(y0-obj_coordinates[i].ss)
                + (x0-obj_coordinates[j].ff)*(x0-obj_coordinates[j].ff) + (y0-obj_coordinates[j].ss)*(y0-obj_coordinates[j].ss)
                + (obj_coordinates[j].ff-obj_coordinates[i].ff)*(obj_coordinates[j].ff-obj_coordinates[i].ff) + (obj_coordinates[j].ss-obj_coordinates[i].ss)*(obj_coordinates[j].ss-obj_coordinates[i].ss);
            int new_mask = mask | (1 << i) | (1 << j);
            //cout << "Aca es " << dist_to_recover + dp[new_mask] << " and r is " << r << endl;
            if (dist_to_recover + dp[new_mask] <= r){
                camino.pb(0);camino.pb(i+1);camino.pb(j+1);
                construir_solucion(new_mask);
                found = 1;
                break;
            }
        }
        if (!found){
            camino.pb(0);camino.pb(i+1);
            construir_solucion(mask | (1 << i));
        }
        break;
    }
    
    return r;
}

int main()
{FIN;
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif
    cin >> x0 >> y0 >> n;
    fore(i,0,n)
        cin >> obj_coordinates[i].ff >> obj_coordinates[i].ss;

    memset(dp, -1, sizeof dp);
    cout << go(0) << "\n";
    construir_solucion(0);
    camino.pb(0);
    fore(i,0,SZ(camino)){
        cout << camino[i] << " ";
    }
    cout << "\n";


    return 0;
}
