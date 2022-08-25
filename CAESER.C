#include<stdio.h>
#include<conio.h>

char *encrypt(char *plain,int key)
{
	char cipher[100];
	int i=0,cip,num;
	while(plain[i]!='\0')
	{
		if((plain[i]>='A')&&(plain[i]<='Z'))
		{
			num=plain[i]-'A';
			cip=(num+key)%26;
			cip=cip+'A';
		}
		else if((plain[i]>='a')&&(plain[i]<='z'))
		{
			num=plain[i]-'a';
			cip=(num+key)%26;
			cip=cip+'a';
		}
		cipher[i]=cip;
		i++;

	}
	cipher[i]='\0';
	return cipher;
}


char *decrypt(char *cipher,int key)
{
	char *plain;
	int i=0,cip,num;
	while(cipher[i]!='\0')
	{
		if((cipher[i]>='A')&&(cipher[i]<='Z'))
		{
			num=cipher[i]-'A';
			cip=(num-key)%26;
			if(cip<0)
				cip=cip+26;
			cip=cip+'A';
		}
		else if((cipher[i]>='a')&&(cipher[i]<='z'))
		{
			num=cipher[i]-'a';
			cip=(num-key)%26;
			if(cip<0)
				cip=cip+26;
			cip=cip+'a';
		}
		plain[i]=cip;
		i++;

	}
	plain[i]='\0';
	return plain;
}

int main()
{
	char message[100];
	int key;
	clrscr();
	printf("Enter the plain text (only letters) : ");
	scanf("%s",message);
	printf("Enter the key to create cipher text (0-25) :");
	scanf("%d",&key);
	printf("\nThe encrypted message = %s",encrypt(message,key));
	printf("\nThe decrypted message = %s",decrypt(encrypt(message,key),key));
	getch();
	return 0;

}
