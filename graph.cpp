#include "graph.h"



Vertex::Vertex(char title) {
    ptitle = title;
}



void Vertex::addNeighbourVertex(Vertex* vertex) {
    neighbourVertex.push_back(vertex);
}



char Vertex::getTitle() const {
    return ptitle;
}



vector<Vertex*> Vertex::getNeighbourVertex() const {
    return neighbourVertex;
}



void Graph::setVertices(const vector<char>& titles, const vector<vector<int>>& weights) {
    for(auto &title : titles){
        vertices.push_back(new Vertex(title));
    }
    for(int i = 0; i < vertices.size(); ++i){
        for(int j = 0; j < vertices.size(); ++j){
            if(i != j && weights[i][j] != 0){
               vertices[i]->addNeighbourVertex(vertices[j]);
            }
        }
    }
}



int Graph::size() const {
    return vertices.size();
}



vector<Vertex*> Graph::getVertices() const {
    return vertices;
}



bool Graph::empty() const {
    return vertices.empty();
}
