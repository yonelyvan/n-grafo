#include <iostream> 
#include <vector>
#define inf 100  // valor infinito'
using namespace std;

 
int M[6][6]={{0,  7,  3,  inf,inf,inf}, 
		     {7,  0,  1,  6,  inf,inf}, 
		     {3,  1,  0,  3,  8,  inf}, 
		     {inf,6,  3,  0,  2,  2  },  
	         {inf,inf,8,  2,  0,  8  },  
		     {inf,inf,inf,2,  8,  0  }}; 	
 
 
int min(int a,int b){if(a<b){return a;} else return b;}



template<class T>
void copiar(int **matrix,vector<T> &d){
	for(int i=0;i<d.size();i++){
		d[i]=matrix[0][i];
		}		
}




template<class T>
bool hay_cero(vector<T> &vec_bool){
	for(int i=0;i<vec_bool.size();i++){
		if(vec_bool[i]==0){return true;}
		}
	return false;
	}



template<class B,class T>
int get_min(vector<B> &vec_bool,vector<T> &d){
	int indice_min=0;
	int j=0;
	while(!indice_min){
     		if(vec_bool[j]==0){
	    		indice_min = j;
			   }
		    j++;
	}
	for(j;j<d.size();j++){
		if( vec_bool[j]==0 && d[j] < d[indice_min]){
			indice_min =j;
			}
	}
 
     return indice_min;
}


//--------------------------------------------------------

template<class T>
vector<int> djt(T **matrix,int size_matrix){
	//creamos los vectores 
	vector<bool> c(size_matrix); for(int i=0;i<c.size();i++){c[i]=0;}//llenamos con ceros 
	vector<int> d(6);
	c[0]=1;//inicialisamos con un nodo 
	copiar(matrix,d);

	while(hay_cero(c)){
		int p = get_min(c,d);
		c[p]=1;//seccionado / marcamos 1  en el vector booleano 
		for(int i=0;i<d.size();i++){
			if(c[i]==0){
				d[i] = min(d[i],(d[p]+matrix[p][i]));
			}
	     }	
	}
	return d;
}





int main(){
	int **matriz;
matriz=new int*[6];
for(int i=0; i<6; i++){matriz[i]=new int[6];} //crear
for(int i=0; i<6; i++){for(int j=0; j<6; j++){matriz[i][j]=M[i][j];}} //lenar

vector<int> n(6);
n=djt(matriz,6);

for(int i=0;i<n.size();i++){cout<<n[i]<<" ";}cout<<endl;
	return 0;
	}
