# HW3 Exam Preparation
## Pseudo code:
```
int main()
{
    //READ DATA
    int solutions[100000] //Record every time candidate’s remaining units
    int X[100000] //Use X to record how many days have you been study
    
    //Prepare for Day1
    solutions[0] = W-A+B;
    solutions[1] = W+D[0];
    
    int min; //record evertime candidate's min
    X[0] = 1; //Initially, first day is one. Others initial as 0
    
    //Start From Day2
    for (int i=2; i<N+1; i++)
    {
        min = solutions[0];
        //ONLY HAVE THE RIGHT TO STUDY
        //Also Record min
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

    //FIND THE SMALLEST IN SOLUTIONS, AND THAT WILL BE THE ANSWER

    cout << answer << endl;
}
```

# 解釋
第一天我們列出讀跟睡的情況並從中找尋最小值

由於較大的值+下一天睡覺必定會大於最小值+下一天睡覺
（因為睡覺會中斷連續讀書所帶來之副作用）

因此較大的值下一天只能讀書不能睡覺 (因為不會是最佳解）
反之最小的值下一天可以讀書或是睡覺

每次會比上次多一筆計算量

再繼續找最小值並重複步驟

因此可知時間複雜度為

2+3+4.....+N+1
Time Complexity = O(N^2)
