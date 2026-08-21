class alignas(64) TrieNode{
public:
    uint16_t arr[26];
    bool wordEnd{false};
    uint32_t mask{0};
};

class WordDictionary {
	inline static vector<TrieNode> trie{};
public:
    WordDictionary() {
        static bool init = (trie.reserve(500002), true);
        trie.clear();
        trie.emplace_back();
    }
    
    void addWord(const string &word) {
    	uint32_t level = 0;
    	for(char c : word) {
    		uint32_t idx = c - 'a';
    		if((trie[level].mask & (1 << idx)) == 0){
    			trie[level].arr[idx] = trie.size();
    			trie[level].mask |= (1 << idx);
    			trie.emplace_back();
    		}
    		level = trie[level].arr[idx];
    	}
    	trie[level].wordEnd = true;
    }

    bool search(uint32_t level, string_view word) {
    	if(word.empty())
    		return trie[level].wordEnd;
    	char c = word.front();
    	uint32_t idx = c - 'a';
    	if(c != '.'){
    		if(trie[level].mask & (1 << idx))
    			return search(trie[level].arr[idx], word.substr(1));
    	} else {
    		uint32_t m = trie[level].mask;
    		while(m) {
    			uint32_t idx = std::countr_zero(m);
    			if(search(trie[level].arr[idx], word.substr(1)))
    				return true;
    			m = m & (m - 1);
    		}
    	}
    	return false;
    }
    
    bool search(const string &word) {
    	return search(0, word);
    }
};