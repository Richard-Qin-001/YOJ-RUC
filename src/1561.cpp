#include<iostream>
#include<math.h>
#include<iomanip>
#include<cmath>
using namespace std;

// ____qcodep____
double compute_dis(double x1, double y1, double z1, double x2, double y2, double z2){
    double result = 0.0;
    result = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return result;
}

int main()
{
	double x1,y1,z1,x2,y2,z2,ans;
	cin>>x1>>y1>>z1>>x2>>y2>>z2;
	ans=compute_dis(x1,y1,z1,x2,y2,z2);
	cout<< fixed << setprecision(1) <<ans<<' ';
	return 0;
}