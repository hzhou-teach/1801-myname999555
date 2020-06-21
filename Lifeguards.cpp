//All ten tests work
//20 minutes
//Difficulty: 2/10
//It was pretty easy, I had some minor typoes but other than that is wasn't hard.


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

bool sortFirst(pair<int, int> p1, pair<int, int>p2) {
	return p1.first <= p2.first;
}

int main(int argc, char* argv[]) {
	const char* FIN = "lifeguards.in";
	const char* FOUT = "lifeguards.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int n;
	cin >> n;
	vector<pair<int, int>> times;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pair<int, int> temp;
		temp.first = x;
		temp.second = y;
		times.push_back(temp);
	}
	sort(times.begin(), times.end(), sortFirst);

	int curMax = 0;


	for (int i = 0; i < n; ++i) {
		int curMaxEnd = 0;
		int curAmount = 0;
		for (int j = 0; j < n; ++j) {
			if (i == j) { continue; }
			else {
				if (times[j].first > curMaxEnd) {
					curMaxEnd = times[j].second;
					curAmount += (times[j].second - times[j].first);
				}
				else {
					if (times[j].second > curMaxEnd) {
						curAmount += (times[j].second - curMaxEnd);
						curMaxEnd = times[j].second;
					}
				}
			}
		}
		if (curAmount >= curMax) {
			curMax = curAmount;
		}
	}

	cout << curMax << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
