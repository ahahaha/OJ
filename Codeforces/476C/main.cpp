#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;

//    ll ans = (((a * b % MOD + b + 2) * a % MOD) * b % MOD) * (b - 1) / 4 % MOD;
    ll ans = ((((a * b % MOD + b + 2) * a % MOD) * b % MOD) * (b - 1) % MOD) * 250000002 % MOD;
    cout << ans << endl;

    return 0;
}
