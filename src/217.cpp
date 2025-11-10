#include <bits/stdc++.h>

using i64 = long long;

struct Point {
    float x, y, z;
	Point() = default;
	Point(const float x, const float y, const float z) : x(x), y(y), z(z) {}
	Point(const int x, const int y, const int z) : x(x), y(y), z(z) {}
    friend bool operator<(const Point& U, const Point& V) {
        if (U.x != V.x) {
            return U.x < V.x;
        }
        if (U.y != V.y) {
            return U.y < V.y;
        }
        if (U.z != V.z) {
            return U.z < V.z;
        }
        return false;
    }
    friend bool operator==(const Point& U, const Point& V) {
        return U.x == V.x && U.y == V.y && U.z == V.z;
    }
    friend std::istream& operator>>(std::istream& is, Point& U) {
        is >> U.x >> U.y >> U.z;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, Point& U) {
        os << U.x << " " << U.y << " " << U.z;
        return os;
    }
    Point& operator+=(const Point& U) {
        x += U.x;
        y += U.y;
        z += U.z;
        return *this;
    }
    Point& operator-=(const Point& U) {
        x -= U.x;
        y -= U.y;
        z -= U.z;
        return *this;
    }
    Point& operator*=(const float k) {
        x *= k;
        y *= k;
        z *= k;
        return *this;
    }
    Point& operator/=(const float k) {
        x /= k;
        y /= k;
        z /= k;
        return *this;
    }
    friend Point operator+(const Point& U, const Point& V) {
        auto R = U;
        R += V;
        return R;
    }
    friend Point operator-(const Point& U, const Point& V) {
        auto R = U;
        R -= V;
        return R;
    }
    friend Point operator*(const Point& U, const float k) {
        auto R = U;
        R *= k;
        return R;
    }
    friend Point operator*(const float k, const Point& U) {
        auto R = U;
        R *= k;
        return R;
    }
    friend Point operator/(const Point& U, const float k) {
        auto R = U;
        R /= k;
        return R;
    }
    friend Point operator/(const float k, const Point& U) {
        auto R = U;
        R /= k;
        return R;
    }
    float operator()() {
        return sqrtl(x * x + y * y + z * z);
    }
};

using Vector = Point;

int dis_floor(Point U, Point V) {
    return floorl((U - V)());
}

i64 eval(Point U, const std::vector<Point>& IP) {
    i64 res = 0;
    for (const auto& V : IP) {
        res += dis_floor(V, U);
    }
    return res;
}

Point simulated_annealing(const std::vector<Point>& IP) {
    Point R;
	for (int i = 0; i < (int)IP.size(); ++i) {
		R.x += IP[i].x;
		R.y += IP[i].y;
		R.z += IP[i].z;
	}

	R.x /= IP.size();
	R.y /= IP.size();
	R.z /= IP.size();

    float temperature = 1E5;
    const float eps = 1E-6;
    const float cool = 0.997;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> disturb(-2147483648, 2147483647);
    std::uniform_real_distribution<> disturb_real;

    auto random_vector = [&](const float length = 1.0) {
        Point P;
        do {
            float x = disturb(gen);
            float y = disturb(gen);
            float z = disturb(gen);
            P = Point{x, y, z};
        } while (P == Point{0, 0, 0});
        P /= P();
        P *= length;
        return P;
    };

    while (temperature >= eps) {
        auto S = random_vector(temperature);
        auto T = R + S;

        auto eval_R = eval(R, IP);
        auto eval_T = eval(T, IP);
        auto delta = eval_T - eval_R;

        if (exp(-1.0 * delta / temperature) > disturb_real(gen)) {
            R = T;
        }

        temperature *= cool;
    }

    return R;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    Point A, B, C, D;
    std::cin >> A >> B >> C >> D;

    auto R = simulated_annealing({A, B, C, D});

	std::cerr << R << "\n";

    std::vector<std::tuple<int, int, int>> ans;
    i64 min = 9E18;

    const int U = 18;
    for (int X = R.x - U; X <= R.x + U; ++X) {
        for (int Y = R.y - U; Y <= R.y + U; ++Y) {
            for (int Z = R.z - U; Z <= R.z + U; ++Z) {
                auto cur = eval(Point(X, Y, Z), {A, B, C, D});
                if (cur < min) {
                    min = cur;
                    ans = {{X, Y, Z}};
                } else if (cur == min) {
                    ans.emplace_back(X, Y, Z);
                }
            }
        }
    }

    std::cout << min << " " << ans.size() << "\n";
    for (const auto& [X, Y, Z] : ans) {
        std::cout << X << " " << Y << " " << Z << "\n";
    }

    return 0;
}
