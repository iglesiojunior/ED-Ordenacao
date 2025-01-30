#include <stdio.h>

// Função de pesquisa binária
int pesquisaBinaria(int arr[], int tamanho, int alvo) {
    int esquerda = 0, direita = tamanho - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == alvo)
            return meio;

        if (arr[meio] > alvo)
            direita = meio - 1;
        else
            esquerda = meio + 1;
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 18, 20, 25};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int alvo;

    printf("Digite o número que deseja procurar: ");
    scanf("%d", &alvo);

    int resultado = pesquisaBinaria(arr, tamanho, alvo);
    
    if (resultado != -1)
        printf("Elemento encontrado na posicão %d\n", resultado);
    else
        printf("Elemento não encontrado\n");

    return 0;
}
