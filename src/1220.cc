#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double calculate_point(int score, int class_score){
    double result = 0.0;
    if(score >= 90) result += 4.0 * class_score;
    else if(score >= 86 && score <= 89) result += 3.7 * class_score;
    else if(score >= 83 && score <= 85) result += 3.3 * class_score;
    else if(score >= 80 && score <= 82) result += 3.0 * class_score;
    else if(score >= 76 && score <= 79) result += 2.7 * class_score;
    else if(score >= 73 && score <= 75) result += 2.3 * class_score;
    else if(score >= 70 && score <= 72) result += 2.0 * class_score;
    else if(score >= 66 && score <= 69) result += 1.7 * class_score;
    else if(score >= 63 && score <= 65) result += 1.3 * class_score;
    else if(score >= 60 && score <= 62) result += 1.0 * class_score;
    else result += 0.0 * class_score;
    result = round(result * 10.0) / 10.0;
    return result;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> class_score(m);
    for(auto&c:class_score) cin >> c;
    vector<vector<double>> students(n, vector<double>(3,0));
    for(int i = 0; i < n; i++){
        cin >> students[i][0];
        for(int j = 0; j < m; j++){
            int score;
            cin >> score;
            students[i][1] += calculate_point(score, class_score[j]);
        }
        students[i][1] = round(students[i][1] * 10.0) / 10.0;
    }
    int rank = 1; double current_max = -1.0;
    vector<int> max_index;
    vector<vector<double>> students_copy = students;
    vector<double> visited = {-100,-100,-100};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(students_copy[j][1] > current_max){
                current_max = students_copy[j][1];
                max_index.clear();
                max_index.push_back(j);
            }
            else if(students_copy[j][1] == current_max){
                max_index.push_back(j);
            }
        }
        int count = max_index.size();
        for(int k = 0; k < count; k++){
            students[max_index[k]][2] = rank;
            students_copy[max_index[k]] = visited;
        }
        rank += count;
        max_index.clear();
        current_max = -1.0;
    }
    for(auto&c:students) cout << (int)c[0] << " " <<fixed << setprecision(1) <<  c[1] << " " << fixed << setprecision(0) << (int)c[2] << endl;
}
int main(){solve(); return 0;}