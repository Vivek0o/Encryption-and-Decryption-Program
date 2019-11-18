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
char *dTrans(string cipher, int key2, int arr[]){
	int col,j; 
	string cipher1 = ""; 
	col = key2;
	int length=cipher.size();
	int row =ceil((float)length/(float)col); 	
	char matrix[row][col]; 
	for (int j=0,k=0; j<col; j++) 
	{ 
		for (int i=0; i<row;i++ ) 
		{ 
				matrix[i][j] = cipher[k++];  
		} 
	} 
//	for(int i=0; i<row; i++){			
//		for(int j=0; j<col; j++){
//			cout<<matrix[i][j]<<' ';
//	}
//	cout<<endl;
//	}
//	cout<<endl;
	char mat[row][col];
	for(int i=0;i<row;i++){
		for(j=0;j<col;j++){
			mat[j][arr[i]-1]=matrix[j][i];
		}
	}
//		for(int i=0; i<row; i++){			
//		for(int j=0; j<col; j++){
//			cout<<mat[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	char *c = new char[length];
	int k=0;
	for(int i=0;i<row;i++){
		for(j=0;j<col;j++){
			c[k] = mat[i][j];	
			k++;
		}
	}
	cout<<endl;
	return c;
}
void dCaesar(char msg[], int key4){
	char ch;
      for(int i = 0; msg[i] != '\0'; ++i) {
         ch = msg[i];
         //decrypt for lowercase letter
         if(ch=='_'){
         	msg[i]=' ';
		 }
         else if(ch >= 'a' && ch <= 'z') {
            ch = ch - key4;
            if(ch < 'a'){
               ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
         }
         //decrypt for uppercase letter
         else if(ch >= 'A' && ch <= 'Z') {
            ch = ch - key4;
            if(ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
         }
      }
      cout <<endl<< "Decrypted message: " << msg;
}

int main(){
	int dk,dk2;
	char dmsg[100];
	cout<<"Enter the Message to Encrypt: "<<endl;
	cin.getline(dmsg,100);
	cout<<endl;
	cout<<"Enter the size key of transposition algorithim: ";
	cin>>dk;
	cout<<endl;
	int *ar2= keyfunctio(dk);
	int key1 = dk;
 	char *c= dTrans(dmsg,key1,ar2);
 	cout<<"Enter the second Key to decrypt the final message: ";
 	cin>>dk2;
 	dCaesar(c,dk2);
}
