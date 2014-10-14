#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int fact(int n) {
    if(n == 0) return 1;

    int ret = 1;
    for(int i = n; i > 0; i--)
        ret *= i;

    return ret;
}

int main() {
    string cmd1, cmd2;
    cin >> cmd1 >> cmd2;

    int np = 0, nn = 0;
    for(int i = 0; i < cmd1.size(); i++) {
        if(cmd1[i] == '+') np++;
        else nn++;
    }
    int pos1 = np - nn;

    np = nn = 0;
    int nu = 0;
    for(int i = 0; i < cmd2.size(); i++) {
        if(cmd2[i] == '+') np++;
        else if(cmd2[i] == '-') nn++;
        else nu++;
    }
    int pos2 = np - nn;

    bool flag = false;
    for(int i = np - nn + nu; i >= np - nn - nu; i -= 2) {
        if(i == pos1) flag = true;
    }

    if(flag) {
        int x, y;
        if(pos1 > pos2) {
            y = (nu - (pos1 - pos2)) / 2;
            x = nu - y;
        }else {
            x = (nu - (pos2 - pos1)) / 2;
            y = nu - x;
        }

        double ans = fact(x + y) / fact(x) / fact(y) * 1.0 / pow(2.0, x + y);
        cout << setprecision(10) << ans << endl;
    }else cout << "0.000000000" << endl;

    return 0;
}
