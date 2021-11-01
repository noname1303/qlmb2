#include "menu.h"
#include "quanLyMayBay.h"
#include <iostream>
using namespace std;
Menu::Menu(){};
void Menu::HienThiMenu()
{
    cout << "============MayBay===========" << endl;
    cout << "1. Them chuyen bay " << endl;
    cout << "2. Quan ly chuyen bay" << endl;
    cout << "3. Dat ve" << endl;
    cout << "4.Huy ve" << endl;
    XuLiMenu();
}
int Menu::NhapMenu()
{
    int n = 0;
    //cout << "\n\nMoi chon menu: ";
    cin >> n;
    if (n > 0 || n < 4)
        return n;
    else
        return NhapMenu();
}
void Menu::XuLiMenu()
{
    int Input = NhapMenu();
    switch (Input)
    {
    case 1:
        cout << "dcm";
        break;
    case 2:
    {
        quanLyMayBay app;
        app.show();
        string maHieu, loai;
        int soDay, soGhe;
        cout << "Nhap ma hieu may bay" << endl;
        cin >> maHieu;
        cout << "Nhap ma loai may bay" << endl;
        cin >> loai;
        cout << "Nhap so day" << endl;
        cin >> soDay;
        cout << "Nhap so ghe" << endl;
        cin >> soGhe;
        app.node_insertion(maHieu, loai, soDay, soGhe);
        app.show();
    }
    case 3:
        cout << "dcm3";
        break;
    case 4:
        cout << "dcm4";
        break;
    }
}