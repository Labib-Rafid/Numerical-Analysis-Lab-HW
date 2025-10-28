#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll N = 1e5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, k, i, j, q = 0, m, x;
    //cin >> ttt;
    while(ttt--){
        cin >> n;
        vector<vector<double>> v(n + 1, vector<double> (n + 2, 0));
        for(i = 0; i < n; ++i){
            for(j = 0; j <= n; ++j) cin >> v[i][j];
        }
        for(i = 0; i < n - 1; ++i){
            
            ll pivot = i;
            for(ll ni = i + 1; ni < n; ++ni)
                if(v[ni][i] > v[pivot][i])
                    pivot = ni;
            
            if(pivot != i) swap(v[pivot], v[i]);
            
            if(v[i][i] == 0.0){
                cout << "Error!!";
                return 0;
            }

            for(j = i + 1; j < n; ++j){
                double ratio = v[j][i] / v[i][i];
                for(k = 0; k <= n; ++k){
                    v[j][k] -= ratio * (v[i][k]);
                }
            }
        }

        //Back-Substitution
        vector<double>ans(n);
        ans[n - 1] = v[n-1][n] / v[n - 1][n - 1];
        for(i = n - 2; i >= 0; --i){
            ans[i] = v[i][n];
            for(j = i + 1; j < n; ++j){
                ans[i] -= v[i][j] * ans[j];
            }
            ans[i] /= v[i][i];
        }
        cout << "Ans:" << '\n';
        for(i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}

/*


*/
