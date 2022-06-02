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
    //int V[] = {1,2,1,2,1,4,5,2,3,8,6,4,5,8,9,5,3,1,3,5,7,9,1,5,4,1,0,9,0,8,7,6,7};
    int V[] = {1,9,1,1,1,5};//vetor do exercicio
    int v[] = {1,5,1,4,1,6};// vetor teste
    for (size_t i = 0; i < 6; i++)
    {
        N.push_back(V[i]);
    }
    for (size_t i = 0; i < 6; i++)
    {
        M.push_back(v[i]);
    }

    
  
    printf("Os dois bigNumbers do vetor sao:\n");
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
    printf("\n");
    printf("\tVezes 10\n\n");
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

        if (y > x) /*Faz a operacao de "Pegar emprestado"*/
        {
            itA--;
            *itA-=1;
            itA++;
            x += 10;
            subtracao = x - y;
            D.push_front(subtracao);
            itA--;
            itB--;
        }  else if(x > y){
           /* itB--;
            *itB-=1;
            itB++;
            y += 10;*/
            subtracao = x - y;
            D.push_front(subtracao);
            itA--;
            itB--;
        
        /*}else if(x > 0 && y == 0){ 
            itB--;
            *itB-=1;
            itB++;
            y += 10;
            subtracao = x - y;
            D.push_front(subtracao);
            itA--;
            itB--; */
                
            /*subtracao = x - y;
            D.push_front(subtracao);
            itA--;
            itB--;*/
        }else{
           /* x = *itA;
            y = *itB;
            subtracao = x - y;
            subtracao = subtracao * -1;
            D.push_front(subtracao);
            itA--;
            itB--;*/
        }
    }
    x = *itA;
    y = *itB;

    if( x == 0 && y == 0){
        return D;
    }else{
        subtracao = x - y;
        D.push_front(subtracao);
    }
    return D;
}
    
