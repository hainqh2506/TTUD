/*Problem: Word Frequency in Text
Description
Given a TEXT which consists of a sequence of words. Each word is defined to be a sequence of contiguous characters of the alphabet (a, ..., z, A, ..., Z) and digits (0, 1, ..., 9). Other special characters are considered as delimiters between words.
Write a program to count the number of occurrences o(w) of each word w of the given TEXT.
Input
The TEXT (each word of the TEXT has length <= 20)

Output
Each line contains a word w and o(w) (separated by a SPACE). The words (printed to lines of the stdout) are sorted in a lexicographic order.

Example
Input
abc  def abc
abc abcd def

Output
abc 3
abcd 1
def 2
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("text.txt", "r", stdin);
    char word[100];
    int n = 0;
    bool startWord = false;
    map<string, int> M;
    while (!feof(stdin))
    {
        char C = fgetc(stdin);
        if (C <= 'z' && C >= 'a' || C <= '9' && C >= '0')
        {
            if (!startWord)
                startWord = true;
            n++;
            word[n - 1] = C;
        }
        else
        {
            if (startWord)
            {
                word[n] = '\0';
                M[word]++;
            }
            n = 0;
            startWord = false;
        }
    }
    for (map<string, int>::iterator p = M.begin(); p != M.end(); p++)
    {
        cout << p->first << " " << p->second << endl;
    }
    return 0;
}