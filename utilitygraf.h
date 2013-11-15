#include <vector>
#include <utility>
#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <map> 

using namespace std;
typedef unsigned long long ll_;
const ll_ inf = 1<<30;//(1<<30)*1.9999999999;

namespace DOT{
	typedef ll_ T;
	string CO = string(1,34); //comilla (")

	string tostr(T i){	
		stringstream st; st<<i; 
		return st.str();
	}
	ostream& putMatx(ostream& os , T**&M , int dx, int dy , string k=""){
		map<T,bool> edge; 
		for (int i = 0; i < dy; ++i)
			for (int j = 0; j < dx; ++j){
				T key = (i+1)*11*(j+1)*11*(i+1)*(j+1);
				if( (i!=j) && M[i][j] != inf && !edge[key]){
					os<<CO<<k<<tostr(i)<<CO<<"--"<<CO<<k<<tostr(j)<<CO
			          <<"[label = "<<CO<<tostr(M[i][j])<<CO<<"];\n";
			        edge[key] = 1;  
			    }
			}
		return os;
	}
	ostream& putMatx(ostream& os ,vector<pair<long,int> >*M,int n, string k=""){
		map<int,bool> edge; 
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<M[i].size() ; ++j){
				long peso = (long)M[i][j].first;
				int F = M[i][j].second;
				int key = (i+1)*11*(F+1)*11*(i+1)*(F+1);
				if(edge[key]) continue;
				os<<CO<<k<<tostr(i)<<CO<<"--"<<CO<<k<<tostr(F)<<CO
			    <<"[label = "<<CO<<tostr(peso)<<CO<<"];\n";
			    edge[key] = 1;  	
			}
		}	
		return os;
	}

	void make1Graf(T **&M , int dx , int dy , string file){
		ofstream of(file.c_str() , ios_base::out); 
		of << "graph G{\n"; //inicianzo grafo
		of << "edge[color = red , fontcolor = blue , weight = 20];\n";
		of << "node[color = brown];\n";
		putMatx(of,M,dx,dy);
		of <<"}";
		of.close();
	}
	void make1Graf(vector<pair<long,int> > *&m1 , int n1 , string file){
		ofstream of(file.c_str() , ios_base::out); 
		of << "graph G{\n"; //inicianzo grafo
		of << "edge[color = red , fontcolor = blue , weight = 20];\n";
		of << "node[color = brown];\n";
		putMatx(of,m1,n1);
		of <<"}";
		of.close();
	}

	void make2Graf(T **&M1 , int dx1 , int dy1 ,T **&M2 , int dx2 , int dy2, string file){
		ofstream of(file.c_str() , ios_base::out); 
		of << "graph G{\n"; //inicianzo grafo
		of << "edge[color = red , fontcolor = blue , weight = 20];\n";
		of << "node[color = brown];\n";
		putMatx(of,M1,dx1,dy1);
		putMatx(of,M2,dx2,dy2," ");
		of <<"}";
		of.close();
	}
	void make2Graf(vector<pair<long,int> > *&m1 , int n1 , vector<pair<long,int> > *&m2 ,int n2 , string file){
		ofstream of(file.c_str() , ios_base::out); 
		of << "graph G{\n"; //inicianzo grafo
		of << "edge[color = red , fontcolor = blue , weight = 20];\n";
		of << "node[color = brown];\n";
		putMatx(of,m1,n1);
		putMatx(of,m2,n2," ");
		of <<"}";
		of.close();
	}



};

namespace MATRIX{
	typedef ll_ T;
	
	void makeMatriz(T **&M , int dx , int dy , int val = 0){
		M = new T*[dy+1];
		for(int i=0 ; i<dy ; ++i)
			M[i] = new T[dx+1];
		
		for(int i=0 ; i<dy ; ++i)
		for(int j=0 ; j<dx ; ++j)
			M[i][j] = val;
	}
 	void destroyMatriz(T **&M , int dx){
		for(int i=0 ; i<dx ; ++i)
			 	delete M[i];
		delete []M;	
	}
	void copyMatrizIn(T **&old , T**&new_ , int n){
		for(int i=0 ; i<n ; ++i)
			for(int j=0 ; j<n ; ++j)
				new_[i][j] = old[i][j];
	}
};

