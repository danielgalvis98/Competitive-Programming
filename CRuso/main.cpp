#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int N;
    cin >> N;
    set<int> perc;
    for (int i = 0; i <N;i++){
        int p;
        cin >> p;
        perc.insert(p);
    }

    int ans = -1;
    for (int i = 1; i <= 100; i++){
        set<int> copyPer = perc;
        for (int j = 0; j <= i; j++){
            int result = round((j*100.0)/i);
            copyPer.erase(result);
        }
        if (copyPer.empty()){
            ans = i;
            break;
        }
    }
    cout << ans << "\n";


    return 0;
}
