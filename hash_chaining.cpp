#include<iostream>
#include<vector> 
#define m 11

using namespace std;

vector<int> hash[m];

void func(int n){
    int index;
    index = n % m;
    hash[index].push_back(n); 
}

void print(){
    int i,j;
    for(i=0;i<m;i++){
        cout << "[" << i << "]";
        for(j=0;j<hash[i].size();j++){
            cout<<"->" << hash[i][j];
        }
        cout << "->NULL"<< endl; 
    }
}

void search(int n){
    int index,i;
    index = n % m;
    for(i=0;i<hash[index].size();i++){
        if(hash[index][i] == n){
            cout << n<<" is in the table" << endl;
            cout << "index :" <<"["<< index <<"]"<<"["<< i <<"]" << endl;
            return;
        }
     }
    cout<< n<<" is not in the table" << endl;
}

void remove(int n){
    int index,i;
    index = n % m;
    for(i=0;i<hash[index].size();i++){
        if(hash[index][i] == n){
            cout << n << " is in the table.And deleted succesfully" << endl;
            hash[index].erase(hash[index].begin()+i);
            return;
        }
    }
    cout << "Element is not in the table.Deletion unsuccesful" << endl;
}

int main(){
    func(22);
    func(1);
    func(13);
    func(11);
    func(24);
    func(33);
    //func(22);
    print();
    search(24);
    search(44);
    remove(11);
    search(11);
    print();
}