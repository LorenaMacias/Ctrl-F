#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class ctrlf {
public:
	vector<string> theFile;
	vector<string> answer;
	string yeet;

	void openFile() {
		fstream	file("test.txt");

		if (file.is_open())
		{
			
			while (!file.eof())
			{
				getline(file, yeet);
				theFile.push_back(yeet);
			}
			file.close();
		}
		else
		{
			cout << "Could not open file test.txt" << endl;
		}
	}
	
	void check(string word) {
		size_t found;
		string temp;
		word = tolower(word);

		for (int i = 0; i < theFile.size(); i++)
		{
			temp = tolower(theFile[i]);
			found = temp.find(word);
			if (found != string::npos)
				answer.push_back(theFile[i]);
		}
	}

	string tolower(string n) {
		std::transform(n.begin(), n.end(), n.begin(), ::tolower);
		return n;
	}

	void display() {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << endl;
		}
	}
};

int main() {
	string word;
	cin >> word;
	ctrlf eh;
	eh.openFile();
	eh.check(word);
	eh.display();
	return 0;
}
