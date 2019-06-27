#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

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
    vector<ElemType> ret;
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

  // 印出所有的頂點:
  Graph<int>::VertexList vertices = g.Vertices();
  for (size_t i = 0; i < vertices.size(); ++i) {
    if (i != 0) cout << ' ';
    cout << vertices[i];
  }

  cout << endl;
  // 印出所有頂點相鄰的鄰居:

  for (Graph<int>::VertexList::const_iterator v = vertices.begin();
       v != vertices.end(); ++v) {
    cout << "頂點 " << *v << ":";

    Graph<int>::NeighborList neighbors = g.Neighbors(*v);
    for (Graph<int>::NeighborList::const_iterator p = neighbors.begin();
         p != neighbors.end(); ++p) {
      cout << " " << *p; 
    }

    cout << endl;
  }

  system("pause");
  return 0;
}
