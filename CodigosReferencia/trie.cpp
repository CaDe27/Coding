#include <iostream>
#include <string>

using namespace std;

class trie{
    struct node{
        bool isEndOfWord;
        node* children[26];
    };

    node* getNode(){
        node* a = new node;
        a -> isEndOfWord = false;
        
        for(int i = 0; i < 26; ++i){
            a-> children[i] = NULL;
        }
        
       return a;
    }

    node* raiz;

    public:
        trie(){ raiz = getNode();}

        void insert(string word){
            node* it = raiz;
            for(char c : word){
                if( it -> children[c - 'a'] == NULL){
                    it -> children[c - 'a'] = getNode();
                }
                it = it -> children[c-'a'];
            }
            it ->isEndOfWord = true;
        }

        bool busca(string word){
            node* it = raiz;
            int i = 0;
            for(char c: word){
                if(it -> children[ c-'a'] == NULL)
                    break;
                else{
                    it  = it->children[ c -'a'];
                    ++i;
                }
            }
            return i == word.size() && it->isEndOfWord;
        }
    
};


int main(){
    trie a; 
    a.insert("hola");
    cout<<a.busca("hola")<<endl;

    
    return 0;

}
