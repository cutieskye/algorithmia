#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

vector<int> partition3(vector<int>& a, int l, int r) {
	int x = a[l];
	int j = l;
	int k = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] < x) {
			j++;
			k++;
			swap(a[i], a[j]);
			if (j != k) {
				swap(a[i], a[k]);
			}
		}
		else if (a[i] == x) {
			k++;
			swap(a[i], a[k]);
		}
	}
	swap(a[l], a[j]);
	return vector<int>{j, k};
}

int partition2(vector<int>& a, int l, int r) {
	int x = a[l];
	int j = l;
	for (int i = l + 1; i <= r; i++) {
		if (a[i] <= x) {
			j++;
			swap(a[i], a[j]);
		}
	}
	swap(a[l], a[j]);
	return j;
}

void randomized_quick_sort(vector<int>& a, int l, int r) {
	if (l >= r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	vector<int> m = partition3(a, l, r);

	randomized_quick_sort(a, l, m[0] - 1);
	randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
}