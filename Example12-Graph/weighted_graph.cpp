#include <iostream>
#include <limits> 
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
 
using namespace std;

template<class ElemType, class WeightType>
class WeightedDirectedGraph {
 public:
  typedef vector<ElemType> VertexList;
  typedef set<ElemType> NeighborList; 
  typedef map<ElemType, map<ElemType, WeightType> > AdjMap;
  
  int Size() const { return adj_.size(); }

  void AddEdge(const ElemType &i, const ElemType &j, const WeightType &w) {
    // 無向圖 
    adj_[i][j] = w;
  }

  WeightType GetWeight(const ElemType &i, const ElemType &j) const {
    typename map<ElemType, WeightType>::const_iterator p = adj_.find(i)->second.find(j);
    if (p == adj_.find(i)->second.end()) return numeric_limits<WeightType>::max();
    return adj_.find(i)->second.find(j)->second;
  }

  NeighborList Neighbors(const ElemType &i) const {
    set<ElemType> ret;
    if (adj_.find(i) == adj_.end()) return ret;
    const map<ElemType, WeightType> &m = adj_.find(i)->second; 
    for (typename map<ElemType, WeightType>::const_iterator p = m.begin();
         p != m.end(); ++p) {
      ret.insert(p->first);
    }
   return ret;
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

int main() {
  WeightedDirectedGraph<int, int> g;
  g.AddEdge(1, 2, 10);
  g.AddEdge(1, 4, 20);
  g.AddEdge(1, 5, 20);
  g.AddEdge(1, 6, 5);
  g.AddEdge(1, 7, 15);
  g.AddEdge(2, 3, 5);
  g.AddEdge(2, 4, 10);
  g.AddEdge(3, 2, 15);
  g.AddEdge(3, 4, 5);
  g.AddEdge(4, 5, 10);
  g.AddEdge(5, 6, 5);
  g.AddEdge(7, 6, 10);
  g.AddEdge(8, 1, 5);
  g.AddEdge(8, 2, 20);
  g.AddEdge(8, 7, 5);
  g.AddEdge(9, 2, 15);
  g.AddEdge(9, 8, 20);
  g.AddEdge(9, 10, 10);
  g.AddEdge(10, 2, 5);
  g.AddEdge(10, 3, 15);

  // 印出所有的頂點:
  WeightedDirectedGraph<int, int>::VertexList vertices = g.Vertices();
  for (size_t i = 0; i < vertices.size(); ++i) {
    if (i != 0) cout << ' ';
    cout << vertices[i];
  } 
  cout << endl;
  // 印出所有頂點相鄰的鄰居:
  for (WeightedDirectedGraph<int, int>::VertexList::const_iterator v = vertices.begin();
       v != vertices.end(); ++v) {
    cout << "頂點 " << *v << ":";
    WeightedDirectedGraph<int, int>::NeighborList neighbors = g.Neighbors(*v); 
    for (WeightedDirectedGraph<int, int>::NeighborList::const_iterator p = neighbors.begin();
         p != neighbors.end(); ++p) {
      cout << " " << *p << "(" << g.GetWeight(*v, *p) << ") "; 
    }  
    cout << endl;
  }
   

  system("pause");
  return 0;
}
