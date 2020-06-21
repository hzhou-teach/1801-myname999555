//All ten tests work
//90 minutes
//Difficulty: 9/10
//It was pretty hard. I had a basic idea at first, but I wasn't really sure how to implement it, but I decided to use an unordered set which worked.

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
		ofstream fout(FOUT);
	
	int n;
	cin >> n;
	vector<pair<int, int>> times;
	unordered_set <int> working;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pair<int, int> temp1;
		pair<int, int> temp2;
		temp1.first = x;
		temp1.second = i;
		temp2.first = y;
		temp2.second = i;
		times.push_back(temp1);
		times.push_back(temp2);
	}
	sort(times.begin(), times.end(), sortFirst);

	int coveredTimes[100000];
	for (int i = 0; i < n; ++i) {
		coveredTimes[i] = 0;
	}
	int totalCovered = 0;
	int lastTime= 0;
	for (int i = 0; i < 2*n; ++i) {
		if (working.size() == 1) {
			coveredTimes[*working.begin()] += (times[i].first - lastTime);
		}
		if (working.size() >= 1) {
			totalCovered += (times[i].first - lastTime);
		}
		if (working.find(times[i].second) == working.end()) {
			working.insert(times[i].second);
		}
		else {
			working.erase(times[i].second);
		}
		lastTime = times[i].first;
	}

	sort(coveredTimes, coveredTimes + n);

	//cout << totalCovered <<" " << coveredTimes[0] <<  endl;
	fout << (totalCovered - coveredTimes[0]) << endl;

	return 0;
}