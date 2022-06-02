#include<stdio.h>
#include<queue>
#include<list>


using namespace std;

list<int> soma(list<int>, list<int>);
list<int> subtracao(list<int>, list<int>);
list<int> vezes10(list<int>*);



void printNumber(list<int> Number){
    list<int>::iterator it;
    for (it = Number.begin(); it != Number.end(); it++)
    {
        printf("%d", *it);
    }
    printf("\n");
    
}

int main(){


    list<int> N;
    list<int> M;

    /*Pede um bigNUmber ao usuário*/
    printf("Informe quantos digitos tem o bigNumber:\n");
    int nC; /*Armazena o tamanho do bigNUmber*/
    scanf("%d", &nC);
    int V[nC]; /*Cria um vetor com o tamanho informado*/
    printf("Digite o bigNUmber:\n");
    /*O usuário informa o bigNumber que é armazenado no vetor */
    for(int a = 0; a < nC; a++){
        scanf("%d", &V[a]);/*Armazena o big Number*/
    }

    /*Pede um bigNUmber ao usuário*/
    printf("Informe quantos digitos tem o bigNumber\n");
    int nCC; /*Armazena o tamanho do bigNUmber*/
    scanf("%d", &nCC);
    int v[nCC];  /*Cria um vetor com o tamanho informado*/
    printf("Digite o bigNUmber\n");
     /*O usuário informa o bigNumber que é armazenado no vetor */
    for(int b = 0; b < nCC; b++){
        scanf("%d", &v[b]);/*Armazena o big Number*/
    }


   // int V[] = {1,9,1,1,1,5};//vetor do exercicio
   // int v[] = {1,5,1,4,1,6};// vetor teste

  

    /*Colocando os valores de V na lista N*/
    for(size_t i = 0; i < nC; i++)
    {
        N.push_back(V[i]);
    }
    
    /*Coloando os valores do v na lista M*/
    for (size_t i = 0; i < nCC; i++)
    {
        M.push_back(v[i]);
    }

    printf("Os dois bigNumbers digitados foram\n\n");
    printNumber(N);
    printNumber(M);

    //SOMA
    printf("\tSOMA\n\n");
    printf("\t  ");
    printNumber(N);
    printf("\t+ ");

    printNumber(M);
    printf("\t---------\n");
    list<int> C = soma(N, M);/*Chamando a função soma passando como parâmetros a lista N  e M que corresponde ao vetor V e v*/
    printf("\t  "); 
    printNumber(C);
    

    //SUBTRAÇÃO   
    printf("\n\tSubtracao\n\n");
    printf("\t  ");
    printNumber(N);
    printf("\t- ");

    printNumber(M);
    printf("\t---------\n");
    list<int> D = subtracao(N,M); /*Chamando a função subtracao passando como parâmetros a lista N  e M que corresponde ao vetor V e v*/
    printf("\t  ");  
    printNumber(D);

}

list<int> vezes10(list<int> *N){
    (*N).push_back(0);
    return (*N);
}

list<int> soma(list<int> A, list<int> B){
    list<int> C; //Lista que armazena o resultado da soma
    list<int>::iterator itA;
    list<int>::iterator itB;
    int soma, x, y, aux=0;
    
    itA = A.end();
    itB = B.end();

    itA--;
    itB--;

    while(itA != A.begin()){
        x = *itA;
        y = *itB;
        soma = x + y + aux;
        aux = (soma > 9) ? 1 : 0;
        C.push_front(soma%10);
        itA--;
        itB--;
    }
    x = *itA;
    y = *itB;
    soma = x + y + aux;
    aux = (soma > 9) ? 1 : 0;
    C.push_front(soma%10);
    itA--;
    itB--;
    return C;
}

list<int> subtracao(list<int> A, list<int> B){
    list<int> D;//Lista que armazena o resultado da subtração
    list<int>::iterator itA;
    list<int>::iterator itB;
    int subtracao, x, y, aux=0;
    
    itA = A.end();
    itB = B.end();

    itA--;
    itB--;

    while(itA != A.begin()){
        x = *itA;
        y = *itB;
        if (y > x){
        itA--;
        *itA-=1;
        itA++;
        x += 10;
        }
        subtracao = x - y;
        D.push_front(subtracao);
        itA--;
        itB--;

    }
    x = *itA;
    y = *itB;
   if (B > A){
        itA--;
        x -= 1;
        itA++;
        x += 10;
        subtracao = x - y;
        D.push_front(subtracao);
        itA--;
        itB--;
    }else{
     subtracao = x - y;
        D.push_front(subtracao);
        itA--;
        itB--;
    }
    return D;
}
