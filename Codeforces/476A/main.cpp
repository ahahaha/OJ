#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int cnt;
    bool flag = false;
    for(int k = n / 2; k >= 0; k--) {
        cnt = k + n - 2 * k;
        if(cnt % m == 0) {
            flag = true;
            break;
        }
    }

    if(flag) cout << cnt << endl;
    else cout << "-1" << endl;

    return 0;
}
