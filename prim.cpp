#include <iostream>
#include <cstdio>
#include "utilitygraf.h"
#include <queue>
using namespace std;
using namespace DOT;

typedef long ll;//-----------------Peso
typedef pair< ll, int > ii;//------(Peso,Node)
typedef vector < int > vi;//-------vector of Nodes
typedef vector< ii > vii;//--------vector de adyacencia
typedef pair<ll,pair<int,int> >  i_ii; //----pair<peso,pair<NodeBegin,NodeEnd>> = edge
typedef priority_queue<i_ii ,vector<i_ii>,greater<i_ii> > pqi_ii; //--priority_queue_of_i_ii

// Prim̈́'s Algorithm
void makeEdge(vii *&grafo , int I , int F ,ll peso){
	grafo[I].push_back(ii(peso,F));
	grafo[F].push_back(ii(peso,I));
}

ll cost_MST(vii *&grafo ,int I , int n , vii *&mst){
	vi v(n,0);    // ningun nodo esta visitado
	v[I] = 1;     // nodo de inicio visitado
	pqi_ii pq;    // priority_queue of i_ii
	ll cost = 0;  // costo total del MST

	for(int i=0 ; i<grafo[I].size() ; ++i){
		//pq.push(grafo[I][i]);
		int FF =grafo[I][i].second;
		int PESO =grafo[I][i].first;
		pq.push(i_ii(PESO,make_pair(I,FF)));
	}
	while(!pq.empty()){
		i_ii curr = pq.top(); pq.pop();
		int Node = curr.second.second; ll peso = curr.first;
		int origin = curr.second.first;
		if(!v[Node]){
			v[Node] = 1;
			if(mst) makeEdge(mst,origin,Node,peso);
			for(int i=0 ; i<grafo[Node].size() ; ++i)
				if(!v[grafo[Node][i].second]){
					int FF =grafo[Node][i].second;
					int PESO =grafo[Node][i].first;
					pq.push(i_ii(PESO,make_pair(Node,FF)));
				}
			cost +=peso;
		}
	}
	return cost;
}


int main(){

	freopen("graf.in","r",stdin);
	vii *grafo = NULL , *mst = NULL;
	int n , adys , I , F;
	ll peso; 
	while(scanf("%d %d" , &n, &adys)==2){ 

		grafo = new vii[n];
		mst = new vii[n];

		for(int ad=0 ; ad<adys ; ++ad){
			scanf("%d %d %ld" , &I , &F , &peso);
			grafo[I].push_back(ii(peso,F));
			grafo[F].push_back(ii(peso,I));
		}
		
		printf("Cost MST = %ld\n" , cost_MST(grafo,0,n,mst));

		cout << "making Dot...."<<endl;
		make2Graf(grafo,n,mst,n,"primDotImg.dot");
		cout << "finished Dot.."<<endl;

		cout << "finished...."<<endl;

		delete []grafo; grafo = NULL;	
		delete []mst; mst = NULL;	
	}


	return 0;

}
