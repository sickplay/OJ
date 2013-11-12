#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <set>
using namespace std;
#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;


bool dp[2][21][10010];
int n;
int p[110];
int ans, ttl;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        ttl = 0; ans = 1e9;
        REP(i, n) scanf("%d", p+i), ttl += p[i];
        sort(p, p+n, greater<int>());
        int nw = 0, nxt = 1;
        memset(dp[nw], 0, sizeof(dp[nw]));
        dp[nw][10][5000] = 1;
        REP(i, n) {
            memset(dp[nxt], 0, sizeof(dp[nxt]));
            REP(j, 21) REP(k, 10001) if (dp[nw][j][k]) {
                if (20 == j && k-p[i]>=0) dp[nxt][19][k-p[i]] = 1;
                else if (0 == j && k+p[i]<=10000) dp[nxt][1][k+p[i]] = 1;
                else {
                    if (k+p[i] <= 10000) dp[nxt][j+1][k+p[i]] = 1;
                    if (k-p[i] >= 0) dp[nxt][j-1][k-p[i]] = 1;
                }
            }
            nw ^= 1;
            nxt ^= 1;
        }
        REP(i, 10001) for (int j = 9; j < 12; j++) if (dp[nw][j][i] && abs(5000-i) < ans) {
            ans = abs(5000-i);
        }
        printf("%d %d\n", (ttl-ans)>>1, (ttl+ans)>>1);
        if (tc != 0) printf("\n");
    }
    return 0;
}
