#include <iostream>

using namespace std;

class Bed
{
public:
    // Bed() : ____qcodep____ {}
    Bed() : bedWeight(200.2), m_second(0) {}
    Bed(double weight, int second) : bedWeight(weight), m_second(second){}

    void Sleep(int second)
    {
        m_second = second;
        cout << "Rest " << m_second << " Seconds"<< endl;
    }

// ____qcodep____
protected:
    double bedWeight;
    int m_second;
};

class Sofa
{
public:
    Sofa(): sofaWeight(180.0), tv_second(0) {}
    Sofa(double weight, int second): sofaWeight(weight),tv_second(second){}
    void WatchTV(int second)
    {
        tv_second = second;
        cout << "WatchTV " << tv_second << " Seconds" << endl;
    }
// ____qcodep____

protected:
    double sofaWeight;
    int tv_second;
};

class SleepSofa : public Bed, public Sofa
{
public:
    SleepSofa() : Bed(), Sofa() {}
    SleepSofa(double bweight, int bsecond, double sweight, int ssecond) : Bed(bweight, bsecond), Sofa(sweight,ssecond) {}

    void FoldOut(int second)
    {
        cout << "Fold sofabed to sleep" << endl;
        Sleep(second);
    }
    void FoldIn(int second)
    {
        cout << "Fold sofabed to watchTV" << endl;
        WatchTV(second);
    }

    // ____qcodep____
    double grossWeight()
    {
        return (bedWeight > sofaWeight) ? bedWeight : sofaWeight;
    }

    int usedTime(){
        return tv_second + m_second;
    }

};

int main(int argc, char *argv[])
{
    double weight0,weight1;
    int time0,time1;
    cin>>weight0;
    cin>>time0;
    cin>>weight1;
    cin>>time1;

    SleepSofa bigBed(weight0,0,weight1,0);
    cout<< bigBed.grossWeight()<<endl;
    cout<< bigBed.usedTime()<<endl;
    bigBed.FoldOut(time0);
    bigBed.FoldIn(time1);
    cout<< bigBed.usedTime()<<endl;

    cout<<"*****************"<<endl;

    SleepSofa unsoldBed;
    cout<< unsoldBed.grossWeight()<<endl;
    cout<< unsoldBed.usedTime()<<endl;
    unsoldBed.FoldOut(0);
    unsoldBed.FoldIn(0);
    cout<< unsoldBed.usedTime()<<endl;

    return 0;
}
