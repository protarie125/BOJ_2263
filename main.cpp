#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

void solve(int n, const vi& inod, const vi& pood,
	int ib, int ie, int ob, int oe) {
	const auto& root = pood[oe - 1];

	if (1 == n) {
		cout << root << ' ';
		return;
	}

	auto inIdx = int{ 0 };
	for (auto i = ib; i < ie; ++i) {
		if (inod[i] == root) {
			break;
		}

		++inIdx;
	}

	solve(1, inod, pood,
		ib + inIdx, ib + inIdx + 1, oe - 1, oe);

	if (0 < inIdx) {
		solve(inIdx, inod, pood,
			ib, ib + inIdx, ob, ob + inIdx);
	}

	if (inIdx + 1 < n) {
		solve(n - inIdx - 1, inod, pood,
			ib + inIdx + 1, ie, ob + inIdx, oe - 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	auto inod = vi(n);
	for (auto i = 0; i < n; ++i) {
		cin >> inod[i];
	}

	auto pood = vi(n);
	for (auto i = 0; i < n; ++i) {
		cin >> pood[i];
	}

	solve(n, inod, pood,
		0, n, 0, n);

	return 0;
}