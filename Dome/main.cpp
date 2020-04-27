#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

using namespace std;
double toDouble (string numb){
    double num = 0;
    bool decimal = false;
    int fsdfds = -1;
    fore(i,0,SZ(numb)){
        if (!decimal)
            num*=10;
        num += double();
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> dists;
    while (n--){
        string x, y, z;
        cin >> x >> y >> z;
        double xx, yy, zz;
        xx = atof(x.c_str());
        yy = atof(y.c_str());
        zz = atof(z.c_str());
        dists.pb(sqrt(xx*xx + yy*yy + zz*zz));
    }
    sort(dists.begin(), dists.end());

    cout << fixed << setprecision(10) << dists[k-1] << endl;

    return 0;
}
