//Repechaje 2019
//Problema E
//La idea es usar Trie y contar la cantidad de palabras que son hojas

#include<iostream>

using namespace std;

struct Trie{
    struct Node{
        Node *children[26];
        int nChildren;
        bool isEndOfWord;
    };
    
    struct Node *getNode(void) 
    { 
        struct Node *pNode =  new Node; 

        pNode -> isEndOfWord = false; 
        pNode -> nChildren = 0;
        for (int i = 0; i < 26; i++) 
            pNode->children[i] = NULL; 
        return pNode; 
    } 
    Node* root;
    int leaves;
    Trie(){root = getNode(); leaves = 0;}
    void insert(string key) 
    { 
        Node *pCrawl = root; 
        for (int i = 0; i < key.length(); ++i) 
        { 
            //this if is to not count the leaves that are not leaves anymore
            //it works in this problem because I don't need to know what words I do have
            //that aren't leaves
            if( pCrawl->nChildren == 0 && pCrawl->isEndOfWord == true){
                pCrawl -> isEndOfWord = false;
                --leaves;
            }

            int index = key[i] - 'a'; 
            if (!pCrawl->children[index]){
                pCrawl->children[index] = getNode();
                (*pCrawl).nChildren++;
            }

            pCrawl = pCrawl->children[index];
        } 

        //only added if it wasn't in the trie already
        if(pCrawl->isEndOfWord != true and pCrawl -> nChildren == 0){ 
            pCrawl->isEndOfWord = true;
            ++leaves;
        }

    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    Trie a = Trie();
    int T;
    cin>>T;
    string word;
    for(int t = 0; t < T; ++t){
        cin>>word;
        a.insert(word);
    }
    cout<<a.leaves<<'\n';
}

