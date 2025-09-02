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

        vector<vector<double>> dp(n + 1, vector<double> (n + 1, 0));

        for(i = 0; i < n; ++i) dp[i][0] = y[i];

        for(j = 1; j < n; ++j){
            for(i = 0; i < n - j; ++i){
                dp[i][j] = (dp[i + 1][j - 1] - dp[i][j - 1]) / (x[i + j] - x[i]);
            }
        }
        double res = dp[0][0];
        double now = 1.0;

        for(i = 1; i < n; ++i){
            //double k1 = dp[0][i] * (val - x[i - 1]);
            now *= (val - x[i - 1]);
            res += (now * dp[0][i]);
        }
        cout << "Result: " << res << endl;

    }
    return 0;
}
