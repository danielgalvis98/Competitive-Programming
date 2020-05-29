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
 
    int cas;
    cin >> cas;
    while (cas--){
        ll h, c, t;
        cin >> h >> c >> t;
 
        ll min = 1;
        ll max = 1e8;
        ll mid = 0;
        double bestTemp = (h + c) / 2.0;
        ll bestMid = -1;
        while(min <= max){
            mid = min + (max - min)/2.0;
            double temp = (mid*h + (mid-1)*c) / (double)(2*mid - 1);
            if (abs(temp - t) < abs(bestTemp - t)){
                bestTemp = temp;
                bestMid = mid;
            } else if (abs(temp - t) == abs(bestTemp - t) && mid < bestMid){
                bestTemp = temp;
                bestMid = mid;
            }
            //cout << mid << ": " << temp << endl;
            if (temp > t)
                min = mid+1;
            else
                max = mid-1; 
        }
        
        if (bestMid != -1)
            cout << 2*bestMid - 1 << "\n";
        else
            cout << "2\n";
    }   
 
    return 0;
}