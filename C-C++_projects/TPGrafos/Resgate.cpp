#include <iostream>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
class Grafo{
public:
    int n;
    double **grafo;
    double *chave;
    queue<int>agm; 
    Grafo(int n){
        this->n=n;
        this->grafo=new double*[n];
        for(int i=0;i<n;i++){
            grafo[i]=new double[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grafo[i][j]=0;
            }
        }
        chave=new double[n];
    }
    void prim(int r){
        for(int i=0;i<this->n;i++){
            this->chave[i]=INFINITY;
        }
        chave[r]=0;
        priority_queue<int> q;
        for(int i=0;i<this->n;i++){
            q.push(i);
        }
        while(!q.empty()){
            int u=q.top();
            q.pop();
            this->agm.push(u);
            for(int v=0;v<this->n;v++){
                double w=this->grafo[u][v];
                if(this->grafo[u][v]!=0&&w<this->chave[v]){
                    this->chave[v]=w;
                }
            }
        }
    }
};
int main(){
    int c,n;
    cin >> c;
    for(int i=0;i<c;i++){
        cin >> n;
        Grafo g(n);
        int x[n];
        int y[n];
        for (int i = 0;i<n;i++){
            cin>>x[i];
            cin>>y[i]; 
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                double dist=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
                g.grafo[i][j]=dist;
            }
        }
        g.prim(0);

        double resp=0;
        int aux=g.agm.front();
        g.agm.pop();
        for(int i=0;i<n-1;i++){
            resp=resp+g.grafo[aux][g.agm.front()];
            aux=g.agm.front();
            g.agm.pop();
        }
        resp=resp/100,0;
        cout<<fixed;
        cout<<setprecision(2);
        cout <<resp<<"\n\n"; 
    }
    return 0;
}