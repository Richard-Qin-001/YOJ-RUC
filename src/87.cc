#include <bits/stdc++.h>
using namespace std;

struct Point {
    int R, G, B;
};

int n, m;
constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};

bool is_bad(const Point& p) {
    return p.R == 0 && p.G == 0 && p.B == 0;
}

int main() {
    cin >> n >> m;
    vector<vector<Point>> picture(n, vector<Point>(m));
    vector<pair<int, int>> bad_points;
    char ch;
    int r, g, b;
    for (int i = 0; i < n; ++i)for (int j = 0; j < m; ++j) {
            cin >> ch >> r >> ch >> g >> ch >> b;
            picture[i][j] = {r, g, b};
            if (r == 0 && g == 0 && b == 0)bad_points.emplace_back(i, j);
        }

    while (true) {
        vector<tuple<int, int, int, int, int>> updates;
        for (auto [x, y] : bad_points) {
            int R = 0, G = 0, B = 0, cnt = 0;
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !is_bad(picture[nx][ny])) {
                    R += picture[nx][ny].R;
                    G += picture[nx][ny].G;
                    B += picture[nx][ny].B;
                    ++cnt;
                }
            }
            if (cnt > 0) {
                updates.emplace_back(x, y, (R + cnt - 1) / cnt, (G + cnt - 1) / cnt, (B + cnt - 1) / cnt);
            }
        }

        if (updates.empty()) break;

        for (auto [x, y, R, G, B] : updates) {
            picture[x][y] = {R, G, B};
        }

        vector<pair<int, int>> new_bad_points;
        for (auto [x, y] : bad_points) {
            if (is_bad(picture[x][y]))
                new_bad_points.emplace_back(x, y);
        }
        bad_points = move(new_bad_points);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "R " << picture[i][j].R << " G " << picture[i][j].G << " B " << picture[i][j].B;
            if (j != m - 1) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}