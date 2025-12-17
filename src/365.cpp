#include<iostream>
#include<string>
using namespace std;

class vehicle {
private:
    double MaxSpeed;
    double Weight;
public:
    vehicle(double MS,double WE) {
        MaxSpeed = MS;
        Weight = WE;
    }

    double GetMaxSpeed() {
        return MaxSpeed;
    }
    double GetWeight() {
        return Weight;
    }
    void Run() {
        cout << "The MaxSpeed of the vehicle is " << MaxSpeed << endl;
        cout << "The Weight of the vehicle is " << Weight << endl;
    }
    void  Stop() {
        cout << "The vehicle has stopped!!!" << endl;
    }
};

class bicycle :virtual public vehicle {
private:
    double Height;
public:
  
    // ____qcodep____
    bicycle(double s, double w, double h) : vehicle(s, w), Height(h) {}

    double GetHeight() {
        return Height;
    }
    void Run() {
        cout << "The height of the bicycle is "<< Height << endl;
    }
    void Stop() {
        cout << "The bicycle has stopped!" << endl;
    }
};
class motorcar :virtual vehicle {
private:
    int SeatNum;
public:
    
    // ____qcodep____
    motorcar(double spd, double w, double sn) : vehicle(spd, w), SeatNum(sn) {}
  
    int GetSeatNum() {
        return SeatNum;
    }
    void Run() {
        cout << "The SeatNum of the motorcar is "<< SeatNum << endl;
    }
    void Stop() {
        cout << "The motorcar has stopped!" << endl;
    }
};
class motorcycle :public bicycle, public motorcar {
public:
   
    // ____qcodep____
    motorcycle(double spd, double w, double h, double sn) : vehicle(spd, w), bicycle(spd, w, h), motorcar(spd, w, sn) {}

    void Run() {
        cout << "This is a motorcycle:" << endl;
        cout << "MaxSpeed:" << GetMaxSpeed() << endl;
        cout << "Weight:" << GetWeight() << endl;
        cout << "Height:" << GetHeight() << endl;
        cout << "SeatNum:" << GetSeatNum() << endl;
    }
    void Stop() {
        cout << "The motorcycle has stopped!!!" << endl;
    }
};

int main() {
    double weight, speed, height;
    int seatnum;
    
    cin >> speed >> weight;
    vehicle  t1(speed, weight);
    t1.Run();
    t1.Stop();
    
    cin >> speed >> weight >> height;
    bicycle t2(speed, weight, height);
    t2.Run();
    t2.Stop();

    cin >> speed >> weight >> seatnum;
    motorcar t3(speed, weight, seatnum);
    t3.Run();
    t3.Stop();

    cin >> speed >> weight >> height >> seatnum;
    motorcycle t4(speed, weight, height, seatnum);
    t4.Run();
    t4.Stop();

    return 0;
}