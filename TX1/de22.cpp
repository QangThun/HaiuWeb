#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct HocPhan
{
    string ten;
    int hocPhi; // nghin VND
    int tinChi;
};

// Khoi tao danh sach hoc phan
vector<HocPhan> khoiTaoDanhSach()
{
    return {
        {"Co so DL", 300, 2},
        {"Tieng Anh CN", 350, 2},
        {"HDH", 400, 2},
        {"Toan roi rac", 500, 3},
        {"KTLT", 600, 3},
        {"CTDL & GT", 700, 4},
        {"CNPM", 800, 3}};
}

// THUAT TOAN THAM LAM
bool chonThamLam(const vector<HocPhan> &danhSach, int tongTien, vector<int> &chon)
{
    int n = danhSach.size();
    chon = vector<int>(n, 0); // khoi tao vector chon toan 0
    int i = 0, conLai = tongTien;

    while (conLai > 0 && i < n)
    {
        if (danhSach[i].hocPhi <= conLai)
        {
            chon[i] = 1; // chon hoc phan thu i
            conLai -= danhSach[i].hocPhi;
        }
        i++;
    }

    return conLai < tongTien; // tra ve true neu da chon it nhat 1 hoc phan
}

// HIEN THI KET QUA THAM LAM
void hienThiThamLam(const vector<HocPhan> &danhSach, const vector<int> &chon, int tongTien)
{
    cout << "\nCau1:Ket qua theo thuat toan tham lam:\n";
    int tongHP = 0, tongTC = 0;
    bool daChon = false;

    for (int i = 0; i < danhSach.size(); i++)
    {
        if (chon[i])
        {
            cout << "- " << danhSach[i].ten << " (" << danhSach[i].hocPhi << "k VND, " << danhSach[i].tinChi << " TC)\n";
            tongHP += danhSach[i].hocPhi;
            tongTC += danhSach[i].tinChi;
            daChon = true;
        }
    }

    if (!daChon)
    {
        cout << "Khong chon duoc hoc phan nao.\n";
    }
    else
    {
        cout << "Tong hoc phi: " << tongHP << "k VND, con lai: " << (tongTien - tongHP) << "k VND\n";
        cout << "Tong tin chi: " << tongTC << "\n";
    }
}

// THUAT TOAN QHD (giong bai toan cai tui 0-1)
void chonQHD(const vector<HocPhan> &danhSach, int gioiHan, vector<int> &chon)
{
    int n = danhSach.size();
    vector<vector<int>> F(n + 1, vector<int>(gioiHan + 1, 0));
    chon.clear();

    for (int i = 1; i <= n; i++)
    {
        int w = danhSach[i - 1].hocPhi;
        int v = danhSach[i - 1].tinChi;

        for (int j = 0; j <= gioiHan; j++)
        {
            F[i][j] = F[i - 1][j];
            if (w <= j)
            {
                int tam = v + F[i - 1][j - w];
                if (F[i][j] < tam)
                    F[i][j] = tam;
            }
        }
    }

    int j = gioiHan;
    for (int i = n; i > 0; i--)
    {
        if (F[i][j] != F[i - 1][j])
        {
            chon.push_back(i - 1);
            j -= danhSach[i - 1].hocPhi;
        }
    }
}

// HIEN THI KET QUA QHD
void hienThiQHD(const vector<HocPhan> &danhSach, const vector<int> &chon, int tongTien)
{
    cout << "\nCau2:Ket qua theo thuat toan QHD:\n";
    if (chon.empty())
    {
        cout << "Khong chon duoc hoc phan nao.\n";
        return;
    }

    int tongHP = 0, tongTC = 0;
    for (int idx : chon)
    {
        cout << "- " << danhSach[idx].ten << " (" << danhSach[idx].hocPhi << "k VND, " << danhSach[idx].tinChi << " TC)\n";
        tongHP += danhSach[idx].hocPhi;
        tongTC += danhSach[idx].tinChi;
    }

    cout << ">> Tong hoc phi: " << tongHP << "k VND\n";
    cout << ">> Tong tin chi: " << tongTC << " TC\n";
}

int main()
{
    vector<HocPhan> danhSach = khoiTaoDanhSach();
    int soTienToiDa = 2000;

    vector<int> chonTham;
    chonThamLam(danhSach, soTienToiDa, chonTham);
    hienThiThamLam(danhSach, chonTham, soTienToiDa);

    vector<int> chonQHDKQ;
    chonQHD(danhSach, soTienToiDa, chonQHDKQ);
    hienThiQHD(danhSach, chonQHDKQ, soTienToiDa);

    return 0;
}