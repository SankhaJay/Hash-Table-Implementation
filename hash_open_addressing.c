#include<stdio.h>
#define m 11
int hash[m];
int count = 0;

void func(int n){
    int index;
    index = n % m;
    int i = index;
    do{
        if(count == m){
            cout << "Hash table is full";
        }
        else if(hash[i] == '\0'){
            hash[i] = n;
            count++;
            break;
        }
        else if(i == m-1){
            i = 0;
        }
        else{
            i++;
            
        }
    }
    while(i != index);
}
void hashprint(){
     int i;
     for(i=0;i<m;i++){
         printf("%d -> %d\n",i,hash[i]);
     }
 }
 
int retrive(int n){
     int index;
     index = n % m;
     int i = index;
     do{
        if(hash[i] == n){
           index = i;
            break;
        }
        else if(i == m-1){
            i = 0;
        }
        else if(hash[i] == '\0'){
            printf("Value is not in the hash table\n");
            return -1;
        }
        else{
            i++;
        }
    }
    while(i != index);
    return index;
 }
 


int main(){
    func(22);
    func(1);
    func(13);
    func(11);
    func(24);
    func(33);
    hashprint();
}