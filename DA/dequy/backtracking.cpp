/*back tracking dùng để giải các bài toán liệt kê, tối ưu tổ hợp
liệt kê tất cả các bộ x thuộc A t hoả mãn một thuộc tính P nào đó
x1,x2,......x[k-1], x[k]....x[n]
    thủ tục TRY(k):

*/
/*bài toán liệt kê xâu nhị phân*/
#include <bits/stdc++.h>
using namespace std;
#define N 21

int x[N]; // Mảng lưu trữ kết quả
int n;    // Độ dài của xâu nhị phân cần liệt kê
int cnt;  // Biến đếm số lượng xâu nhị phân đã được liệt kê

// Hàm kiểm tra xem giá trị v có thỏa mãn điều kiện cho x[k] hay không
int check(int v, int k)
{
    return 1; // Ở đây, ta không có điều kiện kiểm tra nên trả về luôn 1 (đúng)
}
// bai mở rộng, khong có 2 bit 1 cạnh nhau
int check1(int v, int k)
{
    if (k == 1)
        return 1;
    return x[k - 1] + v <= 1;
}

// Hàm in ra kết quả (một xâu nhị phân đã được tạo)
void solution()
{
    cnt += 1;
    printf("Solution %d: ", cnt);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Hàm thử tất cả các giá trị cho x[k] thỏa mãn điều kiện của bài toán
void Try(int k)
{
    printf("call Try at k = %d \n", k);
    for (int v = 0; v <= 1; v++)
    {
        printf("now v at %d \n", v);

        if (check(v, k))
        {
            printf("if check v = %d,k = %d ok\n", v,k);
            x[k] = v;
            printf("x[%d] = v = %d \n",k,v);
            if (k == n)
            {
                // Nếu đã điền đủ n phần tử, in ra kết quả  
                printf("if k == %d \n", n);
                solution();
            }
            else
            {   
                printf("else try(k+1) = %d + 1\n", k);
                // Ngược lại, thử tiếp cho phần tử tiếp theo
                Try(k + 1);
            }
        }
    }
}

int main()
{
    cnt = 0;
    n = 3;  // Độ dài của xâu nhị phân
    Try(1); // Bắt đầu thử giá trị cho x[1]
    return 0;
}
