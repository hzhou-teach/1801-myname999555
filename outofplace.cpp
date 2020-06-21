// All ten work
// 10 minutes
// Difficulty: 3/10
// The problem wasn't too hard,	I originally tried to use casework but I found out the easier way instead.
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char* argv[]) {
	const char* FIN = "outofplace.in";
	const char* FOUT = "outofplace.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int n;
	cin >> n;
	vector<int> heights;
	vector<int> sortedHeights;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		heights.push_back(x);
		sortedHeights.push_back(x);
	}

	sort(sortedHeights.begin(), sortedHeights.end());
	int swaps = 0;
	for (int i = 0; i < n; ++i) {
		if (heights[i] != sortedHeights[i]) {
			++swaps;
		}
	}
	
	cout << swaps-1 << endl;

	return 0;
}