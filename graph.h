#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

using namespace std;



class Vertex {
    friend class Graph;

    char ptitle;
    vector<Vertex*> neighbourVertex;

public:
    Vertex(char);
    void addNeighbourVertex(Vertex*);

    char getTitle() const;
    vector<Vertex*> getNeighbourVertex() const;
};



class Graph {
    vector<Vertex*> vertices;

public:
    Graph() = default;
    void setVertices(const vector<char>&, const vector<vector<int>>&);

    int size() const;
    bool empty() const;

    vector<Vertex*> getVertices() const;
};

#endif // GRAPH_H
