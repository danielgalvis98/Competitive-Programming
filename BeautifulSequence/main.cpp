#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{FIN;
    int numbers [4];
    cin >> numbers[0] >> numbers [1] >> numbers [2] >> numbers [3];
    int sum = numbers[0] + numbers[1] + numbers[2] + numbers [3];
    fore(i, 0, 4){
        if (numbers[i]){
            int index = i;
            vi ans;
            int clone [4];
            copy_n(numbers, 4, clone);
            while (true){
                ans.pb(index);
                clone[index]--;
                if (index != 0 && clone [index-1]){
                    index--;
                }
                else if (index < 3 && clone[index+1]){
                    index++;
                }
                else{
                    break;
                }
            }
            if (SZ(ans) == sum){
                cout << "YES\n";
                fore(i, 0, sum){
                    cout << ans[i] << " \n"[i == sum - 1];
                }
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
