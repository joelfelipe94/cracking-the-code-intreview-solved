#include<vector>
#include<stack>

template <typename T>
struct NodeGraph{
    bool visited;
    std::vector< NodeGraph<T>* > adjacents;
    T data;
    NodeGraph();
    NodeGraph(T data);
};

template <typename T>
NodeGraph<T>::NodeGraph()
:visited(false)
{}

template <typename T>
NodeGraph<T>::NodeGraph(T data)
:data(data)
,visited(false)
{}

template <typename T>
bool isConnected(NodeGraph<T>* source, NodeGraph<T> *dest){
    std::stack< NodeGraph<T>* > toVisit;
    toVisit.push(source);
    while(!toVisit.empty())
    {
        auto &node = toVisit.top();
        if(node == dest)
            return true;
        node->visited = true;
        toVisit.pop();
        for(auto &adjacent : node->adjacents)
        {
            if(!adjacent->visited)
                toVisit.push(adjacent);
        }
    }
    return false;
}