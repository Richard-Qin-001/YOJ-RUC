#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int a, b = 0;
struct Point
{
    int x, y;
};
struct Island
{
    vector<Point> rawland;
    vector<Point> treasures;
};

Island island;
vector<Island> valid_islands;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void visit_island(int x, int y)
{
    if (graph[x][y] == 0 || visited[x][y])
    {
        return;
    }
    if (graph[x][y] == 1)
    {
        island.rawland.push_back({x, y});
    }
    else if (graph[x][y] == 2)
    {
        island.treasures.push_back({x, y});
        island.rawland.push_back({x, y});
    }
    visited[x][y] = true;
    int nx, ny;
    for (int i = 0; i < 4; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && (!visited[nx][ny]))
        {
            visit_island(nx, ny);
        }
    }
}

double calculate_distance(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    graph.assign(N, vector<int>(M, 0));
    visited.assign(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (!visited[i][j])
            {
                if (graph[i][j] == 1 || graph[i][j] == 2)
                {
                    island.rawland.clear();
                    island.treasures.clear();
                    visit_island(i, j);
                    if (island.treasures.size() > 0)
                    {
                        valid_islands.push_back(island);
                    }
                }
                visited[i][j] = true;
            }
        }
    }
    a = valid_islands.size();
    int this_min = INT_MAX;
    int curr_min = 0;
    for (int i = 0; i < a; ++i)
    {
        island = valid_islands[i];
        this_min = INT_MAX;

        for (auto &p : island.rawland)
        {
            curr_min = 0;
            for (auto &q : island.treasures)
            {
                curr_min = max(curr_min, (int)calculate_distance(p, q));
                if (curr_min > this_min)
                    break;
            }
            this_min = min(curr_min, this_min);
        }
        b += this_min;
    }
    cout << a << " " << b << endl;
    return 0;
}