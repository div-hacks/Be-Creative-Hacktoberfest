#include <bits/stdc++.h>
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define sqr(a) (1LL * (a) * (a))
using namespace std;

#ifdef LOCAL
#include <bug.h>
#else
#define mt(...)
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1000000007;
const int inf = 0x3f3f3f3f;

// https://www.codechef.com/JAN13/problems/LEALCO
//-----------------------------------------------------------------------//

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int tt;
    cin >> tt;
    auto check = [](vector<int> &arr, int n, int k, int m) {
        for (int i = 0; i <= n - k; ++i) {
            int curr_max = -inf;
            int cnt = 0;
            for (int j = i; j < i + k; ++j) {
                if (arr[j] == curr_max) cnt++;
                else if (arr[j] > curr_max) {
                    curr_max = arr[j];
                    cnt = 1;
                }
            }
            // mt(i, cnt)
            if (cnt >= m) return false;
        }
        return true;

    };
    while (tt-- > 0) {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> arr(n);
        for (int &r : arr) {
            cin >> r;
        }
        int res = inf;
        for (int mask = 0; mask < (1 << n); ++mask) {
            vector<int> add;
            add.reserve(__builtin_popcount(mask));
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    add.emplace_back(i);
                }
            }
            for (int &i : add) {
                arr[i]++;
            }
            if (check(arr, n, k, m)) {
                res = min(res, (int) add.size());
            }
            for (int &i : add) {
                arr[i]--;
            }
        }
        cout << (res == inf ? -1 : res) << '\n';

    }
    
        

    return 0;
}