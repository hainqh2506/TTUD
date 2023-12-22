/*Problem: Simulation Queue
Description
Perform a sequence of operations over a queue, each element is an integer:
PUSH v: push a value v into the queue
POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
Input
Each line contains a command (operration) of type
PUSH  v
POP
Output
Write the results of POP operations (each result is written in a line)
Example
Input
PUSH 1
PUSH 2
PUSH 3
POP
POP
PUSH 4
PUSH 5
POP
#
Output
1
2
3

Input
PUSH 1
POP
POP
PUSH 4
POP
#
Output
1
NULL
4*/
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    queue<int> Q;
    string cmd;
    int num;

    while (true)
    {
        cin >> cmd;

        if (cmd == "#")
        {
            break;
        }

        if (cmd == "PUSH")
        {
            cin >> num;
            Q.push(num);
        }
        else if (cmd == "POP")
        {
            if (Q.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << Q.front() << endl;
                Q.pop();
            }
        }
    }

    return 0;
}
/*Chương trình này thực hiện các thao tác sau:

Khai báo một hàng đợi (queue<int> Q) để lưu trữ các phần tử là số nguyên.

Đọc dữ liệu từ đầu vào cho đến khi gặp dấu "#".

Kiểm tra từng lệnh đọc được:

Nếu là "PUSH", đọc một số (num) và đẩy số đó vào hàng đợi Q.
Nếu là "POP", kiểm tra xem hàng đợi Q có trống không. Nếu trống, in ra "NULL". Nếu không trống, in ra giá trị ở đầu hàng đợi Q, loại bỏ giá trị đó khỏi hàng đợi.
Khi gặp dấu "#", chương trình kết thúc và thoát khỏi vòng lặp.*/