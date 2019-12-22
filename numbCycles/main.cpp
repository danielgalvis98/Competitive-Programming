#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=0,end=b;i<end;i++)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int(s.size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int minElem(int numb){
    int ans = 0;
    int i = -1;
    while (ans==0)
        ans = numb&(1<<++i);
    return i;
}

int main()
{FIN;
    int n, m;
    cin>>n>>m;
    vector<set<int>> nodes(n);
    int limitMask = pow(2,n);
    ll dp[limitMask][n];
    fore(i,0,m){
        int x,y;
        cin>>x>>y;
        nodes[x-1].insert(y-1);
        nodes[y-1].insert(x-1);
    }
    fore(mask, 0, limitMask)
        fore(j,0,n)
            dp[mask][j]=0;

    fore(mask,0,limitMask){
        fore(i,0,n){
            int result = mask&(1<<i);
            if (__builtin_popcount(mask)==1 && result){
                dp[mask][i] = 1;
            }
            else if (__builtin_popcount(mask) > 1 && result && minElem(mask)!=i){
                for(auto adj: nodes[i]){
                    int result3 = mask^(1<<i);
                    dp[mask][i] += dp[result3][adj];
                }
            } else {
                dp[mask][i] = 0;
            }
        }
    }

    ll result=0;
    fore(i,0,n){
        fore(mask,0,limitMask){
            if (__builtin_popcount(mask)>=3){
                int mini = minElem(mask);
                auto resSearch = nodes[i].find(mini);
                if(resSearch != nodes[i].end()){
                    result += dp[mask][i];
                }
            }
        }
    }
    result/=2;
    cout<<result<<"\n";


    return 0;
}
