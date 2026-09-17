#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int *inversao(int vetor[], int n);
void buscaSequencial(int vetor[], int n, int s);
void buscaBinaria(int vetor[], int n, int s);
void buscaBinariaRecursiva(int vetor[], int L, int R, int s);

long long comparacao = 0;  //contabilizando quantas comparacoes foram feitas
long long atribuicao = 0;  //contabilizando quantas atribuicoes foram feitas

void comp_atrib(){ //exibe contagem final e reseta valores
    printf("Comparacao = %lld\n",comparacao);
    printf("Atribuicao = %lld\n",atribuicao);
    comparacao = 0;
    atribuicao = 0;
}

int main() {

    // Declaração de Variáveis e entrada do tamanho do vetor.
    int n;
    scanf("%d", &n);
    int *V = malloc (n * sizeof(int));
    
    // Preenchimento do vetor
    for(int i = 0; i < n; i++){
        scanf("%d", &V[i]);
    }

    // Continuidade das operações até encerramento com do-while

    int opcao = 0;                                                  
    do{

        // MENU 

        // Leitura da opção escolhida

        scanf("%d", &opcao);
        
        // Estrutura de Condição para decisão da operação

        if(opcao == 1){

            int *vetorInvertido = inversao(V, n);  
            atribuicao++;                                              //atrib. para int *vetorInvertido
        
            for(int i = 0; i < n; i++){
                printf("%d ", vetorInvertido[i]);  //nao contabiliza aqui porque é apenas exibição
            }

            printf("\n");
            comp_atrib();

            free(vetorInvertido);

        } else if(opcao == 2){                          

            int s = 0;
            atribuicao++;                                              //atrib. para o int s = 0

            scanf("%d", &s);
            buscaSequencial(V, n, s);

            comp_atrib();

        } else if(opcao == 3){                       

            int s = 0;
            atribuicao++;                                              //atrib. para int s = 0

            scanf("%d", &s);
            buscaBinaria(V, n, s);

            comp_atrib();

        } else if(opcao == 4){                          

            int s = 0;
            atribuicao++;                                              //atrib. int s = 0

            scanf("%d", &s);
            buscaBinariaRecursiva(V, 0, n-1, s);

            comp_atrib();

        } 

    } while(opcao != 5);
    
    free(V);
    return 0;
}

int *inversao(int vetor[], int n){

        /*
            Esta é a função pela qual ocorre a inversão do vetor. Começamos a percorrer o vetor inicial da direita
            para a esquerda, ao passo que o Vetor Invertido é preenchido, com os valores encontrados no vetor inicial, da esquerda para a direita.
        */
        int *vetorInvertido = malloc(sizeof(int)*n);               
        atribuicao++;                                               //atrib. para int *vetorInvertido
        
        int i = n - 1;                                             
        atribuicao++;                                               //atrib. para int i = n-1

        int j = 0;                                                 
        atribuicao++;                                               //atrib. para int j = 0

        while(i >= 0){
            comparacao++;                                           //comp. para i >= 0

            vetorInvertido[j] = vetor[i];
            atribuicao++;                                           //atrib. para vetorInvertido[j]

            i--;
            atribuicao++;                                           //atrib. para i--

            j++;
            atribuicao++;                                           //atrib para j++

        }
        comparacao++;                                               //comp. da quebra de laco
        return vetorInvertido;
}


void buscaSequencial(int vetor[], int n, int s){
    // Estrutura de busca sequencial: 
    atribuicao++;                                                   //atrib. para i = 0
    for(int i = 0; i < n; i++){
        comparacao++;                                               //comp. para i < n

        comparacao++;                                           //comp. para vetor[i] == s
        if(vetor[i] == s){
            // Função encerrada, caso valor seja encontrado
            printf("SIM\n");
            return;
        }

        atribuicao++;                                               //atrib. para i++
    } 
    comparacao++;                                                   //comp. da quebra de laco

    // Como função ainda não foi encerrada, o valor não está no vetor
    printf("NAO\n");
    return ;
}

void buscaBinaria(int vetor[], int n, int s){
    
    // Ponteiros para a direita e para a esquerda
    int L = 0;
    atribuicao++;                                                           //atrib. para int L = 0

    int R = n - 1;
    atribuicao++;                                                           //atrib. para int R = n-1

    int meio = 0;
    atribuicao++;                                                           //atrib. para int meio = 0


    while(L <= R){
        comparacao++;                                                       //comp. para L <= R

        // Encontrando novo meio
         meio = L + (R - L) / 2;
            atribuicao++;                                                   //atrib. para meio

        comparacao++;                                                       //comp. para vetor[meio] == s
        if(vetor[meio] == s){
            // Caso a posição cotenha o valor procurado, ela é encerrada
            printf("SIM\n");
            return;
        }

        comparacao++;                                                       //comp. para vetor[meio] > s
        if(vetor[meio] > s){
            // Caso o meio seja maior que o valor a ser encontrado, é preciso ir para a esquerda,
            // Assim, o Right é decrementado (teto).
            R = meio - 1;                                                 
            atribuicao++;                                                   //atrib. para R = meio - 1

        } else {
            // Caso o meio seja menor que o valor a ser encontrado, é preciso andar para 
            // a direita, assim o valor de Left é incrementado (chao).
            L = meio + 1;
            atribuicao++;                                                   //atrib. para L = meio + 1
        }

    }
    comparacao++;                                                           //comp. da quebra de laco

    printf("NAO\n");
    return;
}

void buscaBinariaRecursiva(int vetor[], int L, int R,int s){

    comparacao++;                                                     //comp. L > R 
    if(L > R) {
        printf("NAO\n");
        return;
    }

    int meio = L + (R - L) / 2;
    atribuicao++;                                                       //atrib. int meio

    comparacao++;                                                     //comp. para vetor[meio] == s
    if(vetor[meio] == s){
        printf("SIM\n");
        return;
    }

    comparacao++;                                                     //comp. para vetor[meio] > s
    if(vetor[meio] > s){
        return buscaBinariaRecursiva(vetor, L, meio-1, s);
    } 
        return buscaBinariaRecursiva(vetor, meio+1, R, s);

}
