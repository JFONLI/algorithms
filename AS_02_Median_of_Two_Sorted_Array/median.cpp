#include <vector>
#include <iostream>

using namespace std;

vector<int> array1;
vector<int> array2;
int input;

int maximum(int a, int b)
{
    return a > b ? a : b;
}

int minimum(int a, int b)
{
    return a < b ? a : b;
}

int find_mid(int N)
{
    int index1 = 0, index2 = N, i, j;
    int median1, median2;

    while (index1 <= index2)
    {
        i = (index1 + index2) / 2;
        j = N-i;

        if (i>0 && j<N && array1[i-1] > array2[j])
            index2 = i - 1;

        else if (i<N && j>0 && array2[j-1] > array1[i])
            index1 = i + 1;

        else
        {
            if (i == 0)
            {
                median1 = array1[0];
                median2 = array2[N-1];
            }
            else if (j == 0)
            {
                median1 = array1[N-1];
                median2 = array2[0];
            }
            else
            {
                median1 = maximum(array1[i-1], array2[j-1]);
                median2 = minimum(array1[i], array2[j]);
            }
            break;
        }

    }

    return (median1+median2)/2;

}

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> input;
        array1.push_back(input);
    }

    for (int i=0; i<N; i++)
    {
        cin >> input;
        array2.push_back(input);
    }

    //cout << "finish entering" << endl;
    int ans = find_mid(N);
    cout << ans << endl;

    return 0;

}
