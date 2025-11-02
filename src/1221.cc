#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> dict = {{'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}};

enum HandType { GP = 1, SZ, TH, THS };

struct Card
{
    char color;
    int number;
};

string typeToString(HandType type) {
    if (type == THS) return "THS";
    if (type == TH) return "TH";
    if (type == SZ) return "SZ";
    return "GP";
}

bool compare(const Card&a, const Card&b){return a.number < b.number;}

bool isTH(const vector<Card>&cards){
    char first_color = cards[0].color;
    for(size_t i = 1; i < cards.size(); i++)if(cards[i].color != first_color) return false;
    return true;
}

bool isSZ(const vector<Card>&cards){
    if (cards[0].number == 2 && cards[1].number == 3 && 
        cards[2].number == 4 && cards[3].number == 5 && 
        cards[4].number == 14)return true;
    for(size_t i = 0; i < cards.size() - 1; i++)if(cards[i+1].number != cards[i].number + 1) return false;
    return true;
}

bool isTHS(const vector<Card>&cards){
    return isTH(cards) && isSZ(cards);
}

HandType evaluate_hand(vector<Card>& chosen) {
    sort(chosen.begin(), chosen.end(), compare); 
    
    bool is_flush = isTH(chosen);
    bool is_straight = isSZ(chosen);
    
    if (is_flush && is_straight) return THS;
    if (is_flush) return TH;
    if (is_straight) return SZ;
    
    return GP;
}

void process(){
    vector<Card> cards(7);
    for(int i = 0; i < 7; i++){
        string card_str;
        cin >> card_str;
        cards[i].color = card_str[0];
        string value_str = card_str.substr(1);
        if(value_str.length() == 1) cards[i].number = dict[value_str[0]];
        else cards[i].number = 10;
    }
    HandType max_type = GP;
    for(int i = 2; i < 5; i++)for(int j = i+1; j < 6; j++)for(int k = j+1; k < 7; k++){
        vector<Card> chosen;
        chosen.push_back(cards[0]);
        chosen.push_back(cards[1]);
        chosen.push_back(cards[i]);
        chosen.push_back(cards[j]);
        chosen.push_back(cards[k]);
        sort(chosen.begin(), chosen.end(), compare);
        HandType current_type = evaluate_hand(chosen);
        if (current_type > max_type) max_type = current_type;
        if (max_type == THS) goto end_loops;
    }
    end_loops:
    cout << typeToString(max_type) << endl;
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)process();
}
int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}