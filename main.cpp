#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include "unordered_map"

using namespace std;

class Solution {
public:
    vector<vector<int>> cache;
    int n;
    int mod = 1000000007;
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        n = locations.size();
        cache.resize(n, vector<int>(fuel + 1, -1));
        return dfs(locations, start, finish, fuel);
    }

    int dfs(vector<int> &locations, int start, int end, int fuel) {

        if (cache[start][fuel] != -1) {
            return cache[start][fuel];
        }

        if (fuel == 0 && start != end) {
            cache[start][fuel] = 0;
            return 0;
        }
        bool signal = false;
        for (int i = 0; i < n; i++) {
            if (fuel >= locations[i]) {
                signal = true;
                break;
            }
        }
        if (!signal) {
            int a = cache[start][fuel] = start == end ? 1 : 0;
            return a;
        }

        int res = start == end ? 1 : 0;
        for(int i = 0; i < n; i++){
            if(i == start) continue;
            int need = abs(locations[start] - locations[i]);
            if (fuel - need < 0) continue;
            res += dfs(locations, i, end, fuel - need);
            res %= mod;
        }
        cache[start][fuel] = res;
        return res;
    }
};

int main() {
    Solution s;
}
/*
[1,0,1,1]
2
[10,2,5]
[10,9,5]

*/