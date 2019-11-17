#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int *keyfunctio(int n){
	int* ar = new int[n]; 
	cout<<"Enter the Key for 2nd Encryption: "<<endl;
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	return ar;
}
string caesar(char msg[],int key){
	char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if (ch > 'z') {
              ch = ch - 'z' + 'a' - 1;
            }  
            msg[i] = ch;
         }
         else if (ch >= 'A' && ch <= 'Z'){
         	 ch = ch + key;
            if (ch > 'Z'){
               ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
         }
      }
      return msg;
}
void trans(string cipher, int key2, int arr[]){
	int col,j; 
	string cipher1 = ""; 
	col = key2;
	int length=cipher.size();
	int row =ceil((float)length/(float)col); 	
	char matrix[row][col]; 
	for (int i=0,k=0; i<row; i++) 
	{ 
		for (int j=0; j<col; ) 
		{ 
			if(cipher[k] == '\0' || cipher[k]==' ') 
			{ 
				matrix[i][j] = '_';	 
				j++; 
			} 
			
			if( isalpha(cipher[k]) ) 
			{ 
				matrix[i][j] = cipher[k]; 
				j++; 
			} 
			k++; 
		} 
	} 
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl<<"The Encrypted Message is : ";
	for(int i=0;i<key2;i++){
		for(int j=0;j<row;j++){
			cout<<matrix[j][arr[i]-1];
		}
	
	}
	cout<<endl<<endl;
}
int main(){
	char ch[100];
	int n, k;
	cout<<"Enter the String : ";
	cin.getline(ch,100);
	cout<<"Enter the key for 1st encryption :"<<endl;
	cin>>k;
	string ch2 = caesar(ch,k);
	cout<<"Enter the no. of columns of matrix"<<endl;
	cin>>n;
	int *ar2= keyfunctio(n);
	int key2 = n;
	trans(ch2,key2,ar2);
}
