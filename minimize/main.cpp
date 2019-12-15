#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, end=b;i<end;i++)
#define pb push_back
#define ALL(s), s.begin(),s.end()
#define SZ(s) int(s.size())
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{FIN;
    int q;
    cin >> q;
    while (q--){
        int n;
        cin>>n;
        vi oldArray(n);
        fore(i,0,n){
            cin>>oldArray[i];
        }
        int last = 0;

        while (last < n){
            int pos = min_element(oldArray.begin()+last, oldArray.end())-oldArray.begin();
            int elem = oldArray[pos];
            oldArray.erase(oldArray.begin() + pos);
            oldArray.insert(oldArray.begin()+last, elem);
            if (pos == last) last++;
            else last = pos;
        }
        fore(i,0,n)
            cout<<oldArray[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
