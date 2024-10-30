#include <iostream>
#include <vector>
#include <algorithm>

int64_t Search(size_t n, const std::vector<std::vector<int64_t>>& graph) {
	if (n == 1) {
		return 0;
	}
	std::vector<int> permutation;
	for (int i = 2; i <= n; ++i) {
		permutation.push_back(i);
	}
	int64_t answer = 1e9;
	do {
		std::vector<bool> all_vertex(n + 1, false);
		if (graph[1][permutation[0]] != 0) {
			all_vertex[1] = true;
			int64_t local_sum = graph[1][permutation[0]];
			int i;
			for (i = 1; i < permutation.size(); ++i) {
				if (graph[permutation[i]][permutation[i - 1]] == 0) {
					break;
				} else {
					local_sum += graph[permutation[i]][permutation[i - 1]];
				}
				all_vertex[permutation[i - 1]] = true;
			}
			if (i == permutation.size() && graph[1][permutation[permutation.size() - 1]] != 0) {
				local_sum += graph[1][permutation[permutation.size() - 1]];
				if (local_sum < answer) {
					answer = local_sum;
				}
			}
		}
	} while (std::next_permutation(permutation.begin(), permutation.end()));
	if (answer == 1e9) {
		return -1;
	}
	return answer;
}

int main() {
	size_t N;
	std::cin >> N;
	int is_edge;
	std::vector<std::vector<int64_t>> contact_matrix(N + 1, std::vector<int64_t>(N + 1, 0));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			std::cin >> is_edge;
			contact_matrix[i][j] = is_edge;
		}
	}
	std::cout << Search(N, contact_matrix);
}