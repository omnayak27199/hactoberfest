#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 32
int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif 

    string e;    getline(cin, e, '\n');
    string key;  getline(cin, key, '\n');
    int flag = 0, temp = 0, n=4, t;

    if(e.length() > 16 && e.length() <= 32)
    {
    	e.insert(e.length(), 32-e.length(), ' ');
    	flag = 1;
    }
    if(e.length() < 16)
    {
    	e.insert(e.length(), 16-e.length(), ' ');
    	//flag = 1;
    }
    if(key.length() < 16) key.insert(key.length(), 16-key.length(), ' ');
    

    int key_matrix[4][4], key_temp[4][4];

        temp = 0;
        for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++){
        		key_matrix[i][j] = int(key[temp++]);
        	    key_temp[i][j] = key_matrix[i][j];}
        }


      for(int i=0;i<n/2;i++)
      {
      for(int j=i;j<n-i-1;j++)
      {
          int temp=key_matrix[i][j];
          key_matrix[i][j]=key_matrix[j][n-i-1];
          key_matrix[j][n-i-1]=key_matrix[n-i-1][n-j-1];
          key_matrix[n-i-1][n-j-1]=key_matrix[n-j-1][i];
          key_matrix[n-j-1][i]=temp;
      }
   }
   t = 2;
   while(t--)for (int i=1;i<n-1/2;i++) 
   { 
     for (int j=i;j<n-i-1;j++) 
     { 
             int temp=key_matrix[i][j]; 
             key_matrix[i][j]=key_matrix[n-1-j][i]; 
             key_matrix[n-1-j][i]=key_matrix[n-1-i][n-1-j]; 
             key_matrix[n-1-i][n-1-j]=key_matrix[j][n-1-i]; 
             key_matrix[j][n-1-i]=temp; 
     }  
   }    
    

    if(!flag)
    {
    	int e_matrix[4][4], ans[4][4]; 
                temp = 0;
        
        for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++)
        		e_matrix[i][j] = int(e[temp++]);
        }

        for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++)
        	    ans[i][j] = e_matrix[i][j] ^ key_matrix[i][j] ^ key_temp[i][j] ^ 4;
        }
        
        for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++)
        		cout<<char(ans[i][j])<<endl;
        }


   }


else 
{ 
    	int e_matrix[2][4][4], ans[2][4][4]; 
        
        temp = 0;
        for(int k = 0; k<2; k++)
        for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++)
        		e_matrix[k][i][j] = int(e[temp++]);
        }

  for(int k = 0; k<2; k++)
  for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++)
        	    ans[k][i][j] = e_matrix[k][i][j] ^ key_matrix[i][j] ^ key_temp[i][j] ^ 4;
        }

for(int k = 0; k<2; k++)
for(int i = 0; i<4; i++)
        {
        	for(int j = 0; j<4; j++)
        		cout<<char(ans[k][i][j]);
        }
} 
    return 0;
}


