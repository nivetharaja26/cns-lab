#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char mat[5][6],message[100],key[10],two[20][3],cipher[100];
int size;

void keygen()
{
   int i=0,j=-1,l,dup=0,k;
   char alp='a';

   for(k=0;key[k]!='\0';k++)
   {
      dup=0;
      for(l=k-1;l>=0;l--)
      {
	   if(key[k]==key[l])
	   {
		dup=1;
		break;
	   }
      }
      if(dup==0)
      {
	if(j>=4)
	{
		i++;
		j=0;
	}
	else
		j++;
	mat[i][j]=key[k];
      }
   }
   while(alp!=123)
   {
	dup=0;
	for(l=0;key[l]!='\0';l++)
	{
		if((alp==key[l])||(alp=='j'))
		{
			dup=1;
			alp++;
			break;
		}
	}
	if(dup==0)
	{
		if(j>=4)
		{
		i++;
		j=0;
		}
		else
		j++;
		mat[i][j]=alp++;
	}
   }
   for(i=0;i<5;i++)
   {
	for(j=0;j<5;j++)
	printf("%c\t",mat[i][j]);
	printf("\n");
   }

}
void split()
{
	int i,len,k=0;
	len=strlen(message);
	for(i=0;i<len;i=i+2)
	{
		if(message[i]!=message[i+1])
		{
			two[k][0]=message[i];
			if(message[i+1]=='\0')
			two[k][1]='x';
			else
			two[k][1]=message[i+1];

		}
		else
		{
			two[k][0]=message[i];
			two[k][1]='x';
			i--;

		}
		two[k][2]='\0';
		k++;
	}
	size=k;
	for(i=0;i<size;i++)
	printf("\nsplit=%s",two[i]);
}
void encrypt()
{
	int i,j,k,m,n,temp1,temp2,x=0,o,p;
	for(k=0;k<size;k++)
	{
		for(i=0;i<5;i++)
		for(j=0;j<5;j++)
		{
			if(two[k][0]==mat[i][j])
			{
				for(m=0;m<5;m++)
				{
					if(two[k][1]==mat[i][m])
					{
						 n=(j+1)%5;
						 cipher[x++]=mat[i][n];
						 n=(m+1)%5;
						 cipher[x++]=mat[i][n];
						 break;
					}
					else if(two[k][1]==mat[m][j])
					{
						n=(i+1)%5;
						cipher[x++]=mat[n][j];
						n=(m+1)%5;
						cipher[x++]=mat[n][j];
						break;
					}
					else
					{
						for(temp2=0;temp2<5;temp2++)
						if(two[k][1]==mat[m][temp2])
						{
							cipher[x++]=mat[i][temp2];
							cipher[x++]=mat[m][j];
							break;
						}
					}
				}
			}
		}
	}
	cipher[x]='\0';
	printf("\nCipher= %s",cipher);
}

int main()
{
	clrscr();
	printf("\nEnter the message in small case letter ");
	scanf("%s",message);
	printf("\nEnter the key in small case letter");
	scanf("%s",key);
	keygen(key);
	split();
	encrypt();
	getch();
	return 0;

}
