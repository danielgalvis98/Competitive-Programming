#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define SZ(s) int(s.size())
#define pb push_back
#define ALL(s), s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int>ii;

int main()
{FIN;
    int n,m;
    cin>>n>>m;
    ll tot[n];
    memset(tot,0,sizeof(tot));
    fore(i,0,m){
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        tot[x]-=z;
        tot[y]+=z;
    }

    set<pair<int,ll>> pos;
    set<pair<int,ll>> neg;

    fore(i,0,n){
        if(tot[i]>0) pos.insert({i, tot[i]});
        else if (tot[i]<0) neg.insert({i, tot[i]});
    }
    vector<pair<ll,ii>> ans;
    while(SZ(pos)){
        auto receives = *pos.rbegin();
        auto gives = *neg.begin();

        pos.erase(receives);
        neg.erase(gives);
        ll result = receives.snd + gives.snd;
        ans.pb({min(receives.snd, abs(gives.snd)), {gives.fst,receives.fst}});
        if (result > 0)
            pos.insert({receives.fst, result});
        else if (result < 0)
            neg.insert({gives.fst, result});
    }
    cout<<SZ(ans)<<"\n";
    for(auto pr: ans)
        cout<<pr.snd.fst + 1<<" "<<pr.snd.snd + 1<<" "<<pr.fst<<"\n";
    return 0;
}
