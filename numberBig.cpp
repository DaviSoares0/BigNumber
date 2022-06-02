#include<stdio.h>
#include<queue>
#include<list>

using namespace std;

list<int> soma(list<int>, list<int>);
list<int> subtracao(list<int>, list<int>);
list<int> vezes10(list <int> *, list <int> *);



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

    int qtd1 = 0; /*Armazena o tamanho do 1 ° bigNumber*/
    int qtd2 = 0; /*Armazena o tamanho do 2° bigNumber*/
    
    /*Pedindo que o usuario informe o tamanho do bigNumber*/
    printf("Digite A quantidade de digitos do BigNumber:\n");
    scanf("%d", &qtd1);

    /*Pedindo que o usuario informe o big number*/
    int big_Number1;/*Armazena os valores inseridos pelo user*/
    printf("Informe um big number:\n");
    for(int i = 0; i < qtd1; i++){
       scanf("%d", &big_Number1);
       N.push_back(big_Number1); /*Armazenando os valores que o usuário digita na Lista N*/
    }

    /*Pedindo que o usuario informe o tamanho do bigNumber*/
    printf("Digite A quantidade de digitos de outro BigNumber:\n");
    scanf("%d", &qtd2);
    /*Pedindo que o usuario informe o big number*/
    int big_Number2;/*Armazena os valores inseridos pelo user*/
    printf("Informe um big number:\n");
    for(int i = 0; i < qtd2; i++){
        scanf("%d", &big_Number2);
        M.push_back(big_Number2);/*Armazenando os valores que o usuário digita na Lista M*/
    }

    /*Completa o tamho da lista caso elas sejam diferentes*/
    int aux;
    if(qtd1 > qtd2){
        aux = qtd1 - qtd2;
        for(int i = 0; i < aux; i++){
            M.push_front(0);
        }
    }else{
        aux = qtd2 - qtd1;
        for(int i = 0; i < aux; i++){
            N.push_front(0);
        }
    }

  
    printf("Os dois bigNumbers digitados foram\n");
    printf("1°: ");
    printNumber(N);
    printf("2°: ");
    printNumber(M);

     printf("\n");
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

    //Vezes 10
    printf("\tVezes 10\n");
    vezes10(&N, &M);
    printf("\t");
    printNumber(N);
    printf("\t");
    printNumber(M);
    


}

list<int> vezes10(list<int> *N, list<int> *M){

 
    (*N).push_back(0);
    (*M).push_back(0);
    return (*N, *M);
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
    int subtracao, x, y, aux = 0;
    
    itA = A.end();
    itB = B.end();

    itA--;
    itB--;

    while(itA != A.begin()){
        x = *itA;
        y = *itB;

        if (y > x)
        {
            itA--;
            if(*itA != 0){
           *itA-=1;
            itA++;
            x += 10;
            }else{
            itA++;    
            }
            subtracao = x - y;
            if (subtracao > 0){
            D.push_front(subtracao);
            itA--;
            itB--;     
            }else{
            subtracao = subtracao * -1; 
            D.push_front(subtracao);  
            itA--;
            itB--;}
        }else if(x > y){
            itB--;
            if(*itB != 0){
                *itB-=1;
                itB++;
                y += 10;
            }else{
                itB++;    
            }
            subtracao = x - y;
            if (itB != B.begin()){
            if (subtracao > 0){
            D.push_front(subtracao);
            itA--;
            itB--;     
            }else{
            subtracao = subtracao * -1; 
            D.push_front(subtracao);  
            itA--;
            itB--;}  
            }
        }else{
            x = *itA;
            y = *itB;
            subtracao = x - y;
            subtracao = subtracao;
            D.push_front(subtracao);
            itA--;
            itB--;
        }
    }
    x = *itA;
    y = *itB;

    if( x == 0 && y == 0){
        return D;
    } else{
        subtracao = x - y;
        D.push_front(subtracao);
    }

    return D;
}
