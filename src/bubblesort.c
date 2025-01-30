#include <stdio.h>

void bolha(int quant, int *v)
{
    int i, j, t;
    int troca;
    for (i = quant - 1; i >= 1; i--)
    {
        troca = 0;
        for (j = 0; j < i; j++)
        {
            if (v[j] > v[j + 1])
            {
                printf("Log bolha para o numero %d:\n", v[j]);
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                troca = 1;
            }
            for (t = 0; t < quant; t++)
            {   
                if(t == quant-1){
                    printf("%d\n", v[t]);
                }else{
                    printf("%d", v[t]);
                }
            }
        }
        if (troca == 0)
        {
            break;
        }
    }
}

int main()
{
    int v[] = {5, 4, 3, 2, 1};
    bolha(5, v);
    return 0;
}