#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

void demostack()
{
    stack<int> S;
    for (int i = 0; i <= 5; i++)
    {
        S.push(i); // insert to stack
        cout << "Push " << i << endl;
    }
    while (!S.empty())
    {
        int e = S.top(); // access the element on top of stack
        S.pop();         // pop (remove) the top element of stack
        cout << "Pop " << e << endl;
    }
}

void demoqueue()
{
    queue<int> Q;
    for (int i = 1; i <= 5; i++)
    {
        Q.push(i); // Push element to queue
        cout << "Queue push " << i << endl;
    }

    while (!Q.empty())
    {
        int e = Q.front();
        Q.pop();
        cout << "Queue pop " << e << endl;
    }
}

void demomap()
{
    map<string, int> M; // map duoc lap trinh bang cay nhi phan tim kiem can bang

    M["abc"] = 1; // map key abc with value 1
    M["def"] = 2; // map key def with value 2
    M["xyzt"] = 10;

    string k = "abc";
    cout << "Value of key" << k << "=" << M[k] << endl;
    for (map<string, int>::iterator p = M.begin(); p != M.end(); p++)
    {
        cout << p->first << " is map to " << p->second << endl;
    }
}

void demopriority_queue()
{ // hang doi uu tien
    priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(100);
    pq.push(10);
    while (!pq.empty())
    {
        int e = pq.top();
        pq.pop();
        cout << "pq pop" << e << endl;
    }

    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push(make_pair(4, 40));
    PQ.push(make_pair(1, 10));
    PQ.push(make_pair(9, 900));

    while (!PQ.empty())
    {
        pii e = PQ.top();
        PQ.pop();
        cout << "PQ pop (" << e.first << "," << e.second << ")" << endl;
    }
}

int main()
{
    // demostack();
    demoqueue();
    // demomap();
    // demopriority_queue();
    return 0;
}