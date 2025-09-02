#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const double Tol = 1e-3;

double f(double x){
    double ans = pow(x, 5) - (3 * x) + 5;
    return ans;
}
double f_prime(double x){
    double ans = 5 * (pow(x, 4)) - 3;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll ttt = 1, i, j, k, n, m, q=0;
    //cin >> ttt;
    while (ttt--){
        double initialX = 2, prev = 0;
        while(1){
            double now = initialX - (f(initialX) / f_prime(initialX));
            prev = initialX;
            initialX = now;

            double err = fabs((initialX - prev) / (initialX));
            if(err < Tol)break;
        }
        cout << "Ans: " << initialX << endl;
    }
    return 0;
}
