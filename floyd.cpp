#include <iostream>
#define inf 100

using namespace std;
            // 1   2   3   4   5   6
int M[6][6]={{ 0 , 7 , 3 ,inf,inf,inf}, // 1
             { 7 , 0 , 1 , 6 ,inf,inf}, // 2
             { 3 , 1 , 0 , 3 , 8 ,inf}, // 3
             {inf, 6 , 3 , 0 , 2 , 2 }, // 4
             {inf,inf, 8 , 2 , 0 , 8 }, // 5
             {inf,inf,inf, 2 , 8 , 0 }};// 6


void floyd(int **&matrix, int tam){
    for(int A=0;A<tam;A++){
        for(int B=0;B<tam;B++){
            for(int C=0;C<tam;C++){
                if(matrix[B][C] > (matrix[B][A] + matrix[A][C])){
                   matrix[B][C]= matrix[B][A] + matrix[C][A];
                }
            }
        }
    }
}






int main()
{
    int **matriz;
    int tam =6;

    matriz=new int*[tam];
    for(int i=0; i<tam; i++){matriz[i]=new int[tam];} //crear
    for(int i=0; i<tam; i++){for(int j=0; j<tam; j++){matriz[i][j]=M[i][j];}} //llenar

    floyd(matriz,6);cout<<"\n\n";
    for(int i=0; i<tam; i++){for(int j=0; j<tam; j++){cout<<matriz[i][j]<<" ";}cout<<endl;}//imprime resultado

    return 0;
}






