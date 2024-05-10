//Из файла считывается текст на русском языке со знаками препинания.Построить
//кодирование этого текста методом Хаффмана на основании частоты встречаемости
//символов в тексте.Построить кодирование равномерным двоичным кодом,
//оценить выигрыш.

//#include <iostream>
//#include <string>
//#include <queue>
//#include <unordered_map>
//using namespace std;
//
//// A Tree node
//struct Node
//{
//	char ch;
//	int freq;
//	Node* left, * right;
//};
//
//// Function to allocate a new tree node
//Node* getNode(char ch, int freq, Node* left, Node* right)
//{
//	Node* node = new Node();
//
//	node->ch = ch;
//	node->freq = freq;
//	node->left = left;
//	node->right = right;
//
//	return node;
//}
//
//// Comparison object to be used to order the heap
//struct comp
//{
//	bool operator()(Node* l, Node* r)
//	{
//		// highest priority item has lowest frequency
//		return l->freq > r->freq;
//	}
//};
//
//// traverse the Huffman Tree and store Huffman Codes
//// in a map.
//void encode(Node* root, string str,
//	unordered_map<char, string>& huffmanCode)
//{
//	if (root == nullptr)
//		return;
//
//	// found a leaf node
//	if (!root->left && !root->right) {
//		huffmanCode[root->ch] = str;
//	}
//
//	encode(root->left, str + "0", huffmanCode);
//	encode(root->right, str + "1", huffmanCode);
//}
//
//// traverse the Huffman Tree and decode the encoded string
//void decode(Node* root, int& index, string str)
//{
//	if (root == nullptr) {
//		return;
//	}
//
//	// found a leaf node
//	if (!root->left && !root->right)
//	{
//		cout << root->ch;
//		return;
//	}
//
//	index++;
//
//	if (str[index] == '0')
//		decode(root->left, index, str);
//	else
//		decode(root->right, index, str);
//}
//
//// Builds Huffman Tree and decode given input text
//void buildHuffmanTree(string text)
//{
//	// count frequency of appearance of each character
//	// and store it in a map
//	unordered_map<char, int> freq;
//	for (char ch : text) {
//		freq[ch]++;
//	}
//
//	// Create a priority queue to store live nodes of
//	// Huffman tree;
//	priority_queue<Node*, vector<Node*>, comp> pq;
//
//	// Create a leaf node for each character and add it
//	// to the priority queue.
//	for (auto pair : freq) {
//		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
//	}
//
//	// do till there is more than one node in the queue
//	while (pq.size() != 1)
//	{
//		// Remove the two nodes of highest priority
//		// (lowest frequency) from the queue
//		Node* left = pq.top(); pq.pop();
//		Node* right = pq.top();	pq.pop();
//
//		// Create a new internal node with these two nodes
//		// as children and with frequency equal to the sum
//		// of the two nodes' frequencies. Add the new node
//		// to the priority queue.
//		int sum = left->freq + right->freq;
//		pq.push(getNode('\0', sum, left, right));
//	}
//
//	// root stores pointer to root of Huffman Tree
//	Node* root = pq.top();
//
//	// traverse the Huffman Tree and store Huffman Codes
//	// in a map. Also prints them
//	unordered_map<char, string> huffmanCode;
//	encode(root, "", huffmanCode);
//
//	cout << "Huffman Codes are :\n" << '\n';
//	for (auto pair : huffmanCode) {
//		cout << pair.first << " " << pair.second << '\n';
//	}
//
//	cout << "\nOriginal string was :\n" << text << '\n';
//
//	// print encoded string
//	string str = "";
//	for (char ch : text) {
//		str += huffmanCode[ch];
//	}
//
//	cout << "\nEncoded string is :\n" << str << '\n';
//
//	// traverse the Huffman Tree again and this time
//	// decode the encoded string
//	int index = -1;
//	cout << "\nDecoded string is: \n";
//	while (index < (int)str.size() - 2) {
//		decode(root, index, str);
//	}
//}
//
//// Huffman coding algorithm
//int main()
//{
//	string text = "Huffman coding is a data compression algorithm.";
//
//	buildHuffmanTree(text);
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <fstream>
//#include <map>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//struct tree {
//	int freq;
//	char sym;
//	tree* left;
//	tree* right;
//
//	tree() {
//		freq = 0;
//		sym = ' ';
//		left = NULL;
//		right = NULL;
//	}
//
//	tree(char sym_, int freq_) {
//		sym = sym_;
//		freq = freq_;
//		left = NULL;
//		right = NULL;
//	}
//};
//
//void add_tree(tree* t, char sym_, int freq_) {
//	if (freq_ > t->freq) {
//		if (t->right == NULL) {
//			tree* q = new tree(sym_, freq_);
//			t->right = q;
//		}
//		else {
//			add_tree(t->right, sym_, freq_);
//		}
//	}
//	else {
//		if (t->left == NULL) {
//			tree* q = new tree(sym_, freq_);
//			t->left = q;
//		}
//		else {
//			add_tree(t->left, sym_, freq_);
//		}
//	}
//}
//
//void print_tree(tree* t) {
//	if (t != NULL) {
//		print_tree(t->left);
//		cout << t->sym << " " << t->freq << endl;
//		print_tree(t->right);
//	}
//}
//


//void main() {
	//ifstream fileIn("E://a.txt");
	//string str;
	//vector<symbol> symbols;

	//while (getline(fileIn, str)) {
	//	if (str != "") {

	//		for (string::const_iterator it = str.begin() + 1; it != str.end(); it++) {
	//			if (*it != ' ') {
	//				vector<symbol>::size_type iter = find(symbols, *it);
	//				if (iter != -1) {
	//					symbols[iter].freq++;
	//				}
	//				else {
	//					symbol s(*it, 1);
	//					symbols.push_back(s);
	//				}
	//			}
	//		}
	//	}
	//}
	//std::sort(symbols.begin(), symbols.end(), cmp);

	//

//	for (vector<symbol>::const_iterator it = symbols.begin(); it != symbols.end(); it++) {
//		cout << (*it).sym << " " << (*it).freq << endl;
//	}
//
//	fileIn.close();
//}

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
using namespace std;

// Maximum Height of Huffman Tree.
#define MAX_SIZE 100

struct symbol {
    char sym;
    int freq;

    symbol() {
        sym = ' ';
        freq = 0;
    }
    symbol(char sym_, int freq_) {
        sym = sym_;
        freq = freq_;
    }
};

vector<symbol>::size_type find(vector<symbol>& vec, char sym) {
    vector<symbol>::size_type it;
    for (it = 0; it != vec.size(); it++) {
        if (vec[it].sym == sym)
            return it;
    }
    it = -1;
    return it;
}

auto cmp(symbol& a, symbol& b) {
    return a.freq != b.freq ? a.freq < b.freq : a.sym > b.sym;
}

struct code {
    char sym;
    string cd;

    code() {
        sym = 0;
        cd = "";
    }
    code(char sym_, string cd_) {
        sym = sym_;
        cd = cd_;
    }
};


class HuffmanTreeNode {
public:
    char data;
    int freq;
    HuffmanTreeNode* left;
    HuffmanTreeNode* right;

    HuffmanTreeNode(char character, int frequency)
    {
        data = character;
        freq = frequency;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b)
    {
        return a->freq > b->freq;
    }
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq)
{
    while (pq.size() != 1) {

        HuffmanTreeNode* left = pq.top();
        pq.pop();
        HuffmanTreeNode* right = pq.top();
        pq.pop();

        HuffmanTreeNode* node = new HuffmanTreeNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;

        pq.push(node);
    }

    return pq.top();
}

void printCodes(HuffmanTreeNode* root, vector<code>& codes, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, codes, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, codes, arr, top + 1);
    }

    if (!root->left && !root->right) {
        cout << root->data << " ";
        string s;
        for (int i = 0; i < top; i++) {
            cout << arr[i];
            s += std::to_string((arr[i]));
        }
        cout << s << endl;
        code c(root->data, s);
        codes.push_back(c);
        cout << endl;
    }
}

void HuffmanCodes(vector<symbol>& symbols, vector<code>& codes)
{
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    for (vector<symbol>::iterator i = symbols.begin(); i != symbols.end(); i++) {
        HuffmanTreeNode* newNode = new HuffmanTreeNode((*i).sym, (*i).freq);
        pq.push(newNode);
    }

    HuffmanTreeNode* root = generateTree(pq);

    int arr[MAX_SIZE], top = 0;
    printCodes(root, codes, arr, top);
}
string FindCode(vector<code>& codes, char sym) {
    for (vector<code>::const_iterator it = codes.begin(); it != codes.end(); it++) {
        if ((*it).sym == sym) {
            return (*it).cd;
        }
    }
    return "";
}

void main() {
    setlocale(LC_ALL, "rus");
    ifstream fileIn("E://a.txt");
    string str;
    string fullStr;
    vector<symbol> symbols;

    while (getline(fileIn, str)) {
    	if (str != "") {

            for (string::const_iterator it = str.begin() + 1; it != str.end(); it++) {
                fullStr += str;
                vector<symbol>::size_type iter = find(symbols, *it);
                if (iter != -1) {
                    symbols[iter].freq++;
                }
                else {
                    symbol s(*it, 1);
                    symbols.push_back(s);

                }
            }
    	}
    }
    fileIn.close();
    std::sort(symbols.begin(), symbols.end(), cmp);

	/*for (vector<symbol>::const_iterator it = symbols.begin(); it != symbols.end(); it++) {
		cout << (*it).sym << " " << (*it).freq << endl;
	}*/
    vector<code> codes;
    cout << "Коды: " << endl;
    HuffmanCodes(symbols, codes);

    cout << "Закодированная строка: " << endl;
    int I_Huffman = 0;
    for (string::const_iterator it = fullStr.begin(); it != fullStr.end(); it++) {
        if (*it != ' ') {
            string s = FindCode(codes, *it);
            cout << s;
            I_Huffman += s.size();
        }
    }
    cout << endl << endl;

    int I_uniCode = pow(2, symbols.size() - 1);

    int differenceBit = I_uniCode - I_Huffman;

    cout << "Количество информации при кодировании методом Хаффмана: " << I_Huffman << endl;
    cout << "Количество информации при равномерном кодировании: " << I_uniCode << endl;
    cout << "Выигрыш: " << differenceBit << endl;
}