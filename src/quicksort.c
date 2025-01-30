// Troca dois valores
void trocar(int *valor1, int *valor2){
    int aux = *valor1;
    *valor1 = *valor2;
    *valor2 = aux;
}

// Coloca os elementos menores à esquerda e os maiores à direita de um pivo
int particao(int *valores, int inicio, int fim){
    int pivoComparador = valores[fim];
    int i = (inicio - 1); // Indice do menor elemento

    for (int j = inicio; j <= fim - 1; j++){
        if (valores[j] < pivoComparador){
            i++;
            trocar(valores[i], valores[j]);        
        }

    }

    // Realiza a troca final, que faz o comparador ir exatamente para o meio
    trocar(valores[i+1], valores[fim]);

    // Retorna o indice do MEIO dos valores
    return (i+1);
}

void quickSort(int *valores, int inicio, int fim) {
    // Se houver mais de um elemento no array
    if (inicio < fim){
        int indiceParticionamento = particao(valores, inicio, fim);

        // Subtrai-se 1 do argumento fim que é passado, pois o valor central já está ordenado
        quickSort(valores, inicio, indiceParticionamento - 1);

        // Adiciona-se 1 ao argumento começo, pelo mesmo motivo do comentario acima
        quickSort(valores, indiceParticionamento + 1, fim);
    }
}

void exibirValores(int *valores, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%d ", valores[i]);
    }

    puts("");
}

int main(){
    int valores[] = {3, 7, 5, 18, 21, 13, 18, 1, 12};
    int tam = sizeof(valores) / sizeof(valores[0]); 
    // Resultado esperado = {1, 3, 5, 7, 12, 13, 18, 18, 21}
    quickSort(valores, 0, tam-1);


    printf("Array ordenado: ");
    exibirValores(valores, tam);

    return 0;
}