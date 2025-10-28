#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const ll N = 1e5;

double f(double x, double y){
    return x * y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll ttt = 1, n, k, i, j, q = 0, m, x;
    //cin >> ttt;
    while(ttt--){
        double x = 1, y = 1, h = 0.1, tar = 1.5;
        while(x < tar){
            y += h * f(x, y);
            x += h;
        }
        cout << y << '\n';
    }
}

/*


*/
