#include <bits/stdc++.h>
using namespace std;

// M-1 Functional Recursion
bool isPalindrome(string &s, int i)
{
    if (i >= s.length() / 2) // Base Condition : If i exceeds half of the string means all the elements are compared, we return true.
        return true;

    if (s[i] != s[s.length() - i - 1]) // If the start is not equal to the end, not the palindrome.
        return false;

    return isPalindrome(s, i + 1); // If both characters are the same, increment i and check start+1 and end-1
}

// M-2 Two-pointer approach -> Best Method (No need to remove alphanumeric characters and whitespaces before)
bool isPalindrome2(string s)
{
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if (!isalnum(s[left]))
            left++;
        else if (!isalnum(s[right]))
            right--;
        else if (tolower(s[left]) != tolower(s[right]))
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}

// M-3 Iterative approach
bool isPalindrome3(string s)
{
    bool palindrome = true;
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            palindrome = false;
            break;
        }
    }
    return palindrome;
}

// M-4 using swapping and comparing
bool isPalindrome4(string s)
{
    bool palindrome = true;
    string original = s;
    for (int i = 0; i < s.length() / 2; i++)
    {
        swap(s[i], s[s.length() - i - 1]); // OR reverse(s.begin(), s.end());
    }

    if (original == s)
        return true;
    return false;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    // When you erase an element, the size of the string changes, and the positions of the subsequent characters shift accordingly.
    // Hence, start from s.length() - 1.

    for (int i = s.length() - 1; i >= 0; i--)
    {                         // O(n^2)
        s[i] = tolower(s[i]); // tolower() works on single character only, not on string

        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9'))
        {
            s.erase(s.begin() + i); // s.erase() takes  O(n)
        }
        // if (!(isalnum(s[i]))){
        //     s.erase(s.begin() + i);
        // }
    }

    cout << s << endl;

    cout << isPalindrome(s, 0) << endl;
    cout << isPalindrome2(s) << endl;
    cout << isPalindrome3(s) << endl;
    cout << isPalindrome4(s) << endl;

    return 0;
}