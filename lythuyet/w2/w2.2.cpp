/*
Problem: Simulation Stack
Description
Perform a sequence of operations over a stack, each element is an integer:
PUSH v: push a value v into the stack
POP: remove an element out of the stack and print this element to stdout (print NULL if the stack is empty)
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
3
2
5*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<int> S;
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
            S.push(num);
        }
        else if (cmd == "POP")
        {
            if (S.empty())
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << S.top() << endl;
                S.pop();
            }
        }
    }

    return 0;
}
/*Chương trình này thực hiện các thao tác sau:

Khai báo một ngăn xếp (stack<int> S) để lưu trữ các phần tử là số nguyên.

Đọc dữ liệu từ đầu vào cho đến khi gặp dấu "#".

Kiểm tra từng lệnh đọc được:

Nếu là "PUSH", đọc một số (num) và đẩy số đó vào ngăn xếp S.
Nếu là "POP", kiểm tra xem ngăn xếp S có trống không. Nếu trống, in ra "NULL". Nếu không trống, in ra giá trị ở đỉnh ngăn xếp S, loại bỏ giá trị đó khỏi ngăn xếp.
Khi gặp dấu "#", chương trình kết thúc và thoát khỏi vòng lặp.*/