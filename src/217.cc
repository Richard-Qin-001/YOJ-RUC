#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Point{
    double x;
    double y;
    double z;
};
// struct Range_d
// {
//     double left; double right;
// };
struct ResultPoint
{
    int x, y, z;
    ResultPoint(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
};

double epsilon = 1e-6;
vector<Point> P(4);
// Range_d x_range = {0.0, 0.0}, y_range = {0.0, 0.0}, z_range = {0.0, 0.0};

double calculate_distance(const Point& A, const Point& B){
    double distance = 0;
    double x_d = pow((A.x - B.x), 2);
    double y_d = pow((A.y - B.y), 2);
    double z_d = pow((A.z - B.z), 2);
    distance = sqrt(x_d+y_d+z_d);
    return distance;
}

Point Weiszfeld(const vector<Point>& P_points) {
    Point P_current = {
        (P_points[0].x + P_points[1].x + P_points[2].x + P_points[3].x) / 4.0,
        (P_points[0].y + P_points[1].y + P_points[2].y + P_points[3].y) / 4.0,
        (P_points[0].z + P_points[1].z + P_points[2].z + P_points[3].z) / 4.0
    };  
    Point P_next;
    while (true) {
        double sum_weights_inv = 0.0;
        double sum_x = 0.0;
        double sum_y = 0.0;
        double sum_z = 0.0;
        for (int i = 0; i < 4; ++i) {
            double d = calculate_distance(P_current, P_points[i]);
            if (d < epsilon) { 
                return P_current;
            }
            double weight = 1.0 / d;
            sum_weights_inv += weight;
            sum_x += P_points[i].x * weight;
            sum_y += P_points[i].y * weight;
            sum_z += P_points[i].z * weight;
        }
        P_next.x = sum_x / sum_weights_inv;
        P_next.y = sum_y / sum_weights_inv;
        P_next.z = sum_z / sum_weights_inv;

        if (calculate_distance(P_next, P_current) < epsilon)break;

        P_current = P_next;
    }

    return P_current;
}

bool compareResultPoints(const ResultPoint& a, const ResultPoint& b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

ll calculate_total_distance(const Point&P_search, const vector<Point>&P_points){
    ll total_distance = 0;
    for(int i = 0; i < 4; i++){
        double d_axis = calculate_distance(P_search, P[i]);
        total_distance += (ll)floor(d_axis);
    }
    return total_distance;
}

void solve(){
    for(int i = 0; i < 4; i++){
        Point Pk;
        cin >> Pk.x >> Pk.y >> Pk.z;
        P[i] = Pk;
    }
    // for(int i = 0; i < 3; i++){
    //     x_range.left = min(x_range.left, P[i].x);
    //     x_range.right = max(x_range.right, P[i].x);
    //     y_range.left = min(y_range.left, P[i].y);
    //     y_range.right = max(y_range.right, P[i].y);
    //     z_range.left = min(z_range.left, P[i].z);
    //     z_range.right = max(z_range.right, P[i].z);
    // }
    // Point start_point = {
    //     (P[0].x + P[1].x + P[2].x + P[3].x) / 4,
    //     (P[0].y + P[1].y + P[2].y + P[3].y) / 4,
    //     (P[0].z + P[1].z + P[2].z + P[3].z) / 4,
    // };
    Point fermat_point = Weiszfeld(P);
    int center_x = (int)floor(fermat_point.x);
    int center_y = (int)floor(fermat_point.y);
    int center_z = (int)floor(fermat_point.z);

    const int R = 15;

    ll min_total_distance = -1;
    vector<ResultPoint> best_points;

    for(int x = center_x - R; x <= center_x + R; x++)for(int y = center_y - R; y <= center_y + R; y++)for(int z = center_z - R; z <= center_z + R; z++){
        Point P_search = {(double)x, (double)y, double(z)};
        ll current_distance = calculate_total_distance(P_search, P);
        if(min_total_distance == -1 || current_distance < min_total_distance){
            min_total_distance = current_distance;
            best_points.clear();
            best_points.push_back(ResultPoint(x, y, z));
        }
        else if(current_distance == min_total_distance) best_points.push_back(ResultPoint(x, y, z));
    }
    sort(best_points.begin(), best_points.end(), compareResultPoints);
    cout << min_total_distance << " " << best_points.size() << endl;
    for (const auto& p : best_points) {
        cout << p.x << " " << p.y << " " << p.z << endl;
    }
}
int main(){solve(); return 0;}