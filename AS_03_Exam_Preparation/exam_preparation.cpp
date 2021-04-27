#include <iostream>

using namespace std;

int N, A, B, W;
int D[100000];
int solutions[100000];
int X[100000];

int main()
{
    cin >> N;
    cin >> A;
    cin >> B;
    cin >> W;
    
    for (int i=0; i<N; i++)
    {
        cin >> D[i];
        X[i] = 0;
    }
    //Prepare Day1
    solutions[0] = W-A+B;
    solutions[1] = W+D[0];
    
    int min;    //record evertime candidate's min
    X[0] = 1;    //Use X to record how many days have you been study
    
    
    for (int i=2; i<N+1; i++)
    {
        min = solutions[0];
        //ONLY HAVE THE RIGHT TO STUDY
        for (int j=0; j<i; j++)
        {
            if (solutions[j] < min)
                min = solutions[j];
        
            X[j] = X[j] + 1;
            solutions[j] = solutions[j] - A + X[j]*B;
        }
        //MIN HAVE THE RIGHT TO SLEEP
        solutions[i] = min + D[i-1];
    }
    
    //FIND THE SMALLEST IN SOLUTIONS
    int answer = solutions[0];
    
    for (int i=1; i< N+1; i++)
    {
        if (solutions[i] < answer)
            answer = solutions[i];
    }
    
    cout << answer << endl;
        
}
