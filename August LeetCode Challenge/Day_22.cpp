class StreamChecker {
public:

	struct TrieNode {
		map<char, TrieNode*> children;
		bool endOfWord;
	};

	TrieNode* getNewNode() {
		struct TrieNode* node = new TrieNode;
		node->endOfWord = false;
		return node;
	}

	string toSearch;
	TrieNode* root;
	int maxLen;
	void insert(TrieNode* root, string word) {
		toSearch = "";
		TrieNode* current = root;
		for (int i = 0; i < word.length(); i++) {
			char ch = word.at(i);
			if (current->children.find(ch) == current->children.end()) {
				current->children.insert(make_pair(ch, getNewNode()));
			}
			current = current->children.at(ch);
		}
		current->endOfWord = true;
	}

	bool search(TrieNode* root, string word) {
		TrieNode* curr = root;
		for (int i = 0; i < word.length(); i++) {
			char ch = word.at(i);
			if (curr->children.find(ch) == curr->children.end()) { return false; }
			curr = curr->children.at(ch);
			if (curr->endOfWord) return true;
		}
		return curr->endOfWord;
	}

	StreamChecker(vector<string>& words) {
		root = getNewNode();
		maxLen = INT_MIN;
		for (string word : words) {
			int l = word.length();
			maxLen = max(maxLen, l);
			reverse(word.begin(), word.end());
			insert(root, word);
		}
	}

	bool query(char letter) {
		if (root->children.find(letter) != root->children.end()) {
			toSearch = letter + toSearch;
			if (toSearch.length() > maxLen) {
				toSearch = toSearch.substr(0, maxLen);
			}
			if (search(root, toSearch)) {
				return true;
			}
			return false;
		} else {
			toSearch = letter + toSearch;
			if (toSearch.length() > maxLen) {
				toSearch = toSearch.substr(0, maxLen);
			}
			return false;
		}
		return false;
	}
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */