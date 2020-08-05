class WordDictionary {
	unordered_map<int, vector<string>>m;
public:
	WordDictionary() {}

	void addWord(string word) {
		m[word.size()].push_back(word);
	}

	bool search(string word) {
		for (auto x : m[word.size()])
		{
			bool flag = true;
			for (int i = 0 ; i < word.size() ; i++)
			{
				if (word[i] == '.') continue;
				if (word[i] != x[i]) {flag = false; break;}
			}
			if (flag) return true;
		}
		return false;
	}
};