#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    pair <int, int> comodin = {0,1e9};
    while(t--){
        map <pair<int, int>, int> paths;
        pair<int,int> ans = comodin;
        pair <int, int> act = {0,0};
        paths.insert({{0,0}, 0});
        int n;
        cin >> n;
        string path;
        cin >> path;
        for (int i = 0; i < n; i++){
            char actC = path[i];
            if (actC == 'L')
                act.first--;
            else if (actC == 'R')
                act.first++;
            else if (actC == 'U')
                act.second++;
            else
                act.second--;

            if (paths.find(act) == paths.end())
                paths.insert({act,i+1});
            else {
                int l = paths.find(act) -> second;
                if (i+1 - l < ans.second - ans.first)
                    ans = {l+1, i+1};
                paths.insert({act, i+1});
            }
        }
        if (ans == comodin)
            cout << "-1\n";
        else
            cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}
