#include<iostream>
#include<vector>
//#include<string.h>
#define m 11
using namespace std;
int x = 31;
/*struct node{
    int index;
    string word;
};*/
vector<string> hash[m];
//vector<string> list[m];

void add_word(string s){
    //cout << "here";
    int index;
    int i = 0;
    while(s[i] != '\0'){
        index = index + (int)s[i] * (x ^ i);
        i++;
    }
    index = index % m;
    hash[index].push_back(s);

}

void search(string s){
    //cout << "huh";
    int index;
    int i = 0;
    while(s[i] != '\0'){
        index = index + (int)s[i] * (x ^ i);
        i++;
    }
    index = index % m;
    //cout << "here";
    for(i=0;i<hash[index].size();i++){
        if(hash[index][i] == s){
            cout << "word is in the hash table at position "<< index << endl;
            return;
        }
    }
        cout<<"word is not in the hash table" << endl;
        return;
}

void display(){
    int i,j;
    for(i=0;i<m;i++){
        cout << i <<"->";
        for(j=0;j<hash[i].size();j++){
            cout << hash[i][j] << "->";
        }
        cout << "NULL" << endl;
    }
}

int main(){

    add_word("hold");
    search("hold");
    add_word("kill");
    search("jug");
    display();
    add_word("sidda");
    add_word("piththa");
    add_word("royya");
    add_word("aoyry");
    add_word("dhimbe");
    search("kaiya");
    display();
}
