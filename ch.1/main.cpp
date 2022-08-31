#include "rotate_string.h"
#include "linked_list.h"

bool isAnagram(std::string s, std::string s);

int main(int argc, char **argv)
{
    using std::cout;
    using std::endl;
    using std::string;

    LinkedList list;

    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);
    list.push(5);
    list.push(6);

    list.printList();
}

// Time complexity:o(n+m), SpaceComplexity:o(n);
// Make good use of unordered_map.
bool isAnagram(std::string s, std::string s)
{
    if (s.size() != t.size())
        return false;

    // Store s and t element
    int ss[26] = {0},
        tt[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        // Sorting a to z;
        ss[s[i]-"a"]++;
        tt[t[i]-"a"]++;
    }

    for (int i = 0; i < 26; i++)
    {
        // Check if s and t a to z elements are the same;
        if (ss[i] != tt[i])
            return false;

    }
    return true;
}