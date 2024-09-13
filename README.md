# Trie Data Structure Implementation in C++

## Overview
This project implements a Trie (Prefix Tree) data structure in C++ using object-oriented programming. The Trie is designed for efficient storage and retrieval of strings, commonly used for dictionary operations like word search, autocomplete, and spell-check.

## Features
- **Insert Operation**: Allows inserting a word into the Trie.
- **Search Operation**: Checks if a word exists in the Trie.

## Code Explanation

### `TrieNode` Class
Each node of the Trie is represented by the `TrieNode` class, which contains:
- `data`: The current character stored in the node.
- `childNode[26]`: An array of pointers to child nodes, one for each letter in the lowercase English alphabet.
- `isTerminalNode`: A boolean flag indicating whether the node marks the end of a word.

### `Trie` Class
The `Trie` class provides:
- A `root` node that serves as the entry point for the Trie.
- An `insert()` function to add words to the Trie.
- A `search()` function to check if a word exists in the Trie.

### Insert Function
The `insert()` function breaks down a word character by character. If the character is not present in the Trie, a new node is created for it. When the word is fully inserted, the last node is marked as terminal.

### Search Function
The `search()` function checks if a word exists by traversing through the Trie nodes corresponding to the characters of the word. It returns `true` if the word is found and marked as terminal.

## Code Example

```cpp
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
    if(str.length() == 0){
        root->isTerminalNode = true;
        return;
    }

    int index = str[0] - 'a';
    TrieNode* child;

    if(root->childNode[index] != NULL){
        child = root->childNode[index];
    } else {
        child = new TrieNode(str[0]);
        root->childNode[index] = child;
    }

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
        if(word.length() == 0){
            return root->isTerminalNode;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        if(root->childNode[index] != NULL){
            child = root->childNode[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insert("eat");
    cout << "word is present or not: " << t->search("eat") << endl;
    return 0;
}
