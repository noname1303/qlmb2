#include"menu.h"
#include<iostream>
using namespace std;
Menu::Menu(){};
void Menu::HienThiMenu()
{   
    cout<< "============MayBay==========="<< endl;
    cout<<"1. Them chuyen bay "<< endl;
    cout<<"2. Quan ly chuyen bay"<< endl;
    cout<<"3. Dat ve"<< endl;
    cout<<"4.Huy ve"<< endl;
    XuLiMenu();
}
int Menu::NhapMenu()
{
    int n = 0;
	//cout << "\n\nMoi chon menu: ";
	cin >> n;
	if (n > 0 || n < 4)
		return n;
	else return NhapMenu();
}
void Menu::XuLiMenu()
{
    int Input= NhapMenu();
    switch(Input)
    {
        case 1:
            cout<<"dcm";
            break;
        case 2:
            cout<<"dcm2";
            break;
        case 3:
            cout<<"dcm3";
            break;
        case 4:
            cout<<"dcm4";
            break;
    }
}