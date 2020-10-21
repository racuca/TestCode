#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
int main() {
	unordered_map<string, int> scores;
	scores["Nana"] = 60;
	scores["Mocha"] = 70;
	scores["Coco"] = 100;
	for (auto it = scores.begin(); it != scores.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
}