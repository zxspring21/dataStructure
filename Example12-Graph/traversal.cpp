#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
 
using namespace std;

template<class ElemType>
class Graph {
 public:
  typedef vector<ElemType> VertexList;
  typedef set<ElemType> NeighborList; 
  typedef map<ElemType, NeighborList> AdjMap;
  
  int Size() const { return adj_.size(); }

  void AddEdge(const ElemType &i, const ElemType &j) {
    // 無向圖 
    adj_[i].insert(j);
    adj_[j].insert(i);
  }

  bool IsAdjacent(const ElemType &i, const ElemType &j) const {
    typename AdjMap::const_iterator p = adj_.find(i);
    if (p == adj_.end()) return false;
    return p->second.find(j) != p->second.end();
  }

  const NeighborList &Neighbors(const ElemType &i) const {
    return adj_.find(i)->second;
  }

  VertexList Vertices() const {
    VertexList ret;
    ret.reserve(Size());
    for (typename AdjMap::const_iterator p = adj_.begin();
         p != adj_.end(); ++p) {
      ret.push_back(p->first);
    }
    return ret;
  } 
 private:
  AdjMap adj_;
};

template<class ElemType>
vector<ElemType> TraversalByDFS(Graph<ElemType> &g, const ElemType &i) {
  stack<ElemType> s;
  vector<ElemType> path;
  set<ElemType> explored;
  s.push(i);
  explored.insert(i);
  while (!s.empty()) {
    const ElemType &t = s.top();
    s.pop();
    path.push_back(t);
    const typename Graph<ElemType>::NeighborList &neighbors = g.Neighbors(t);
    for (typename Graph<ElemType>::NeighborList::const_iterator p = neighbors.begin();
         p != neighbors.end(); ++p) { 
      if (explored.find(*p) == explored.end()) {
        s.push(*p);
        explored.insert(*p);
      } 
    }
  }
  return path;
}


template<class ElemType>
vector<ElemType> TraversalByBFS(Graph<ElemType> &g, const ElemType &i) {
  queue<ElemType> s;
  vector<ElemType> path;
  set<ElemType> explored;
  s.push(i);
  explored.insert(i);
  while (!s.empty()) {
    const ElemType &t = s.front();
    s.pop();
    path.push_back(t);
    const typename Graph<ElemType>::NeighborList &neighbors = g.Neighbors(t);
    for (typename Graph<ElemType>::NeighborList::const_iterator p = neighbors.begin();
         p != neighbors.end(); ++p) { 
      if (explored.find(*p) == explored.end()) {
        s.push(*p);
        explored.insert(*p);
      } 
    }
  }
  return path;
}

ostream &operator<<(ostream &lhs, const vector<int> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

int main() {
  Graph<int> g;
  g.AddEdge(1, 2);
  g.AddEdge(1, 3);
  g.AddEdge(2, 4);
  g.AddEdge(2, 5);
  g.AddEdge(3, 6);
  g.AddEdge(3, 7);
  g.AddEdge(4, 8);
  g.AddEdge(5, 8);
  g.AddEdge(6, 8);
  g.AddEdge(7, 8);

  cout << TraversalByDFS(g, 1) << endl;
  cout << TraversalByDFS(g, 4) << endl;

  cout << TraversalByBFS(g, 1) << endl;
  cout << TraversalByBFS(g, 4) << endl;
  system("pause");
  return 0;
}
