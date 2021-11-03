#include <iostream>
#include <iomanip>
using namespace std;

struct MayBay
{
private:
    string maHieu, loaiMayBay;
    int soDay, soGhe;
    MayBay *next;
    MayBay *head;

public:
    MayBay(string = "", string = "", int = 10, int = 2);
    void menuMayBay();
    void themMayBay();
    void addNode(string, string, int, int);
    void show();
    int SearchMB();
    void xoaMayBay();
    void suaMayBay();
    void ghiFile();
    void docFile();
    string getMaHieu()
    {
        return maHieu;
    }
};