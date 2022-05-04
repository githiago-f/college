#include <stdio.h>
#define TAM 8
void imprimeVetor(int vet[]){
    int i;
    printf("vetor: ");
    for(i=0; i<TAM; i++) printf("%d ",vet[i]);
    printf("\n");
}

void deslocarD(int vet[],int indice, int elementos){
    printf("Chamada: deslocarD(vet, %d, %d)\n", indice, elementos);
    if(elementos==0) return; //fazer nada
    if(elementos+indice>TAM -1) return; //fazer nada, ultrapassou limite
        else{
            if(elementos==1){
                vet[indice+1]=vet[indice];
            }
            imprimeVetor(vet);
            deslocarD(vet,indice+1, elementos -1);
            deslocarD(vet,indice,elementos-1);
        }
}

/**
    Este código desloca recursivamente os numeros do vetor a partir da posição 3 até a posição 5.
    O caso base desta função é elementos = 0 e ela cria ramificações binárias em suas chamadas, ou seja
    
**/ 
int main(){
   int vetor[]={1,2,3,5,6,7,1,0};
    imprimeVetor(vetor);
    deslocarD(vetor,3,3);
}
