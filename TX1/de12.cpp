#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc máy tính
struct MayTinh
{
    string soHieu;
    string tenQuanLy;
    int giaTri;
    int giaThanhLy;
};

// DỮ LIỆU CÓ SẴN
vector<MayTinh> danhSach = {
    {"MT01", "Nguyen Van An", 60, 30},
    {"MT02", "Le Thi Ban", 100, 50},
    {"MT03", "Tran Van Cuong", 120, 60},
    {"MT04", "Vo Thi Duyen", 30, 20},
    {"MT05", "Pham Van Dong", 70, 30},
    {"MT06", "Nguyen Van Thanh", 90, 40},
    {"MT07", "Nguyen Van Giap", 50, 25}};
int m = 100; // Tổng số tiền có thể chi

// So sánh theo tỉ lệ giá trị / giá thanh lý (Greedy)
bool soSanhTheoGiaThanhLy(const MayTinh &a, const MayTinh &b)
{
    return a.giaThanhLy < b.giaThanhLy;
}

// Thuật toán Tham lam (Greedy)
void giaiThuatThamLam(vector<MayTinh> danhSach, int m)
{
    sort(danhSach.begin(), danhSach.end(), soSanhTheoGiaThanhLy);

    int tongGiaTri = 0, tongTien = 0;
    vector<MayTinh> ketQua;

    for (auto &mt : danhSach)
    {
        if (tongTien + mt.giaThanhLy <= m)
        {
            tongTien += mt.giaThanhLy;
            tongGiaTri += mt.giaTri;
            ketQua.push_back(mt);
        }
    }

    // Sắp xếp kết quả theo soHieu tăng dần
    sort(ketQua.begin(), ketQua.end(), [](const MayTinh &a, const MayTinh &b)
         { return a.soHieu < b.soHieu; });

    cout << "\nDanh sach may tinh duoc chon (Thuat toan Tham Lam):\n";
    for (auto &mt : ketQua)
    {
        cout << "- " << mt.soHieu
             << " | Quan ly: " << mt.tenQuanLy
             << " | Gia tri: " << mt.giaTri
             << " | Gia thanh ly: " << mt.giaThanhLy << endl;
    }
    cout << "Tong gia tri: " << tongGiaTri << " | Tong tien da dung: " << tongTien << endl;
}

// Quy hoạch động (DP)
void giaiThuatQHD(vector<MayTinh> danhSach, int m)
{
    int n = danhSach.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Lập bảng DP
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= m; w++)
        {
            if (danhSach[i - 1].giaThanhLy > w)
            {
                dp[i][w] = dp[i - 1][w];
            }
            else
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    dp[i - 1][w - danhSach[i - 1].giaThanhLy] + danhSach[i - 1].giaTri);
            }
        }
    }

    // Truy vết kết quả
    int tongTien = 0;
    vector<MayTinh> ketQua;
    int w = m;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            ketQua.push_back(danhSach[i - 1]);
            tongTien += danhSach[i - 1].giaThanhLy;
            w -= danhSach[i - 1].giaThanhLy;
        }
    }

    // Sắp xếp kết quả theo soHieu tăng dần
    sort(ketQua.begin(), ketQua.end(), [](const MayTinh &a, const MayTinh &b)
         { return a.soHieu < b.soHieu; });

    cout << "\nDanh sach may tinh duoc chon (Quy hoach dong):\n";
    for (auto &mt : ketQua)
    {
        cout << "- " << mt.soHieu
             << " | Quan ly: " << mt.tenQuanLy
             << " | Gia tri: " << mt.giaTri
             << " | Gia thanh ly: " << mt.giaThanhLy << endl;
    }
    cout << "Tong gia tri: " << dp[n][m] << " | Tong tien da dung: " << tongTien << endl;
}

int main()
{
    // Gọi hai phương pháp giải
    giaiThuatThamLam(danhSach, m);
    giaiThuatQHD(danhSach, m);

    return 0;
}
