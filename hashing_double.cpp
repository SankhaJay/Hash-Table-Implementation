#include<iostream>
#define m 13
int count = 0;
int hash[m];
using namespace std;

int func(int n){
    int index,p,q;
    
    p = n % m;
    q = 8 - (n % 8);
    int i = 0;
    int k = 13;
    while(1){
        index = (p + i*q) % k;
        if(hash[index] == '\0'){
            hash[index] = n;
            count++;
            break;
        }
        else if(count == m){
            cout << "Hash table is full"<< endl;
            break;
        }
        else{
            i++;
        }
    }
}

void print(){
     int i;
     for(i=0;i<m;i++){
         printf("%d -> %d\n",i,hash[i]);
     }
 }

 void search(int n){
     int index,p,q;
     int s = 0;
     int i = 0;
     int k = 13;
     p = n % m;
     q = 8 - (n % 8);
     while(1){
        index = (p + i*q) % k;
        if(hash[index] == n){
            cout << "element is in the table at position " << index<< endl;
            break; 
        }
        else if(hash[index] == '\0'){
            cout << "element is not in the table" << endl;
            break;
        }
        else{
            i++;
        }
        

     }

 }

 int main(){
    func(18);
    func(41);
    func(22);
    func(44);
    func(59);
    func(32);
    func(31);
    func(73);
    func(123);
    func(45);
    func(88);
    func(456);
    func(563);
    func(777);
    print();
    //cout << count << endl;
    search(73);
    search(10);
 }

