class Solution {
public:
	int compareVersion(string version1, string version2) {
		vector<int>Q1, Q2;
		stringstream check1(version1), check2(version2);
		string str;
		while (getline(check1, str, '.'))Q1.push_back(stoi(str));
		while (getline(check2, str, '.'))Q2.push_back(stoi(str));

		Q1.size() > Q2.size() ? Q2.resize(Q1.size()) : Q1.resize(Q2.size());

		for (int index = 0; index < Q1.size(); index++) {
			if (Q1[index] < Q2[index])return -1;
			else if (Q1[index] > Q2[index])return 1;
		}
		return 0;
	}
};