#include <iostream>

using namespace std;
int A1(int a[], int left, int right, int k)
{
    int dem = 0;
    if (left == right)
    {
        if (a[left] % k == 0)
        {
            dem++;
            return dem;
        }
        else
        {
            return 0;
        }
    }
    int mid = (left + right) / 2;
    int count1 = A1(a, left, mid, k);
    int count2 = A1(a, mid + 1, right, k);
    return count1 + count2;
}

int main()
{
    int n = 12;
    int a[n] = {2, 4, 5, 24, 12, 34, 35, 46, 54, 78, 86, 89};
    int k1 = 2;
    int k2 = 3;
    int dem1 = A1(a, 0, n - 1, k1);
    cout << " So luong cac so trong mang chia het cho " << k1 << " : " << dem1 << endl;
    int dem2 = A1(a, 0, n - 1, k2);
    cout << " So luong cac so trong mang khong chia het cho " << k2 << " : " << (n - dem2) << endl;
}