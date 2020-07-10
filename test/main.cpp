#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<ll,ll> ii;
struct Comp {
  bool operator()(const std::pair<ll, ll> &a, const std::pair<ll, ll> &b) {
    if (a.first != b.first) {
      return a.first > b.first;
    }
    return a.second < b.second;
  }

};
typedef tree < ii ,  string ,  Comp ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;

int main(){FIN;
    ll cnt_id=0;
    int N; cin>>N;
    map<string,ii> mp;
    ordered_set ordSet;
    while(N--){
        string comand,code; cin>>comand;
        if(comand == "ISSUE"){
            cin>>code;
            auto it = mp.find(code);
            if(it == mp.end()){
                mp[code]={cnt_id,0};
                ordSet[{0,cnt_id}]=code;
                cout<<"CREATED "<<cnt_id<<" 0\n";
                cnt_id++;
            }else{
                ii curr= it->second ;
                cout<<"EXISTS "<<curr.ff<<" "<<curr.ss<<"\n";
            }
        }else if(comand=="DELETE"){
            cin>>code;
            auto it = mp.find(code);
            if(it == mp.end()){

                cout<<"BAD REQUEST\n";
            }else{
                ii curr= it ->second ;
                mp.erase(it);
                auto it2 = ordSet.find({curr.ss,curr.ff});
                ordSet.erase(it2);
                cout<<"OK "<<curr.ff<<" "<<curr.ss<<"\n";
            }
        }else if(comand =="RELIABILITY"){
            cin>>code;
            ll m; cin>>m;
            auto it = mp.find(code);
            if(it == mp.end()){
                cout<<"BAD REQUEST\n";
            }else{
                ii curr= it ->second ;
                ii newP= {curr.ff,curr.ss+m};
                mp.erase(it);
                mp[code]=newP;
                auto it2 = ordSet.find({curr.ss,curr.ff});
                ordSet.erase(it2);
                ordSet[{newP.ss, newP.ff}]=code;
                cout<<"OK "<<newP.ff<<" "<<newP.ss<<"\n";
            }
        }else if(comand == "FIND"){
            int kth; cin>>kth;
            if(sz(mp)==0){
                cout<<"EMPTY\n";
            }else{
                kth=min(kth,sz(ordSet)-1);
                auto found= ordSet.find_by_order(kth);
                cout<<"OK "<<found->second<<" "<<(found->first).ss<<" "<<(found->first).ff<<"\n";
            }
        }
    }
    return 0;
}
