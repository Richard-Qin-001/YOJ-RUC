#include <vector>
#include <iostream>
using namespace std;

class NumPrint
{
public:
    NumPrint(int t=0):tt(t){};
    void printNum();
    int getCompositeNum(int pmax);//得到符合条件的完数
    
    // ____qcodep____
    friend void reversePrintNum(NumPrint X);
    

private:
    vector<int> a;
    int tt;
};

// ____qcodep____
void reversePrintNum(NumPrint X){
    for(int i = X.a.size() - 1; i >= 0; --i){
        cout << X.a.at(i) << " ";
    }
}

void NumPrint::printNum(){
 for(int i=0;i<(a.size());i++)
        cout<<a.at(i)<<" ";
}

int NumPrint::getCompositeNum(int pmax){
    int number=6;
    int n=1;
    int sum=0;
    while(number<=pmax){
        while(n <= (number/2)){
            if(number%n == 0){
                sum += n;
            }
            n++;
        }
        if(sum == number){
            a.push_back(number);
        }
        number++;
        sum=0;
        n=1;
    }
    return 0;
}

class NewNumPrint : public NumPrint
{
public:
    NewNumPrint();
    void printNum();
};

NewNumPrint::NewNumPrint(){
}

void NewNumPrint::printNum(){
    this->getCompositeNum(1000);
}


int main(int argc, char *argv[])
{
    int a;
    cin>>a;
    NumPrint X;
    X.getCompositeNum(a);
    // ____qcodep____
    X.printNum();
    cout<<endl;
    reversePrintNum(X);
    return 0;

}
