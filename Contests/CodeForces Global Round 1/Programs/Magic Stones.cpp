#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

typedef long long LL;

LL is_permutation(vector <LL> A, vector <LL> B)
{
    sort(all(A));
    sort(all(B));

    int is_equal = (A.size() == B.size() ? true : false);

    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] != B[i])
        {
            is_equal = false;
        }
    }

    return is_equal;
}

void read(vector <LL> &A, int n)
{
    for(int i = 0; i < n; i++)
        cin >> A[i];
}

void get_difference(vector <LL> &A, vector <LL> &D)
{
    for(int i = 0; i + 1 < A.size(); i++)
    {
        D.push_back(A[i + 1] - A[i]);
    }
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <LL> A(no_of_elements);
    read(A, no_of_elements);

    vector <LL> B(no_of_elements);
    read(B, no_of_elements);

    vector <LL> beginning_difference;
    get_difference(A, beginning_difference);

    vector <LL> ending_difference;
    get_difference(B, ending_difference);

    cout << (A[0] == B[0] && is_permutation(beginning_difference, ending_difference) ? "Yes\n" : "No\n");
    return 0;
}
