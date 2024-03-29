#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int n, m;
int board[500][500];
pair<int, int> border[19] = { // 기준이 되는 칸의 범위
    {3, 0}, {0, 3}, {1, 1}, {2, 1},
    {2, 1}, {1, 2}, {1, 2}, {1, 2},
    {1, 2}, {2, 1}, {1, 2}, {2, 1},
    {1, 2}, {1, 2}, {2, 1}, {1, 2},
    {2, 1}, {2, 1}, {2, 1}
};
pair<int, int> pos[19][4] = { // 기준이 되는 칸으로부터 거리가 이 값만큼 떨어진 칸
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},

    {{0, 1}, {1, 1}, {2, 0}, {2, 1}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {1, 2}},

    {{0, 2}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}, {1, 1}},
    {{0, 1}, {1, 0}, {1, 1}, {2, 0}},

    {{0, 0}, {0, 1}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {0, 2}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
    {{0, 1}, {1, 0}, {1, 1}, {1, 2}},

    {{0, 1}, {1, 0}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}}
};

int calculate(int p) { // p번째 테트로미노를 놓았을 때의 최댓값 구하기
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n-border[p].X; i++) {
        for (int j = 0; j < m-border[p].Y; j++) {
            for (int k = 0; k < 4; k++) sum += board[i+pos[p][k].X][j+pos[p][k].Y];
            ans = max(sum, ans);
            sum = 0;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < 19; i++) ans = max(ans, calculate(i)); // 모든 테트로미노에 대해 최댓값 구하기

    cout << ans;
}