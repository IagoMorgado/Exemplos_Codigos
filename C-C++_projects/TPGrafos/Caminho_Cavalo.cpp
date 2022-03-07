#include <iostream>
#include <cstring>
#include<queue>
using namespace std;

int findPosition(string pos);
class Grafo{
    public:
        int grafo[8][8];
        int matrizAdj[64][64];
        string colors[64];
        Grafo(){
            for(int x=0;x<8;x++){
                for(int y=0;y<8;y++){
                    this->grafo[x][y]=1;
                }
            }
            for(int x=0;x<64;x++){
                for(int y=0;y<64;y++){
                    this->matrizAdj[x][y]=0;
                }
            }
        }   
    void buildMatriz(){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(i+1<8 && i+1>=0 && j+2<8 && j+2>=0&&this->grafo[i+1][j+2]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i+1)+(j+2)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
                if(i+1<8 && i+1>=0 && j-2<8 && j-2>=0&&this->grafo[i+1][j-2]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i+1)+(j-2)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
                if(i-1<8 && i-1>=0 && j+2<8 && j+2>=0&&this->grafo[i-1][j+2]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i-1)+(j+2)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
                if(i-1<8 && i-1>=0 && j-2<8 && j-2>=0&&this->grafo[i-1][j-2]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i-1)+(j-2)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1; 
                }
                if(i+2<8 && i+2>=0 && j+1<8 && j+1>=0&&this->grafo[i+2][j+1]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i+2)+(j+1)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
                if(i+2<8 && i+2>=0 && j-1<8 && j-1>=0&&this->grafo[i+2][j-1]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i+2)+(j-1)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
                if(i-2<8 && i-2>=0 && j+1<8 && j+1>=0&&this->grafo[i-2][j+1]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i-2)+(j+1)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
                if(i-2<8 && i-2>=0 && j-1<8 && j-1>=0&&this->grafo[i-2][j-1]==1){
                    int vertex1=i+j*8;
                    int vertex2=(i-2)+(j-1)*8;
                    this->matrizAdj[vertex1][vertex2]=1;
                    this->matrizAdj[vertex2][vertex1]=1;
                }
            }
        }
    }
    int bfs(int i,int j,int i2,int j2){
        int vertex_ini=i+j*8;
        int vertex_end=i2+j2*8;
        int dist=0;
        for(int i=0;i<64;i++){
            this->colors[i]="WHITE";
        }
        queue<int> Q;
        int * distances = new int[64];
        memset(distances,0,sizeof(int)*64);
        Q.push(vertex_ini);
        while(!Q.empty()){
            int u=Q.front();
            Q.pop();
            for(int v=0;v<64;v++){
                if(this->matrizAdj[u][v]==1&&this->colors[v]=="WHITE"){
                    distances[v]=distances[u]+1;
                    this->colors[v]="GRAY";
                    Q.push(v);
                }
            }
            colors[u]="Black";
        }
        return distances[vertex_end];
    }
};
int main(){
    int i,j,i2,j2,resp;
    string first_in,second_in;
    for (int count = 0; count < 8; count++){
        cin >> first_in;
        cin >> second_in;  
        i2=findPosition(second_in);
        j2=second_in[1]-'0'-1;
        i=findPosition(first_in);
        j=first_in[1]-'0'-1;
        Grafo a;
        a.buildMatriz();
        resp=a.bfs(i,j,i2,j2);
        cout << "To get from " << first_in << " to " << second_in << " takes " << resp <<" knight moves." <<"\n";
    }
    return 0;
}
int findPosition(string pos){
    int aux;
    if(pos[0]=='a'){
        aux=0;
    }else 
    if(pos[0]=='b'){
        aux=1;
    }else if(pos[0]=='c'){
        aux=2;
    }else if(pos[0]=='d'){
        aux=3;
    }else if(pos[0]=='e'){
        aux=4;
    }else if(pos[0]=='f'){
        aux=5;
    }else if(pos[0]=='g'){
        aux=6;
    }else if(pos[0]=='h'){
        aux=7;
    }
    return aux;
}