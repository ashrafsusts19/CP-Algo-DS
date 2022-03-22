#include <bits/stdc++.h>
 


struct Node {
    bool isWord;
    long long int counter;
    Node* next[26];
    Node() {
        isWord = false;
        counter = 0;
        for (int i = 0; i < 26; i++){
            next[i] = NULL;
        }
    }
};

Node* root = new Node();



bool findPrefix(std::string s){
    Node* curr = root;
    for (int i = 0; i < s.size(); i++){
        if (curr->next[s[i] - 'a'] == NULL) return false;
        curr = curr->next[s[i] - 'a'];
    }
    return true;
}

bool findWord(std::string s){
    Node* curr = root;
    for (int i = 0; i < s.size(); i++){
        if (curr->next[s[i] - 'a'] == NULL) return false;
        curr = curr->next[s[i] - 'a'];
    }
    return curr->isWord;
}

void insert(std::string s){
    if (findWord(s)) return;
    Node* curr = root;
    curr->counter++;
    for (int i = 0; i < s.size(); i++){
        if (curr->next[s[i] - 'a'] == NULL) curr->next[s[i] - 'a'] = new Node();
        curr = curr->next[s[i] -'a'];
        curr->counter++;
    }
    curr->isWord = true;
}

long long int totalWords(){
    return root->counter;
}

long long int totalSubwords(std::string s){
    Node* curr = root;
    for (int i = 0; i < s.size(); i++){
        if (curr->next[s[i] - 'a'] == NULL) return 0;
        curr = curr->next[s[i] - 'a'];
    }
    return curr->counter;
}

int main()
{
    insert("super");
    insert("meat");
    insert("boy");
    insert("ibrahim");
    insert("suppadupah");
    insert("supppppppp");
    std::cout << findWord("super") <<"\n";
    std::cout << findWord("sup") <<"\n";
    std::cout << findPrefix("sup") <<"\n";
    std::cout << findWord("mom") <<"\n";
    std::cout << totalSubwords("") << "\n";
    std::cout << totalWords() << "\n";
}
