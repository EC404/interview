#include "rotate_string.h"
#include "linked_list.h"

bool isAnagram(std::string, std::string);
int maxSymmetricString(std::string);

int main(int argc, char **argv)
{
    using std::cout;

    cout << maxSymmetricString("goooog");

    return 0;
}

// Time complexity:o(n+m), SpaceComplexity:o(n);
// Make good use of unordered_map.
bool isAnagram(std::string s, std::string t)
{
    if (s.size() != t.size())
        return false;

    // Store s and t element
    int ss[26] = {0},
        tt[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        // Sorting a to z;
        ss[s[i]-'a']++;
        tt[t[i]-'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        // Check if s and t a to z elements are the same;
        if (ss[i] != tt[i])
            return false;

    }
    return true;
}

int maxSymmetricString(std::string str)
{
    if (str.length() < 1)
        return 0;

    int n = str.length(),
        m = 0,
        l = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; (i-j >= 0) && (i+j+1 < n); j++)
        {
            if (str[i-j] != str[i+j+1])
                break;

            l = j*2+2;
            m = std::max(m, l);
        }
    }
    return m;
}
