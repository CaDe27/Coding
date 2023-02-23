
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)
#define iloop(i,a,b) for(int i = a; i > b; --i)

const int maxN = 3e5 + 5, maxQ = maxN, maxBlocks = 1000 + 5;
int n, q, k, arre[maxN], resp[maxQ];
int block_size;

//answer is -1 if there is not or the number if it works
struct query{
    int left, right, block, answer, indx;
    bool operator < (const query &other) const{ 
        return right < other.right;
    }
};
vector<query> blocks[maxBlocks];

int block_bucket[maxN], non_block_bucket[maxN];
void process_block(int block_id){
    if(blocks[block_id].size() == 0) return;

    fill(block_bucket + 1, block_bucket + n + 1, 0);
    fill(non_block_bucket + 1, non_block_bucket + n + 1, 0);

    int fin_block = block_size * (block_id+1) - 1;
    
    int left_pointer, right_pointer, mostFrequentInNonBlock = 0, mostFrequentInQuery;
    left_pointer = right_pointer = blocks[block_id][0].left;
    ++block_bucket[ arre[left_pointer] ];
    for(query qu : blocks[block_id]){
        //update right pointer
        while(right_pointer != qu.right){
            ++right_pointer;
            if(right_pointer > fin_block){
                ++non_block_bucket[arre[right_pointer]];
                if(non_block_bucket[mostFrequentInNonBlock] < non_block_bucket[arre[right_pointer]]){
                    mostFrequentInNonBlock = arre[right_pointer];
                }
            }
            else{
                ++block_bucket[arre[right_pointer]];
            }
        }

        //update left pointer
        while(left_pointer < qu.left){
            --block_bucket[arre[left_pointer]];
            ++left_pointer;
        }

        while(qu.left < left_pointer){
            --left_pointer;
            ++block_bucket[arre[left_pointer]];
        }

        //we answer query 
        mostFrequentInQuery = mostFrequentInNonBlock;
        loop(i, left_pointer, 1+min(fin_block, right_pointer)){
            if( block_bucket[arre[i]] + non_block_bucket[arre[i]] > block_bucket[mostFrequentInQuery] + non_block_bucket[mostFrequentInQuery]){
                mostFrequentInQuery = arre[i];
            }
        }
        int total_frequency = block_bucket[mostFrequentInQuery] + non_block_bucket[mostFrequentInQuery];
        resp[qu.indx] = total_frequency * k >= right_pointer - left_pointer + 1? mostFrequentInQuery : -1;
    }
}

void Mos(){
    int total_blocks = (n + block_size - 1) / block_size; 
    loop(i, 0, total_blocks)
        process_block(i);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    cin>>n>>k>>q;
    loop(i, 0, n) 
        cin>>arre[i];
    
    block_size = (int)sqrt(n);
    query foo;
    loop(i, 0, q){
        cin>>foo.left>>foo.right;
        foo.indx = i;
        foo.block = foo.left / block_size;
        blocks[foo.block].push_back(foo);
    }

    loop(i, 0, block_size)
        sort(blocks[i].begin(), blocks[i].end());    

    Mos();

    loop(i, 0, q)
        cout<<resp[i]<<(i < q-1? " ":"\n");
    return 0;
}