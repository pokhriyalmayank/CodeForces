#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int is_vowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u': return true;
    }

    return false;
}

int main()
{
    string S;
    cin >> S;

    char last_ch = S[S.size() - 1];
    int good_string = (!is_vowel(last_ch) && last_ch != 'n' ? false : true);

    for(int i = 0; i + 1 < S.size(); i++)
    {
        if(S[i] == 'n') continue;

        if(!is_vowel(S[i]) && !is_vowel(S[i + 1]))
        {
            good_string = false;
        }
    }

    cout << (good_string ? "YES" : "NO");
    return 0;
}
