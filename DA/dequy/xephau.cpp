#include <bits/stdc++.h>

int x[100];
int n;

// Kiểm tra xem có thể đặt quân hậu với giá trị v tại cột k hay không
// kiểm tra v có thể gán được cho x[k] hay không

int check(int v, int k) {
    for (int i = 1; i <= k-1 ; i++) {  
/*Trong hàm check, vòng lặp chạy từ i = 1 đến k - 1 để kiểm tra các quân hậu đã được đặt từ cột 1 đến cột k - 1. 
Mục đích của việc này là để đảm bảo rằng quân hậu ở cột k không trùng vị trí với các quân hậu ở các cột trước đó theo hàng, đường chéo chính, và đường chéo phụ.
Khi bạn đặt một quân hậu mới ở cột k, bạn cần kiểm tra xem quân hậu đó có trùng vị trí với các quân hậu đã đặt ở 
các cột trước đó hay không. Vòng lặp từ i = 1 đến k - 1 giúp bạn kiểm tra những quân hậu đã đặt từ cột 1 đến cột k - 1. 
Nếu tại một vị trí nào đó, bạn thấy quân hậu đã đặt trùng vị trí với quân hậu mới 
(theo hàng hoặc đường chéo chính hoặc đường chéo phụ), hàm check sẽ trả về 0 (false), nghĩa là không thể đặt quân hậu ở vị trí này.
Như vậy, vòng lặp này giúp đảm bảo tính hợp lệ của vị trí khi đặt quân hậu mới,
đồng thời tránh được việc có 2 quân hậu nào đó cùng nằm trên một hàng, đường chéo chính hoặc đường chéo phụ.*/
        // Kiểm tra trùng vị trí theo hàng
        if (x[i] == v) 
            return 0;
        
        // Kiểm tra trùng vị trí theo đường chéo chính
        if (x[i] + i == v + k) 
            return 0;
        
        // Kiểm tra trùng vị trí theo đường chéo phụ
        if (x[i] - i == v - k) 
            return 0;
    }
    return 1;
}

// In ra một cách xếp quân hậu
void solution() {
    for (int i = 1; i <= n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Hàm đệ quy để thử nghiệm tất cả các khả năng xếp quân hậu
void Try(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            if (k == n) 
                solution();
            else 
                Try(k + 1);
        }
    }
}

int main() {
    n = 4;
    Try(1);
    return 0;
}
