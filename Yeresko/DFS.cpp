#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Vertex {
    int id = 0;
    int depth = 0;
    bool visited = false;
    vector<Vertex*> neighbours;
};

void dfs(Vertex* initial) {
    cout<<"Running DFS algorithm\n";
    stack<Vertex*> pending;
    pending.push(initial);
    do {
        Vertex* current = pending.top();
        pending.pop();
        cout<<"Vertex "<<current->id<<" visited. Distance from root: "<<current->depth<<"\n";
        for(Vertex* next: current->neighbours) {
            if (!next->visited) {
                pending.push(next);
                next->visited = true;
                next->depth = current->depth+1;
            }
        }
    } while (!pending.empty());
}

int main() {
    Vertex v[8];
    for(int i = 1; i < 8; i++) {
        v[i].id = i;
    }
    v[1].neighbours.push_back(&v[2]);
    v[1].neighbours.push_back(&v[3]);
    v[2].neighbours.push_back(&v[3]);
    v[2].neighbours.push_back(&v[4]);
    v[3].neighbours.push_back(&v[4]);
    v[3].neighbours.push_back(&v[6]);
    v[4].neighbours.push_back(&v[7]);
    v[5].neighbours.push_back(&v[3]);
    v[5].neighbours.push_back(&v[6]);
    v[7].neighbours.push_back(&v[5]);
    v[7].neighbours.push_back(&v[6]);
    for(int i = 1; i < 8; i++) {
        v[i].visited = false;
    }
    dfs(&v[1]);
}
