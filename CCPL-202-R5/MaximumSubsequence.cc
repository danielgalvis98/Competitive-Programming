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
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> ii;

int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        #define endl '\n'
    #endif

    int N, K;
    cin >> N >> K;
    while (N != 0){

        vl nums(N), pos, neg;
        fore(i,0,N){
            cin >> nums[i];
            if(nums[i] > 0) pos.pb(nums[i]);
            else if (nums[i] < 0) neg.pb(nums[i]);
        }
        vl sumPos(SZ(pos)), sumNeg(SZ(neg));
        vd multPos(SZ(pos)), multNeg(SZ(neg));

        sort(ALL(nums));
        sort(ALL(pos));
        sort(ALL(neg));
        reverse(ALL(nums));
        reverse(ALL(pos));

        pair<double, ll> ans = {-1e18, -1e18};
        fore(i,0,SZ(pos)){
            sumPos[i] = pos[i];
            multPos[i] = log(pos[i]);
            if (i){
                sumPos[i] += sumPos[i-1];
                multPos[i] += multPos[i-1];
            } 
        }
        
        fore(i,0,SZ(neg)){
            sumNeg[i] = neg[i];
            multNeg[i] = log(abs(neg[i]));
            if (i){
                sumNeg[i] += sumNeg[i-1];
                multNeg[i] += multNeg[i-1];
            } 
        }


        for (int totNeg = 0; totNeg <= K && totNeg <= SZ(neg); totNeg += 2){
            int totPos = K - totNeg;
            if (totPos <= SZ(pos)){
                pair<double, ll> act = {0,0};
                if (totPos){
                    act.fst += multPos[totPos-1];
                    act.snd += sumPos[totPos-1];
                }

                if (totNeg){
                    act.fst += multNeg[totNeg-1];
                    act.snd += sumNeg[totNeg-1];
                }
                ans = max(ans, act);
            }
        }


        if (ans.fst == -1e18){
            ll sum = 0;
            fore(i,0,K) sum += nums[i];
            ans.snd = sum;
        }

        cout << ans.snd << "\n";

        cin >> N >> K;
    }

    


    return 0;
}
