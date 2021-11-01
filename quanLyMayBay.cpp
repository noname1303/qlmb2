#include "quanLyMayBay.h"
#include <iostream>
using namespace std;
quanLyMayBay::quanLyMayBay(){};
struct MayBay
{
    string maHieu, loaiMayBay;
    int soDay, soGhe;
    MayBay *next;
};
struct listMB
{
    int n;
    MayBay *nodes[MAXMB];
};
typedef struct listMB LISTMB;
//Declaration of Head MayBay
struct MayBay *head = NULL;
void quanLyMayBay::node_insertion(string maHieu, string loaiMayBay, int soDay, int soGhe)
{
    struct MayBay *newMayBay = new MayBay;
    newMayBay->maHieu = maHieu;
    newMayBay->loaiMayBay = loaiMayBay;
    newMayBay->soDay = soDay;
    newMayBay->soGhe = soGhe;
    newMayBay->next = head;
    head = newMayBay;
}

//Traversing/displaying entered nodes
void quanLyMayBay::show()
{
    if (head == NULL)
    {
        return;
    }
    struct MayBay *temp = head;
    while (temp != NULL)
    {
        cout << temp->maHieu << " ";
        cout << temp->loaiMayBay << " ";
        cout << temp->soDay * temp->soGhe << " ";
        temp = temp->next;
    }
    cout << endl;
}

//Deleting node from start
void quanLyMayBay::del_Item()
{
    if (head == NULL)
    {
        return;
    }
    head = head->next;
    cout << 1;
}
void quanLyMayBay::suaChuyenBay(LISTMB &LMB, int i, )
{
}

// void EditMB(LISTMB &LMB, int i, NODECB LCB)
// {
//     //cout<<LMB.nodes[i]->SoHieuMB;

//     NODECB p;
//     p = LCB;
//     while (p != NULL)
//     {
//         if (strcmp(LMB.nodes[i]->SoHieuMB, p->CB.SoHieuMB) == 0)
//         {
//             AlertErr(15, 4, "DA CO CHUYEN BAY DUOC TAO TREN MAY BAY NAY!");
//             Sleep(1000);
//             clearErr(15, 4);
//             return;
//         }
//         p = p->next;
//     }

//     TextColor(Blue);
//     gotoxy(120, 8);
//     cout << "CHINH SUA SO HIEU MAY BAY : " << LMB.nodes[i]->SoHieuMB;
//     gotoxy(120, 10);
//     cout << "LOAI MAY BAY MOI : ";
//     fflush(stdin);
//     NhapChuoi(LMB.nodes[i]->LoaiMB, 140, 10);
//     DelSpace(LMB.nodes[i]->LoaiMB);
// SODAYNEW:;
//     SetColor(Blue);
//     gotoxy(120, 12);
//     cout << "SO DAY MOI : ";
//     gotoxy(140, 12);
//     char soDaynew[2];
//     if (inputNum(soDaynew, 1) == -1)
//         return;
//     if (atoi(soDaynew) > checkDay)
//     {
//         AlertErr(120, 4, "SO DAY KHONG DUOC HON 5!");
//         Sleep(2000);
//         clearErr(120, 4);
//         gotoxy(140, 12);
//         cout << "    ";
//         goto SODAYNEW;
//     }
//     LMB.nodes[i]->soDay = atoi(soDaynew);
// SODONGNEW:;
//     SetColor(Blue);
//     gotoxy(120, 14);
//     cout << "SO DONG MOI : ";
//     gotoxy(140, 14);
//     char soDongnew[3];
//     if (inputNum_noN(soDongnew) == -1)
//         return;
//     if (atoi(soDongnew) > checkDong)
//     {
//         AlertErr(120, 4, "SO DONG KHONG DUOC HON 20!");
//         Sleep(2000);
//         clearErr(120, 4);
//         gotoxy(140, 14);
//         cout << "    ";
//         goto SODONGNEW;
//     }
//     LMB.nodes[i]->soDong = atoi(soDongnew);
//     GhiFileDSMB(FileDSMB, LMB);
//     system("cls");
// }