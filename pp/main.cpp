using namespace std;

#include <iostream>
#include <vector>
#include <fstream>

void dfs(int u, vector<vector<int>> &graph, vector<int> &visited, int without = 0){
    visited[u] = 1;
    for(int j = 0; j < graph[u].size(); j++){
        int v = graph[u][j];
        if(v != without && !visited[v]){
            dfs(v, graph, visited, without);
        }
    }
}

int get_components_count(vector<vector<int>> &graph, int without = 0){
    vector<int> visited(graph.size());

    int result = 0;

    for(int u = 1; u < graph.size(); u++){
        if(u != without && !visited[u]){
            dfs(u, graph, visited, without);
            result++;
        }
    }

    return result;
}

int main(){
    vector<vector<int>> graph;

    //cout << "Input vertex count: ";
    int vertex_count;
    cin >> vertex_count;
    graph.resize(vertex_count + 1);

    for(int i = 1; i <= vertex_count; i++){
        //cout << "Input number of edges for " << i << ": ";
        int relations;
        cin >> relations;
        //cout << "Input all vertexes that " << i << " relation: ";
        for(int j = 0; j < relations; j++){
            int second;
            cin >> second;
            graph[i].push_back(second);
        }
    }

    int total_components = get_components_count(graph);

    vector<int> answer;
    for(int u = 1; u <= vertex_count; u++){
        if(get_components_count(graph, u) > total_components){
            answer.push_back(u);
        }
    }
    cout << endl;
    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
    cout << endl;
}