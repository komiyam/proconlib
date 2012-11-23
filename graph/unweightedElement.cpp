class Edge {
public:
	int to;

	Edge(){}
	Edge(int to):
		to(to)
	{}
};

// BEGIN CUT HERE
bool operator< (const Edge& lhs, const Edge& rhs) {
	return lhs.to < rhs.to;
}
// END CUT HERE
// BEGIN CUT HERE
ostream& operator<< (ostream& os, const Edge& x) {
	return os << "Edge(" << x.to << ", " <<  ")";
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

	void addUndirectedEdge(int from, int to) {
		DEBUGASSERT(0<=from && from < numV && 0 <= to && to < numV, from, to);
		operator [](from).push_back(Edge(to));
		operator [](to).push_back(Edge(from));
	}

	void addDirectedEdge(int from, int to) {
		DEBUGASSERT(0<=from && from < numV && 0 <= to && to < numV, from, to);
		operator [](from).push_back(Edge(to));
	}
};
