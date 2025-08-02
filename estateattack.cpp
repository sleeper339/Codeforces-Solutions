#include <iostream>
#include <vector>

struct Vertex {
	int d;
	int max;
	int min;
	std::vector<int> children;
};

void Solve_iter
(
Vertex& current_node,
std::vector<Vertex>& all_nodes, 
std::vector<bool>& visited
) {
	std::vector<int>& ch = current_node.children;
	
	if (ch.size() == 0) {
		current_node.max = current_node.min = current_node.d;
		return;
	}
	
	int smallest, largest;
	
	for (int i = 0; i < ch.size(); i++) {
		int child = ch[i];
		
		if (visited[child])
			continue;
		
		visited[child] = true;
		Solve_iter(all_nodes[child], all_nodes, visited);
		
		if(i == 0) {
			smallest = all_nodes[child].min;
			largest = all_nodes[child].max;
		}
	}
	
	for(int i = 0; i < ch.size(); i++) {
		largest = std::max(all_nodes[ch[i]].max, largest);
		smallest = std::max(all_nodes[ch[i]].min, smallest);
	}
	
	current_node.min = current_node.d - largest;
	current_node.max = current_node.d - smallest;
}

void Solve() {
	int n;
	std::cin >> n;
	
	std::vector<Vertex> nodes(n);
	std::vector<bool> visited(n);
	
	for(int i = 0; i < n; i++) {
		std::cin >> nodes[i].d;
	}
	
	for(int i = 0; i < n-1; i++) {
		int x, y;
		
		std::cin >> x >> y;
		nodes[x].children.push_back(y);
		nodes[y].children.push_back(x);
	}
	
	Solve_iter(nodes[0], nodes, visited);
	
	for(int i = 0; i < nodes.size(); i++) {
		std::cout << nodes[i].max << " ";
	}
	std::cout << std::endl;
}

int main() {
	Solve();
	return 0;
}