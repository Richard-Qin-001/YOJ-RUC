#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int count_correct_guesses(char who_shot_it) {
    int correct_count = 0;
    if (who_shot_it == 'H' || who_shot_it == 'F') {
            correct_count++;
        }
    if (who_shot_it == 'B') {
        correct_count++;
    }
    if (who_shot_it == 'G') {
        correct_count++;
    }
    if (who_shot_it != 'B') {
        correct_count++;
    }
    if (!(who_shot_it == 'H' || who_shot_it == 'F')) {
        correct_count++;
    }
    if (who_shot_it != 'F' && who_shot_it != 'H') {
        correct_count++;
    }
    if (who_shot_it != 'C') {
        correct_count++;
    }
    if (who_shot_it == 'H' || who_shot_it == 'F') {
        correct_count++;
    }
    return correct_count;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    if (!(cin >> n)) {
        return 0; 
    }


    vector<char> possible_shooters;
    
    for (char shooter = 'A'; shooter <= 'H'; ++shooter) {
        int correct = count_correct_guesses(shooter);
        if (correct == n) {
            possible_shooters.push_back(shooter);
        }
    }

    if (possible_shooters.size() == 1) {
        cout << possible_shooters[0] << endl;
    } else {
        cout << "DONTKNOW" << endl;
    }

    return 0;
}