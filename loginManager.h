#include<iostream>
#include<iomanip>
using namespace std;
class QuanLyDangNhap
{
public:
    QuanLyDangNhap();
    bool dangNhap();
    void dangKi();
    bool checkFile(string , const char* );
    void saveFile(string ,const char*  ); // giam bo nho
    long long maHoa (int ); //Dung long long de co the luu dc nhin gia tri hon
    int giaiMa(long long ); // vi` giai ma nen chi can int la` du
private:

    string taiKhoanTmp;
    string matKhauTmp;
    bool quyenTruyCap;
};
