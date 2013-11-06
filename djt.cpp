#include <iostream> 
#define inf 100 
using namespace std; 
                   //1   2   3   4   5    6
int matrix[6][6] = {{0,  7,  3,  inf,inf,inf},  //1
					{7,  0,  1,  6,  inf,inf},  //2
					{3,  1,  0,  3,  8,  inf},  //3
					{inf,6,  3,  0,  2,  2  },  //4
					{inf,inf,8,  2,  0,  8  },  //5
					{inf,inf,inf,2,  8,  0  }}; //6

int min(int a,int b){if(a<b){return a;} else return b;}

void copiar(int M[6][6],int size_nodos,int vec[6]){
	for(int i=0;i<size_nodos;i++){
		vec[i]=M[0][i];
		}		
	for(int j=0;j<size_nodos;j++)
	{cout<<"pos "<<j<<" : "<<vec[j]<<endl;}
    
	}

bool hay_cero(int vec_bool[6],int size_nodos){
	for(int i=0;i<size_nodos;i++){
		if(vec_bool[i]==0){return true;}
		}
	return false;
	}

int get_min(int vec_bool[],int d[],int size_nodos){
	int indice_min;
	int j;
	for(int i=0;i<size_nodos;i++){
		if(vec_bool[i]==0){
			j=i;
			indice_min = i; 
			break;}
      }
    j++;
     for(j;j<6;j++){
		 if(vec_bool[j]==0){
			 if(d[j] < d[indice_min]){
				 indice_min=j;
			}
		}	 
     } 
     return indice_min;
}

void djt(){
	//creamos los vectores 
	int c[6]={0,0,0,0,0,0}; //llenamos con ceros 
	int d[6];
	
	c[0]=1;//inicialisamos 
	copiar(matrix,6,d);//mejorar para 6 (codigo duro)
	//algoritmo boras O.o
	while(hay_cero(c,6)){
		int p = get_min(c,d,6);
		c[p]=1;//seccionado / marcamos 1  en el vector de bools
	
		for(int i=0;i<6;i++){
			if(c[i]==0){
				d[i] = min(d[i],(d[p]+matrix[p][i]));
			}
	     }	
	}
	for(int j=0;j<6;j++){
		cout<<d[j]<<" ";
		}
		cout<<endl;
}




int main(){
	djt();
	
	return 0;
	}
