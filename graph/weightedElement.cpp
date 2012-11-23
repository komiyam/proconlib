typedef int cost_t;

class Edge {
public:
	int to;
	cost_t cost;

	Edge(){}
	Edge(int to, cost_t cost):
		to(to), cost(cost)
	{}
};

// BEGIN CUT HERE
bool operator< (const Edge& lhs, const Edge& rhs) {
	if ( lhs.to != rhs.to ) return lhs.to < rhs.to;
	return lhs.cost < rhs.cost;
}
// END CUT HERE
// BEGIN CUT HERE
ostream& operator<< (ostream& os, const Edge& x) {
	return os << "Edge(" << x.to << ", " << x.cost << ", " <<  ")";
}
// END CUT HERE

class Graph : vector< vector<Edge> > {
public:
	int numV;

	Graph(){}

	void init(int numV_) {
		numV = numV_;
		init();
	}

	void init() {
		assign(numV, vector<Edge>());
	}

	void addUndirectedEdge(int from, int to, cost_t cost) {
		DEBUGASSERT(0<=from && from < numV && 0 <= to && to < numV, from, to, cost);
		operator [](from).push_back(Edge(to, cost));
		operator [](to).push_back(Edge(from, cost));
	}

	void addDirectedEdge(int from, int to, cost_t cost) {
		DEBUGASSERT(0<=from && from < numV && 0 <= to && to < numV, from, to, cost);
		operator [](from).push_back(Edge(to, cost));
	}
};
