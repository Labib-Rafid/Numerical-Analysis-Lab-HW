#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const double Tol = 1e-3;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ll ttt = 1, i, j, k, n, m, q=0;
    //cin >> ttt;
    while (ttt--){
        cout << "Enter Number Of Points: ";
        cin >> n;
        vector<double> x(n + 1), y(n + 1);
        cout << "Enter X Values: ";
        for(i = 0; i < n; ++i) cin >> x[i];
        cout << "Enter Y Values: ";
        for(i = 0; i < n; ++i) cin >> y[i];

        cout << "Value to interpolate: ";
        double val;
        cin >> val;

        double res = 0;
        for(i = 0; i < n; ++i){
            double now = 1.0;
            for(j = 0; j < n; ++j){
                if(i == j) continue;
                now *= (val - x[j]) / (x[i] - x[j]);
            }
            res += y[i] * now;
        }
        cout << "Result : " << res << endl;
    }
    return 0;
}
