#include <iostream>
#include <queue>
using namespace std;
class Grafo{
public:
    int n;
    int **grafo;
    int *colorsVertex;
    string *colors;
    Grafo(int n){
        this->n=n;
        this->grafo=new int*[n];
        for (int i=0;i<n;i++){
            this->grafo[i]=new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grafo[i][j]=0;
            }
        }
        this->colorsVertex=new int[n];
        this->colors=new string[n];
    }
    void bfs(int i){
        for(int i=0;i<this->n;i++){
            this->colors[i]="WHITE";
        }
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int v=0;v<this->n;v++){
                if(this->grafo[u][v]==1&&this->colors[v]=="WHITE"){
                    this->colors[v]="GRAY";
                    Q.push(v);
                }
            }
            colors[u]="Black";
        }
    }
};
int main(){
    int t,n,m,p,k;
    cin >> t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>m;
        cin>>p;
        cin>>k;
        Grafo g(n);
        for(int i=0;i<n;i++){
            int color;
            cin >>color;
            g.colorsVertex[i]=color;
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x;
            cin>>y;
            g.grafo[x-1][y-1]=1;
            g.grafo[y-1][x-1]=1;
        }
        g.bfs(0);
        queue <int> aux;
        for(int i=0;i<n;i++){
            if(g.colors[i]=="WHITE"){
                aux.push(i);
            }
        }
        for(int i=0;i<p;i++){
            bool inserted=false;
            for(int i=0;!inserted&&i<n;i++){
                if(g.colorsVertex[aux.front()]!=g.colorsVertex[i]){
                    g.grafo[aux.front()][i]=1;
                    g.grafo[i][aux.front()]=1;
                    inserted=true;
                }
            }
            aux.pop();
        }
        g.bfs(0);
        bool resp=true;
        for(int i=0;i<n;i++){
            if(resp==true&&g.colors[i]=="WHITE"){
                resp=false;
            }
        }
        if(resp){
            cout<<"Y\n\n";
        }else{
            cout<<"N\n\n";
        }   
    }
    return 0;
}
