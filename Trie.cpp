#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* childNode[26];
    bool isTerminalNode;
    
    TrieNode(char ch){
        data = ch;

        for(int i=0; i<26; i++){
            childNode[i] = NULL;
        }

        isTerminalNode = false;
    }

};

void insertUtil(TrieNode* root, string str){
    // base case
    if(str.length()==0){
        root->isTerminalNode = true;
        return;
    }

    // Assumption is all character is small
    int index = str[0] - 'a';
    TrieNode* child;

    // character is present
    if(root->childNode[index]!=NULL){
        child = root->childNode[index];
    }
    else{
        // character is absent
        child = new TrieNode(str[0]);
        root->childNode[index] = child;
    }

    // RECURSION
    insertUtil(child, str.substr(1));
}
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string str){
        insertUtil(root, str);
    }

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.length()==0){
            return root->isTerminalNode;
        }

        TrieNode* child;
        int index = word[0]-'a';

        // character is present
        if(root->childNode[index]!=NULL){
            child = root->childNode[index];
        }
        else{
            // character is absent
            return false;
        }

        // RECURSION
        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }
};

int main(){
    
    Trie*t = new Trie();

    t->insert("eat");

    cout<<"word is present or not "<<t->search("eat")<<endl;
    return 0;
}