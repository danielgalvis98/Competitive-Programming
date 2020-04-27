#include <bits/stdc++.h>

using namespace std;

int main()
{
    double vals [4];
    for (int i = 0; i < 4; i++){
        cin >> vals[i];
    }
    double t;
    cin >> t;
    t *= 3;
    sort(vals, vals + 4);

    double parSum = 0;
    for (int i = 1; i < 4; i++)
        parSum += vals[i];


    if (parSum <= t)
        cout << "infinite\n";
    else{
        parSum = 0;
        for (int i = 0; i < 3; i++)
            parSum += vals[i];
        if (parSum > t)
            cout << "impossible\n";
        else {
            parSum -= vals[0];
            double needed = t - parSum;
            cout << needed << "\n";
        }
    }
    return 0;
}
