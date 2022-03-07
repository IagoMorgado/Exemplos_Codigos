#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
class Grafo{
    public:
    int **grafo;
    int n;
    string *colors;
    Grafo(int n){
        this->n=n;
        this->grafo=new int*[n];
        for(int i=0;i<n;i++){
            grafo[i]=new int[n];
        }
        colors=new string[n];
    }
    void insertEdge(int v,int w,int p){
        if(p==1){
            this->grafo[v][w]=1;
        }else
        {
            this->grafo[v][w]=1;
            this->grafo[w][v]=1;
        }
    }
    void bfs(int i){
        int resp;
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
    int n,m,v,w,p,resp;
    cin >> n;
    cin >> m;
    while (n!=0&&m!=0)
    {
        Grafo a(n);
        for(int i=0;i<m;i++){
            cin >> v;
            cin >> w;
            cin >> p;
            a.insertEdge(v-1,w-1,p);
        }
        for(int i=0;i<n;i++){
            a.bfs(i);              
        }
        resp=1;
        for(int i=0;i<n;i++){
            if(resp==1){
                if(a.colors[i]=="WHITE"){
                    resp=0;
                }
            }
        }
        cout << resp << "\n";
        cin >> n;
        cin >> m;
    } 
    return 0;
}