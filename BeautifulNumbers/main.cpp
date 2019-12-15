#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i = a, end = b; i < end; i++)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
    FIN;
    int t;
    cin>>t;
    fore(cas, 0, t){
        int n;
        cin>>n;
        int perm [n];
        fore(i, 0, n){
            int numb;
            cin>>numb;
            perm[numb-1] = i;
        }
        int left = n;
        int right = -1;
        fore(i, 0, n){
            int index = perm[i];
            left = min(left, index);
            right = max(right, index);
            cout<<(right - left == i);
        }
        cout<<"\n";
    }


}
