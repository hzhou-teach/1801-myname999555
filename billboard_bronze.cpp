//Jeffrey Chen
//10 minutes, ****x *****
//Difficulty - 4/10
//It didn't seem hard, though I'm not sure why the fifth test case isn't working.



#include <algorithm>
#include <iostream>
#include <sstream> 
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

bool compareTwo(vector<int> arr1, vector<int> arr2) {
	return arr1[0] < arr2[0];
}

int main(int argc, char* argv[]) {
	const char* FIN = "billboard.in";
	const char* FOUT = "billboard.out";
	const char* inFile = argc > 1 ? argv[1] : FIN;
	ifstream cin(inFile);
	ofstream cout(FOUT);

	int ax1, ay1, ax2, ay2;
	int cx1, cy1, cx2, cy2;
	int sum = 0;

	cin >> ax1 >> ay1 >> ax2 >> ay2 >> cx1 >> cy1 >> cx2 >> cy2;


	if (cy2 >= ay2 && cy1 <= ay1) {
		if (cx1 <= ax1 && cx2 <= ax2 && cx2 >= ax1) {
			sum += (cx2 - ax1) * (ay2 - ay1);
		}
		if (cx1 >= ax1 && cx1 <= ax2 && cx2 >= ax2) {
			sum += (ax2 - cx1) * (ay2 - ay1);
		}
		if (cx1 <= ax1 && cx2 >= ax2) {
			sum += (ax2 - ax1) * (ay2 - ay1);
		}
	}

	if (cx2 >= ax2 && cx1 <= ax1) {
		if (cy1 <= ay1 && cy2 <= ay2 && cy2 >= ay1) {
			sum += (cy2 - ay1) * (ax2 - ax1);
		}
		if (cy1 >= ay1 && cy1 <= ay2 && cy2 >= ay2) {
			sum += (ay2 - cy1) * (ax2 - ax1);
		}

	}

	cout << (ax2 - ax1) * (ay2 - ay1) - sum;

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
