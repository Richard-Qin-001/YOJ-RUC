#include <iostream>
#include <string>
#include <iomanip>
//#include "stock.h"
#ifndef STOCK_H
#define STOCK_H
#endif
 

using namespace std;

class stock {
// ____qcodep____
private:
    string Symbol;
    int volume;
    double open_price;
    double close_price;
    double buy_price;

public:
    stock() : Symbol(""), volume(0), open_price(0), close_price(0), buy_price(0) {}
    stock(string s, int v, double o, double c, double b);
    ~stock();
    string getSymbol();
    int getVolume();
    double getOpenPrice();
    double getClosePrice();
    double getBuyPrice();
    void setSymbol(string Symbol0);
    void setVolume(int Volume);
    void setOpenPrice(double Oprice);
    void setClosePrice(double Cprice);
    void setBuyPrice(double Bprice);
    double calCurrentHolding();
    double calOpenHolding();
    double calCloseHolding();
};

// ____qcodep____

stock::stock(string s, int v, double o, double c, double b) : Symbol(s), volume(v), open_price(o), close_price(c), buy_price(b) {}

string stock::getSymbol()
{
	return Symbol;
}
int stock::getVolume()
{
	return volume;
}
double stock::getOpenPrice()
{
	return open_price;
}
double stock::getClosePrice()
{
	return close_price;
}
double stock::getBuyPrice()
{
	return buy_price;
}
void stock::setSymbol(string Symbol0)
{
	Symbol.assign(Symbol0);
}
void stock::setVolume(int Volume)
{
	volume = Volume;
}
void stock::setOpenPrice(double Oprice)
{
	open_price = Oprice;
}
void stock::setClosePrice(double Cprice)
{
	close_price = Cprice;
}
void stock::setBuyPrice(double Bprice)
{
	buy_price = Bprice;
}

double stock::calCurrentHolding()
{
	double h;
	h = (double)getVolume() * getBuyPrice();
//	cout<<"H" <<getVolume() <<"B"<< getBuyPrice()<<"\t";
	return h;
}
double stock::calOpenHolding()
{
	double hmo;
	hmo = (double)getVolume() * getOpenPrice();
	return hmo;
}
double stock::calCloseHolding()
{
	double hmc;
	hmc = (double)getVolume() * getClosePrice();
	return hmc;
}

stock::~stock()
{

}

int main() {
	
	int stock_array = 5;
	stock stocks[stock_array];

	string symbol;
	int volume_now;
	double open_price;
	double close_price;
	double buy_price;

	for (int i = 0; i < stock_array; i++)
	{
		//cout << "Stock" << i + 1 << endl;
		while(1){
		
			//cout << "enter symbol: ";
			cin >> symbol;
	
			if ((symbol.find_first_not_of(' ') == std::string::npos) || symbol.empty() || (symbol.length() > 5))
			{
				cout << "symbol should not be empty and size <= 5. Try again\n";
				continue;
			}
			break;
		}

		while(1){
		//cout << "enter volume: ";
			cin >> volume_now;
			if (volume_now <= 0)
			{
				cout << "volume should be >0. Try again\n";
				continue; 
			}
			break;
		}

		while(1){
		//cout << "enter opening price: ";
			cin >> open_price;

			if (open_price <= 0)
			{
				cout << "All prices should be >0. Try again\n";
				continue; 
			}
			break;
		}
		while(1){
		//cout << "Enter closing price: ";
			cin >> close_price;

			if (open_price <= 0)
			{
				cout << "all prices should be >0. Try again\n";
				continue; 
			}
			break;
		}
		while(1){
		//cout << "enter buying price: ";
			cin >> buy_price;

			if (open_price <= 0)
			{
				cout << "All prices should be >0. Try again\n";
				continue; 
			}
			break;
		}
		
//		cout<< "symbol" << symbol <<"\t" <<volume_now <<"\t" << open_price<<"\t"<<endl; 
		stock s1(symbol, volume_now, open_price, close_price, buy_price);
//		cout<<s1.getVolume();
		
		stocks[i] = s1; 
	}

	//cout << endl << std::setw(20) << "-----------Displaying Holdings Data ----------" << endl;
	for (int i = 0; i < stock_array; i++)
	{		
		cout << "SYM = " << stocks[i].getSymbol() << ", H = " << stocks[i].calCurrentHolding() <<
			", HMO = "<< stocks[i].calOpenHolding()<<", HMC = "<< stocks[i].calCloseHolding()<< endl;
	}

	double totalh = 0;
	double totalhmo = 0;
	double totalhmc = 0;

	cout << endl << "SYMS =";
	for (int i = 0; i < stock_array; i++)
	{
		totalh = totalh + stocks[i].calCurrentHolding();
		totalhmo = totalhmo + stocks[i].calOpenHolding();
		totalhmc = totalhmc + stocks[i].calCloseHolding();
		cout << stocks[i].getSymbol() << ", ";
	}
	cout << endl;
	cout << "Total H: " << totalh << endl;
	cout << "Total HMO: " << totalhmo << endl;
	cout << "Total HMC: " << totalhmc << endl;
	
	//system("pause");
	return 0;
}