#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class ChuyenBay
{
private:
    string maHieu, loaiMayBay;
    int soDay;
    int soGhe;
    string ngay;
    string gio;
    string noiKH, noiKT;
    ChuyenBay *nxt;
    ChuyenBay *head;

public:
    ChuyenBay(string = "", string = "", int = 10, int = 2, string = "", string = "", string = "Da Nang", string = "Ha Noi");

    void menuCB();
    void themCB();
    void insertCB(string, string, string, string);
    void show();
    void xoaCB();
    void suaCB();
    void ghiFile();
    void docFile();
};