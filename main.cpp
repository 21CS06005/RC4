#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
  string plainText;
  cout<<"Enter the plain text:"<<endl;
  getline(cin, plainText); 

  string key;
  cout<<"Enter the key:"<<endl;
  getline(cin, key); 

  int length = plainText.length();
  int s[256], k[256], j=0, keyStream[length], pt_ascii[length], encryptedText[length], decryptedText[length];

// Preparing pre-requisite data arrays based on key
  for(int i=0; i<256; i++) {
    s[i] = i;
    k[i] = int(key[i%key.length()]);
  } 

  for(int i=0; i<length; i++) {
    pt_ascii[i] = plainText[i];
  }

// keyscheduling
  for(int i=0; i < 256; i++) {
    j = (j + s[i] + k[i]) % 255;
    
    // Swapping s[i] and s[j]
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }

//stream generation
 int i = 0;
 j = 0;
 for(int l=0; l<length; l++) {
   i = (i+1)%255;
   j = (j+s[i])%255;
  
// Swapping s[i] and s[j]
  int temp = s[i];
  s[i] = s[j];
  s[j] = temp;

  int t = (s[i] + s[j]) % 255;
  keyStream[i] = s[t];
 } 

// Encryption
  for(int m=0; m<length; m++) {
    encryptedText[m] = pt_ascii[m] ^ keyStream[m];
  }

  cout<<endl<<"Encrypted text:"<<endl;
  for(int m=0; m<length; m++) {
    cout<<char(encryptedText[m])<<" ";
  }

  cout<<endl<<"Decrypted text:"<<endl;

  for(int m=0; m<length;m++) {
    decryptedText[m] = encryptedText[m] ^ keyStream[m];
    cout<<char(decryptedText[m]);
  }
}