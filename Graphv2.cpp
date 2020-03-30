#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Graph{
    int V,E;
    int **adj;
    
    public: Graph* adjmatrix(){
        Graph *g = new Graph;
        string line;
        ifstream inp("cpp1.txt");
        // cout << "Enter No. of Vertices(V) : ";
        // cin >> g->V;
        getline(inp,line);
        g->V = stoi(line);
        g->adj = new int* [g->V];
        for(int i=0;i<g->V;i++){
            g->adj[i] = new int[g->V];
            for(int j=0;j<g->V;j++){
                g->adj[i][j] = 0;
            }
        }
        
        
        
        int j=0;
        
        while(j<2){
            getline(inp,line);
            string a[2] = {"",""};
            int k=0;
            for(int i=0;i<line.length();i++){
                if(line[i] != ' '){
                    a[k]+=line[i];
                }else{
                    k++;
                    if(k>1){
                        k--;
                    }

                }
        
            }
        int g1 = stoi(a[0]);
        int g2 = stoi(a[1]);
        g->adj[g1][g2] = 1;
        g->adj[g2][g1] = 1;
        j++;

        }
        
        return g;
    }

    void display(){
        cout << endl << endl;
        cout << "\t";
        
        for(int i=0;i<V;i++){
            cout << i << "\t";
        }
        cout << "\n\n";
        for(int i=0;i<V;i++){
            cout << i << "\t";
            for(int j=0;j<V;j++){
                cout << adj[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph *g;
    g = g->adjmatrix();
    g->display();
}