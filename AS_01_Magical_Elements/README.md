# HW1 Magical Elements
[Problem](Problem.md)
## Pseudo code:
```
void combine(int m, int k, vector<int>combinations)
{
    combinations.push_back(m-1);
    for (int i=m; i<=N-k && k>0; i++)
        combine(i+1, k-1, combinations); //選取傳進來的第一個元素或不選
    if (k==0)
    {
        sum = 0;
        for (int i=0; i<S; i++)
        {
            temp = 0;
            for (int j=0; j<combinations.size(); j++)
            {
                if (objects[combinations[j]][i] > temp)
                    temp = objects[combinations[j]][i];
            }
        sum = sum + temp;
    }
    if (sum > maxium)
        maxium = sum;
    }
}

int main()
{
    cin >> ……… //讀取資料 M, N, K
    for (int i=0; i<=N-K && K>0; i++)
        combine(i+1, K-1, combinations); //選取第一個元素或不選
}
```

# 解釋
題目要求為從 N 把武器中選取 K 把進行組合。
因此我將所有組合列出，採用的方法為檢查所有 N 把武器，當檢查到第幾把武
器時可以選擇要或不要這把武器，以此類推，最後當 k=0 時代表已沒有武器可
以進行選擇，因此將選擇的武器進行組合計算出其 Energy，並在與此前最大值
的 max(初始為 0)進行比較，若較大則其為新的 max。
因方法為檢查全部 N 把武器進行選擇和不選擇，因此 BigO 為 O(2^n)。