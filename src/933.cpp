#include<vector>
#include<iostream>
#include <algorithm>
using namespace std;

/*a directed graph with edge weights*/
template <typename weight_type> 
class dgraph_v_of_v {
public:
	std::vector<std::vector<std::pair<int, weight_type>>> INs, OUTs;
	dgraph_v_of_v(int n) {
		INs.resize(n); 
		OUTs.resize(n);
	}
	inline void add_edge(int, int, weight_type); 
	inline void print();
};

template <typename T>
int graph_hash_of_mixed_weighted_binary_operations_insert(std::vector<std::pair<int, T>>& input_vector, int key, T load) {
	int left = 0, right = input_vector.size() - 1;
	while (left <= right) { 
		int mid = left + ((right - left) / 2);
		if (input_vector[mid].first == key) {
			input_vector[mid].second = load;
			return mid;
		}
		else if (input_vector[mid].first > key) {
			right = mid - 1; 
		}
		else {
			left = mid + 1; 
		}
	}
	input_vector.insert(input_vector.begin() + left, { key,load });
	return left;
}

// ____qcodep____

template <typename weight_type>
inline void dgraph_v_of_v<weight_type>::add_edge(int u, int v, weight_type w)
{
    graph_hash_of_mixed_weighted_binary_operations_insert(OUTs[u], v, w);
    graph_hash_of_mixed_weighted_binary_operations_insert(INs[v], u, w);
}

template <typename weight_type>
inline void dgraph_v_of_v<weight_type>::print()
{
    for (int i = 0; i < OUTs.size(); ++i)
    {
        std::cout << "Vertex " << i << ":" << endl;
        std::cout << "INs: ";
        for(auto &edge : INs[i]){
            std::cout << "<" << edge.first << "," << edge.second << ">";
        }

        std::cout << endl << "OUTs: ";
        for (auto &edge : OUTs[i])
        {
            std::cout << "<" << edge.first << "," << edge.second << ">";
        }
        std::cout << endl;
    }
}

int main() {
	dgraph_v_of_v<double> g(3); // initialize a graph with 3 vertices
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		double z;
		cin >> x >> y >> z; // x and y are int values in [0,2], z is a double value
		g.add_edge(x, y, z); 
	}
	g.print();
}