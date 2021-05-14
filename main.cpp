#include <iostream>
#include <fstream>
using namespace std;

const int SIZE=13;
const int HASH=13;

struct node{
  string data;
  node* next = NULL;
};

struct node* bucketArray[SIZE];

//Big-O: O(1) since the insertion is at the specified index
//would be O(n) at the creation of a second node from the head
void insert(string newData){
struct node* newNode = new node;
newNode -> data = newData;
int sum = 0;
for(int i = 0; i<newData.size(); i++){
sum += newData[i];    //changing string to int
  }
newNode -> next = bucketArray[sum % HASH];  //pointing to location
bucketArray[sum % HASH] = newNode;   //placing value at pointed location 
}

//Big-O
bool find(string input){
struct node* temp;
int inspected = 0;
int sum = 0;
//O(n) for the conversion
for(int i = 0; i<input.size(); i++){
sum += input[i];    //changing string to int
  }
int x = sum % HASH;   //finding key for input
temp = bucketArray[x];

//O(1)
if(bucketArray[x]==NULL){
inspected++;
cout<<"inspected " <<inspected<< " elements " << "and "<<input<<" was not found"<<endl;
  return false;
}

//O(1)
if(bucketArray[x]->data == input){
inspected++;
cout <<"inspected "<<inspected<<" elements "<<" and "<< " found at index " << x << endl;
  return true;
}

//O(n)
else{
while(temp != NULL){
inspected ++;
if(temp -> data == input){
   cout <<"inspected "<<inspected<<" elements "<<" and "<< " found at index " << x << endl;
   return true;
      }
    temp = temp -> next;
   }
  cout<<"inspected " <<inspected<< " elements " << "and "<<input<<" was not found"<<endl;
  return false;
  }

}

void display(){
  struct node* temp;
  for(int i = 0; i<SIZE; i++){
    int x = i % HASH;
    temp = bucketArray[x];
    while(temp != NULL){
      cout<< temp -> data << " ";
      temp = temp -> next;
    }
    cout << endl;
  }
}

int main() {
//importing our strings
  fstream myFile;
  string wordArray[13];
  int m = 0;
  myFile.open("text.in");
  while (!myFile.eof()) {
    myFile >> wordArray[m];
    m++;
  }
  myFile.close();

  for(int i = 0; i < 13; i++){
    //cout<<wordArray[i];
    insert(wordArray[i]);
  }

  //display();

  string input;

  while(input != "404"){
  cout<<"Enter a string"<<endl;
  cin>>input;
  find(input);
  }

}
