// Autor : Odair
// Data: 17 AGO 2024
//  Objetivo: o robô usa o grafo para navegar eficientemente de sua posição inicial até a posição de destino, 
//            encontrando o caminho mais curto possível com base no critério definido (por exemplo, a distância).


#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm> // Inclui a função reverse
#include <cmath>

using namespace std;

int heuristica(char atual, char destino) {
    return abs(atual - destino); 
}

class Grafo_A {
private:
    unordered_map<char, vector<pair<char, int>>> adj;

public:
    void adicionarAresta(char u, char v, int peso) {
        adj[u].emplace_back(v, peso);
        adj[v].emplace_back(u, peso); // Grafo não-direcionado
    }

    pair<vector<char>, int> a_star(char inicio, char destino) {
        unordered_map<char, int> g_score;
        unordered_map<char, int> f_score;
        unordered_map<char, char> anterior;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;

        for (auto& [nodo, _] : adj) {
            g_score[nodo] = numeric_limits<int>::max();
            f_score[nodo] = numeric_limits<int>::max();
        }
        g_score[inicio] = 0;
        f_score[inicio] = heuristica(inicio, destino);
        pq.emplace(f_score[inicio], inicio);

        while (!pq.empty()) {
            char u = pq.top().second;
            pq.pop();

            if (u == destino) break;

            for (auto& [v, peso] : adj[u]) {
                int tentativa_g_score = g_score[u] + peso;

                if (tentativa_g_score < g_score[v]) {
                    anterior[v] = u;
                    g_score[v] = tentativa_g_score;
                    f_score[v] = g_score[v] + heuristica(v, destino);
                    pq.emplace(f_score[v], v);
                }
            }
        }

        vector<char> caminho;
        int custoTotal = 0;
        for (char v = destino; v != inicio; v = anterior[v]) {
            caminho.push_back(v);
            custoTotal += adj[v][0].second; // Soma o peso da aresta correspondente
        }
        caminho.push_back(inicio);
        reverse(caminho.begin(), caminho.end());

        custoTotal = g_score[destino]; // Define o custo total como o g_score do destino

        return {caminho, custoTotal};
    }
};

int main() {
    Grafo_A g;
    g.adicionarAresta('A', 'B', 7);
    g.adicionarAresta('A', 'C', 3);
    g.adicionarAresta('B', 'C', 4);
    g.adicionarAresta('B', 'D', 12);
    g.adicionarAresta('C', 'D', 5);
    g.adicionarAresta('C', 'E', 9);
    g.adicionarAresta('D', 'E', 6);

    char inicio = 'A';
    char destino = 'E';
    auto [caminho, custoTotal] = g.a_star(inicio, destino);

    cout << "Caminho A* de " << inicio << " até " << destino << ": ";
    for (char nodo : caminho) {
        cout << nodo << " ";
    }
    cout << "\nCusto total do caminho: " << custoTotal << endl;

    return 0;
}
