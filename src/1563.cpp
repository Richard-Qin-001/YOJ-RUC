#include <stdio.h>
#include <math.h>

// ____qcodep____
struct Point{
    double x;
    double y;
};

int main() {
    struct Point p1, p2;
    
    // 输入两个点的坐标
    scanf("%lf %lf", &p1.x, &p1.y);
    scanf("%lf %lf", &p2.x, &p2.y);

    // ____qcodep____
    double result = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    printf("%.3f", result);
    return 0;
}
