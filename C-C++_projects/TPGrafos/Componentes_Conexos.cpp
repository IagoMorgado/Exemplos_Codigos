#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
class Grafo{
public:
    int tam;
    int **grafo;
    string *colors;
    bool *visited;
    Grafo(int tam){
        this->tam=tam;
        this->grafo=new int*[tam];
        for(int i=0;i<tam;i++){
            grafo[i]=new int[tam];
        }
        for(int i=0;i<tam;i++){
            for(int j=0;j<tam;j++){
                grafo[i][j]=0;
            }
        }
        colors=new string[tam];
        visited=new bool[tam];
        memset(visited,false,sizeof(bool)*tam);
    }
    void bfs(int i){
        for(int i=0;i<this->tam;i++){
            this->colors[i]="WHITE";
        }
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int v=0;v<this->tam;v++){
                if(this->grafo[u][v]==1&&this->colors[v]=="WHITE"){
                    this->colors[v]="GRAY";
                    Q.push(v);
                }
            }
            colors[u]="Black";
        }
    }
};
int decode(char c){
    int resp;
    if(c=='a'){
        resp=0;
    }else if(c=='b'){
        resp=1;
    }else if(c=='c'){
        resp=2;
    }else if(c=='d'){
        resp=3;
    }else if(c=='e'){
        resp=4;
    }else if(c=='f'){
        resp=5;
    }else if(c=='g'){
        resp=6;
    }else if(c=='h'){
        resp=7;
    }else if(c=='i'){
        resp=8;
    }else if(c=='j'){
        resp=9;
    }else if(c=='k'){
        resp=10;
    }else if(c=='l'){
        resp=11;
    }else if(c=='m'){
        resp=12;
    }else if(c=='n'){
        resp=13;
    }else if(c=='o'){
        resp=14;
    }else if(c=='p'){
        resp=15;
    }else if(c=='q'){
        resp=16;
    }else if(c=='r'){
        resp=17;
    }else if(c=='s'){
        resp=18;
    }else if(c=='t'){
        resp=19;
    }else if(c=='u'){
        resp=20;
    }else if(c=='v'){
        resp=21;
    }else if(c=='w'){
        resp=22;
    }else if(c=='x'){
        resp=23;
    }else if(c=='y'){
        resp=24;
    }else if(c=='z'){
        resp=25;
    }
    return resp;
}
int main(){
    int n,v,e;
    char *a;
    int a1_i,a2_i;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> v;
        cin >> e;
        Grafo g(v);
        a=new char[v];
        for (int i=0;i<v;i++){
            a[i]=97+i;
        }
        for(int i=0;i<e;i++){
            char a1,a2;
            cin >> a1;
            cin >> a2;
            a1_i=decode(a1);
            a2_i=decode(a2);
            g.grafo[a1_i][a2_i]=1;
            g.grafo[a2_i][a1_i]=1;
        }
        int count=0;
        cout<<"Case #"<<i<<":\n";
        for(int i=0;i<v;i++){
            if (g.visited[i]==false){ 
                g.bfs(i);
                for(int j=0;j<v;j++){
                        if(g.colors[j]=="Black"){
                            cout<<a[j]<<",";
                            g.visited[j]=true;
                        }
                }
                count++;
                cout<<"\n";
            }
        }
        cout<<count<<" connected components"<<"\n\n";
        
    }  
    return 0;
}