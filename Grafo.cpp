// Autor : Odair
// Data: 17 AGO 2024
//  Objetivo: o robô usa o grafo para navegar eficientemente de sua posição inicial até a posição de destino, 
//            encontrando o caminho mais curto possível com base no critério definido (por exemplo, a distância).

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // Valor infinito
/*
O grafo é representado como um mapa de listas de adjacência, onde cada nó mapeia para uma lista de pares (nó vizinho, peso da aresta).
*/ 
// Classe para representar o grafo
class Grafo {
private:
    unordered_map<char, vector<pair<char, int>>> adj;

public:
    void adicionarAresta(char u, char v, int peso) {
        adj[u].emplace_back(v, peso);
        adj[v].emplace_back(u, peso); // Se o grafo for não-direcionado
    }


// Algoritmo de Dijkstra: A prioridade é dada aos nós com a menor distância conhecida, 
// usando uma fila de prioridade (min-heap). O algoritmo percorre o grafo até encontrar o caminho mais curto para o nó de destino
//
    vector<char> dijkstra(char inicio, char destino) {
        unordered_map<char, int> dist;
        unordered_map<char, char> anterior;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;

        for (auto& [nodo, _] : adj) {
            dist[nodo] = INF;
        }

        dist[inicio] = 0;
        pq.emplace(0, inicio);

        while (!pq.empty()) {
            char u = pq.top().second;
            pq.pop();

            if (u == destino) break;

            for (auto& [v, peso] : adj[u]) {
                int novaDist = dist[u] + peso;

                if (novaDist < dist[v]) {
                    dist[v] = novaDist;
                    anterior[v] = u;
                    pq.emplace(novaDist, v);
                }
            }
        }

        vector<char> caminho;
        for (char v = destino; v != inicio; v = anterior[v]) {
            caminho.push_back(v);
        }
        caminho.push_back(inicio);
        reverse(caminho.begin(), caminho.end());

        return caminho;
    }
};

int main() {
    Grafo g;
    g.adicionarAresta('A', 'B', 4);
    g.adicionarAresta('A', 'C', 2);
    g.adicionarAresta('B', 'C', 5);
    g.adicionarAresta('B', 'D', 10);
    g.adicionarAresta('C', 'D', 3);
    g.adicionarAresta('C', 'E', 8);
    g.adicionarAresta('D', 'E', 7);

    char inicio = 'A';
    char destino = 'E';
    vector<char> caminho = g.dijkstra(inicio, destino);
// Resultado: O caminho mais curto do nó de início ao nó de destino é impresso, com os nós visitados na ordem correta. 
    cout << "Caminho mais curto de " << inicio << " até " << destino << ": ";
    for (char nodo : caminho) {
        cout << nodo << " ";
    }
    cout << endl;

    return 0;
}
