#include<iostream>

using namespace std;

struct Trie{
    struct Node{
        Node *children[26];
        int initializedChildren;
        bool isEndOfWord;
    };

    struct Node *getNode() 
    { 
        struct Node *pNode =  new Node; 

        pNode -> isEndOfWord = false; 
        for (int i = 0; i < 26; i++) 
            pNode->children[i] = NULL; 

        return pNode; 
    } 

    Node* root;

    Trie(){
        root = getNode();
    }

    void insert(string key) 
    { 
        Node *pCrawl = root; 
        for (int i = 0; i < key.length(); ++i) 
        { 
            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]) 
                pCrawl->children[index] = getNode(); 
            pCrawl = pCrawl->children[index]; 
        } 
    
        // mark last node as leaf 
        pCrawl->isEndOfWord = true; 
    } 

    bool search(string word){
        Node *pCrawl = root; 
        bool band = false;
        for (int i = 0; i < word.length(); ++i) 
        { 
            int index = word[i] - 'a'; 
            if (!pCrawl->children[index]) 
                return false; 
            pCrawl = pCrawl->children[index]; 
        } 
        return pCrawl->isEndOfWord;
    }
    
    void remove(string word){
        Node *pCrawl = root; 
        bool band = false;
        for (int i = 0; i < word.length(); ++i) 
        { 
            int index = word[i] - 'a'; 
            if (!pCrawl->children[index]) 
                break;
            pCrawl = pCrawl->children[index]; 
        } 
        pCrawl->isEndOfWord = false; 
    }
};

