#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <cassert>

using namespace std;

template<class ElemType, class WeightType>
class WeightedDirectedGraph {
 public:
  typedef ElemType ValueType; 
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


template<class Graph, class Functor>
void TraversalByDFS(const Graph &g, Functor &f) {
  typedef typename Graph::ValueType ElemType;
  stack<queue<ElemType> > s;
  vector<ElemType> path;
  set<ElemType> explored;

  typename Graph::VertexList vtx = g.Vertices();
  s.push(queue<ElemType>(typename queue<ElemType>::container_type(vtx.begin(), vtx.end())));
  while (!s.empty()) {
    queue<ElemType> &t = s.top();
    if (t.empty()) {
      assert(!s.empty()); 
      s.pop();
      explored.erase(path.back());
      if (!path.empty()) { path.pop_back(); } 
      continue;
    }
    path.push_back(t.front());
    explored.insert(t.front());
    const typename Graph::NeighborList &neighbors = g.Neighbors(t.front());
    t.pop();
    // 對某條路經呼叫函式 
    f(path, g);
    
    queue<ElemType> n;
    for (typename Graph::NeighborList::const_iterator p = neighbors.begin();
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


template<class Graph>
class Print {
  public:
    typedef typename Graph::ValueType ElemType; 
    Print(const ElemType &b,
          const ElemType &e) { 
      begin_ = b;
      end_ = e;
   }

    inline void operator()(
        const vector<ElemType> &seq,
        const Graph &g) const {
      if (seq.size() >= 1 && seq.front() == begin_ && seq.back() == end_) {
        cout << seq;
        int total_dist = 0;
        for (size_t i = 1; i < seq.size(); ++i) {
          total_dist += g.GetWeight(seq[i-1], seq[i]);
        }
        cout << " (" << total_dist << ")" << endl;
      } 
    }
  private:
    ElemType begin_;
    ElemType end_;
};


template<class ElemType>
ostream &operator<<(ostream &lhs, const vector<ElemType> &rhs) {
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i != 0) lhs << " ";
    lhs << rhs[i];
  }
  return lhs;
}

template<class Graph>
void PrintAllPaths(
    const Graph &g,
    const typename Graph::ValueType &b, 
    const typename Graph::ValueType &e) {
  Print<Graph> f(b, e);
  TraversalByDFS(g, f);
}

template<class Graph>
class GetShortest {
 public:
  typedef typename Graph::ValueType ElemType;
  GetShortest(const ElemType &b, const ElemType &e) {
    begin_ = b; end_ = e;
    best_dist_ = numeric_limits<int>::max();
  }

  inline void operator() (const vector<ElemType> &seq, const Graph &g) {
    if (seq.size() < 1) return;
    if (seq.front() == begin_ && seq.back() == end_) {
      int total_dist = 0; 
      for (size_t i = 1; i < seq.size(); ++i) {
        total_dist += g.GetWeight(seq[i-1], seq[i]);
      }
      if (best_dist_ > total_dist) {
        best_dist_ = total_dist;
        best_seq_ = seq;
      }
    }  
  }

  void Print() const {
    for (size_t i = 0; i < best_seq_.size(); ++i) {
      if (i > 0) cout << " ";
      cout << best_seq_[i];
    }
    cout << endl;
  }

 private:
  ElemType begin_;
  ElemType end_;
  int best_dist_;
  vector<ElemType> best_seq_;
};

template<class ElemType, class Graph>
void PrintShortestPath(
    const Graph &g,
    const ElemType &b, const ElemType &e) {
  GetShortest<Graph> f(b, e);
  TraversalByDFS(g, f);
  f.Print();
}


int main() {
  WeightedDirectedGraph<string, int> g;
  g.AddEdge("基隆", "台北", 35);
  g.AddEdge("台北", "龍潭", 45);
  g.AddEdge("龍潭", "新竹", 25);
  g.AddEdge("台北", "桃園", 30);
  g.AddEdge("桃園", "新竹", 45);
  g.AddEdge("新竹", "台中", 100);
  g.AddEdge("桃園", "台中", 130);

  cout << "[Case 1]" << endl;
  PrintAllPaths(g, "基隆", "台中");
  cout << endl;


  cout << "[Case 2]" << endl;
  PrintShortestPath(g, "基隆", "台中");
  cout << endl;  

  system("pause");
  return 0;
}
