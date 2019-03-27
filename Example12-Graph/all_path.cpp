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

template<class ElemType, class Functor>
void TraversalByDFS(const Graph<ElemType> &g, Functor f) {
  stack<queue<ElemType> > s;
  vector<ElemType> path;
  set<ElemType> explored;

  typename Graph<ElemType>::VertexList vtx = g.Vertices();
  s.push(queue<ElemType>(typename queue<ElemType>::container_type(vtx.begin(), vtx.end())));
  while (!s.empty()) {
    queue<ElemType> &t = s.top();
    if (t.empty()) {
      s.pop();
      explored.erase(path.back());
      if (!path.empty()) { path.pop_back(); } 
      continue;
    }
    path.push_back(t.front());
    explored.insert(t.front());
    const typename Graph<ElemType>::NeighborList &neighbors = g.Neighbors(t.front());
    t.pop();
    // 對某條路經呼叫函式 
    f(path);
    
    queue<ElemType> n;
    for (typename Graph<ElemType>::NeighborList::const_iterator p = neighbors.begin();
         p != neighbors.end(); ++p) { 
      if (explored.find(*p) == explored.end()) {
        n.push(*p);
      } 
    }
    if (n.empty()) {
      explored.erase(path.back());
      path.pop_back();
    } else {
      s.push(n);
    }
  }
}

ostream &operator<<(ostream &lhs, const vector<int> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}


template<class ElemType>
struct Print {
  inline void operator()(const vector<ElemType> &path) {
    cout << path << endl;
  }
};

int main() {
  Graph<int> g;
  g.AddEdge(1, 2);
  g.AddEdge(1, 3);
  g.AddEdge(1, 4);
  g.AddEdge(2, 3);
  g.AddEdge(2, 4);
  g.AddEdge(3, 4);

  TraversalByDFS(g, Print<int>());
  cout << endl;

  system("pause");
  return 0;
}
