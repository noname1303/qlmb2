
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "loginManager.h"
#include "MayBay.h"
#include "menu.h"
using namespace std;
int main()
{
    QuanLyDangNhap app;
    int option;
    bool isLogin;
    system("cls");
    cout << "Nhap lua chon" << endl;
    cout << "1.Dang ky" << endl;
    cout << "2.Dang nhap" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
    {
        app.dangKi();
        break;
    }

    case 2:
    {
        isLogin = app.dangNhap();
        break;
    }
    }
}
