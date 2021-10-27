#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "menu.h"
#include"loginManager.h"
using namespace std;

QuanLyDangNhap::QuanLyDangNhap()
    {
         quyenTruyCap = 0;
    }

bool QuanLyDangNhap::dangNhap()
    {
        bool isLogin;
        cout<<"-----------DANG NHAP----------------"<<endl;
        cout << "Nhap tai khoan va mat khau.\nTai Khoan:";
        cin >> taiKhoanTmp;
        int userID = checkFile(taiKhoanTmp,"users.txt");
        if(userID != 0)
        {
            cout << "Mat khau:";
            cin >> matKhauTmp;

            int passwordID = checkFile(matKhauTmp,"passwords.txt");
            if(userID == passwordID)
            {
                isLogin=  true;
                Menu menu;
                menu.HienThiMenu();
                cin.get();
            }
            else
            {
                cout << "Sai mat khau." << endl;
                dangNhap();
            }
        }
        else
        {
            cout << "Ten dang nhap khong dung." << endl;
            dangNhap();
        }
        return isLogin;
    }
bool QuanLyDangNhap:: checkFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;
        long long maHoaKiTu;
        file.open(p_fileName, ios::in);
        while(1)
        {
          
            file >> maHoaKiTu;
            if(maHoaKiTu == 0)
            {
                if(attempt == line){
                    file.close();
                    return true;
                }
                else{
                    line.erase(line.begin(),line.end());
                }
            }
            else{

            line += (char)giaiMa(maHoaKiTu);
            }

            if(file.peek() == EOF)
            {
                file.close();
                return false;
            }
        }

    }
void QuanLyDangNhap:: saveFile(string p_line,const char* p_fileName ) // giam bo nho
    {
        fstream file;
        file.open(p_fileName, ios::app);
        for(int i=0; i<p_line.length(); i++)
        {
            file << maHoa(p_line[i]);
            file << "\n";

        }
        file<<"0\n"; // de ngan cach cac mat khau/tk
        file.close();
    }
void QuanLyDangNhap::dangKi(){
    string tk,mk; 
    cout<<"-----------DANG Ky----------------"<<endl;
    cout<<"Vui long nhap ten tai khoan:\t";
    cin>>tk;

    cout<<"Vui long nhap mat khau:\t";
    cin>>mk;
    saveFile(tk,"users.txt");
    saveFile(mk,"passwords.txt");
    dangNhap();

}
long long QuanLyDangNhap::maHoa (int p_letter) //Dung long long de co the luu dc nhin gia tri hon
    {
        return powf(p_letter,4);

    }
int QuanLyDangNhap::giaiMa(long long p_letter) // vi` giai ma nen chi can int la` du
    {
        return powf(p_letter,1/4.f); // .f de trinh bien dich biet chung ta can tra ve du lieu dang float

    }


