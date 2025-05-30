#include <iostream>
using namespace std;

int main()
{
    // 1. Khởi tạo mảng 12 số thực (fake data)
    float danhSachSo[12] = {4.5, 6.2, 3.5, 7.8, 3, 5.1, 9.0, 2, 8.3, 1, 3.9, 6.4};

    // 2. Gán sẵn giá trị k (fake data)
    float k = 5;

    // 3. Thuật toán A - đếm, tính tổng và in ra các số nhỏ hơn k
    int demSoNhoHon = 0;    // Số lượng phần tử nhỏ hơn k
    float tongSoNhoHon = 0; // Tổng các phần tử nhỏ hơn k

    cout << "Gia tri k = " << k << endl;
    cout << "Cac so nho hon " << k << " trong mang: ";

    for (int i = 0; i < 12; i++)
    {
        if (danhSachSo[i] < k)
        {
            cout << danhSachSo[i] << "  ";
            demSoNhoHon++;
            tongSoNhoHon += danhSachSo[i];
        }
    }

    cout << endl;

    // 4. Xuất kết quả
    if (demSoNhoHon == 0)
    {
        cout << "Khong co so nao nho hon " << k << " trong mang.\n";
    }
    else
    {
        float giaTriTrungBinh = tongSoNhoHon / demSoNhoHon;
        cout << "Co " << demSoNhoHon << " so nho hon " << k << " trong mang.\n";
        cout << "Gia tri trung binh cua cac so do la: " << giaTriTrungBinh << endl;
    }

    return 0;
}
