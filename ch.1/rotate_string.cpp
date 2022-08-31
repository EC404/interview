#include "rotate_string.h"

void leftRotateString(std::string& str, int m, unsigned int type)
{
    using std::cout;

    if (type == 1)
    {
        cout << "Type 1\n";
        while (m--)
            leftShiftOne(str);

    } else if (type == 2) {
        cout << "Type 2\n";

        reverseString(str, 0, m-1);
        reverseString(str, m, str.length()-1);
        reverseString(str, 0, str.length()-1);
    } else 
        cout << "Not tpye!!!";
}

void leftShiftOne(std::string& str)
{
    char t = str[0];

    int i;
    for (i = 1; i < str.length(); i++)
        str[i-1] = str[i];

    str[i-1] = t;
}

void reverseString(std::string& str, int left, int right)
{
    while (left < right)
    {
        char t = str[left];
        str[left++] = str[right];
        str[right--] = t;
    }
}

void reverseWords(std::string& str)
{
    int n = str.length(),
        i,
        j;

    for (i = 0, j = 0; i < n; i++)
    {
        if (str[i] != ' ')
            continue;

        reverseString(str, j, i-1);
        j = i+1;
    }
    reverseString(str, j, i-1);
    reverseString(str, 0, n-1);
}

void rightRotateString(std::string& str, int m)
{
    reverseString(str, str.length()-m, str.length()-1);
    reverseString(str, 0, str.length()-m-1);
    reverseString(str, 0, str.length()-1);
}