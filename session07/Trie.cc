class Trie {
private:
	class Node {
	public:
		Node* next[26];
		bool isWord[26];  //216 bytes minimum!
		
	};

	Node* root;

public:
	void add(const char s[]) {
		char c = s[0];
		Node* p = root.next[c];


		
	}

	bool isWord(const char s[]) {  return true/false; }

	// return true if the dictionary contains any words that start with these letters
	bool startsWith(const char s[]) {  return true/false; }
};
