#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <string>
#include <Windows.h>
using namespace std;

void readGraph(const string& filename, vector<vector<int>>& adjList, int& n, int& m) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Не вдалося відкрити файл!" << endl;
        return;
    }

    infile >> n >> m;
    adjList.assign(n + 1, vector<int>());
    int v, u;
    for (int i = 0; i < m; ++i) {
        infile >> v >> u;
        adjList[v].push_back(u);
    }

    infile.close();
}

bool isIrreflexive(const vector<vector<int>>& adjList) {
    for (int i = 1; i < adjList.size(); ++i) {
        for (int neighbor : adjList[i]) {
            if (neighbor == i) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(const vector<vector<int>>& adjList) {
    for (int i = 1; i < adjList.size(); ++i) {
        for (int neighbor : adjList[i]) {
            for (int neighbor_of_neighbor : adjList[neighbor]) {
                
                if (find(adjList[i].begin(), adjList[i].end(), neighbor_of_neighbor) == adjList[i].end()) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    
    string inputFile = "123.txt";
    vector<vector<int>> adjList;
    int n, m;

    readGraph(inputFile, adjList, n, m);

    if (isIrreflexive(adjList)) {
        cout << "Граф є іррефлексивним." << endl;
    }
    else {
        cout << "Граф не є іррефлексивним." << endl;
    }

    if (isTransitive(adjList)) {
        cout << "Граф є транзитивним." << endl;
    }
    else {
        cout << "Граф не є транзитивним." << endl;
    }

    return 0;
}
