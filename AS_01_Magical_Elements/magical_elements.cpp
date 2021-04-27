#include <iostream>
#include <vector>

using namespace std;

int N;  //objects
int K;  //combine times
int S;  //elements
int objects[10000][5];  //components
int temp;   //
int sum;    //
int maxium;    //

void combine(int m, int k, vector<int>combinations)
{
    combinations.push_back(m-1);
    for (int i=m; i<=N-k && k>0; i++)
    {
        combine(i+1, k-1, combinations);
    }

    if (k==0)
    {
        sum = 0;

        for (int i=0; i<S; i++)
        {
            temp = 0;

            for (int j=0; j<combinations.size(); j++)
            {
                //cout << combinations[j] << " " << i << " " << objects[combinations[j]][i] << endl;

                if (objects[combinations[j]][i] > temp)
                    temp = objects[combinations[j]][i];

            }
            //cout << "TEMP = " << temp << endl;
            sum = sum + temp;
        }

        //cout << "SUM = " << sum << endl;

        if (sum > maxium)
            maxium = sum;

        //All of the combinations
        /*
        for (int i=0; i<combinations.size(); i++)
        {
            cout << combinations[i] << " ";
        }
        cout << endl;
        */
    }
}

int main()
{
    int T;      //commands
    vector<int> combinations;
    cin >> T;
    int max1 = 0;
    int max2 = 0;

    for (int i=0; i<T; i++)
    {
        max1 = 0;
        max2 = 0;
        cin >> N >> K >> S;



        if (S == 2)
        {
            max1 = 0;
            max2 = 0;
            for (int y=0; y<N; y++)
            {
                cin >> objects[y][0];
                if (objects[y][0] > max1)
                    max1 = objects[y][0];
                cin >> objects[y][1];
                if (objects[y][1] > max2)
                    max2 = objects[y][1];
            }
            cout << max1 + max2 << endl;
        }

        else
        {
            for (int j=0; j<N; j++)
                for (int k=0; k<S; k++)
                    cin >> objects[j][k];

            maxium = 0;
            for (int i=0; i<=N-K && K>0; i++)
            {
                combine(i+1, K-1, combinations);
            }

            cout << maxium << endl;
        }
    }



    return 0;
}
