#pragma once

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

namespace graphs {

	class graph {
	public:
		bool add_node(int n);
		bool del_node(int n);
		bool add_edge(int n1, int n2);
		bool del_edge(int n1, int n2);
		vector<int> nodes();
		vector<pair<int, int>> out_edges(int n);
		int nodes_count() const;
		int edges_count() const;

		friend ostream& operator<<(ostream& out, const graph& g);
		friend istream& operator>>(istream& in, graph& g);

		static graph transpose(const graph& g);
		static vector<int> shortest_path(graph& g, int n1, int n2);
		static vector<int> depth_first_search(graph& g, int n);

	private:
		unordered_map<int, unordered_set<int>> edges;
		int ecount = 0;
		static void DFS_rec(graph& g, int v, unordered_map<int, bool>& discovered, vector<int>& search);
	};

}
