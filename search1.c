#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>
#include<stdlib.h>


void func(void);
unsigned char* hash_fun(char a[]);
EVP_MD_CTX *mdctx;
const EVP_MD *md;
unsigned char md_value[EVP_MAX_MD_SIZE];
unsigned int md_len, i;
//int cmp_func(unsigned char * cmp_val);
int  cmp_arr(unsigned char * val_arr);

unsigned char val_checker[] = "cebdc06632de5dcd7219415264d4be25"; 



void main(void)
{
char arg_val[] = "md5";
md = EVP_get_digestbyname(arg_val);
func();



}



void func(void)
{
int p = 1;
	
for(int i = 0; i < 256 && p == 1; i++)
{
	
	char en[4]; en[0] = i;
	for(int j = 0; j < 256 && p == 1; j++)
		{
				en[1] =  j;
			for(int k = 0; k < 256&& p == 1; k++)
				{
					en[2] =  k;

					for(int l = 0; l < 256 && p == 1; l++)
						{
							
							
						
							
							en[3] =  l;
							
							
							
							
							
								
							unsigned char * message = hash_fun(en);
							if(cmp_arr(message) == 0)
							{
								p = 0;
								printf("%s\n", en);
							}
									

						}
				}
		} 
}
}



	

unsigned char * hash_fun(char val[])
{

     mdctx = EVP_MD_CTX_new();
     EVP_DigestInit_ex(mdctx, md, NULL);
     EVP_DigestUpdate(mdctx, val, strlen(val));
     EVP_DigestFinal_ex(mdctx, md_value, &md_len);
     EVP_MD_CTX_free(mdctx);
     return md_value;

  
	
}

int  cmp_arr(unsigned char * val_arr)
{

	
	
	unsigned char temp_arr[33];
	
	for(int i = 0; i < 16; i++)
	{
		sprintf(temp_arr + 2*i, "%02x", val_arr[i]);
	}
	
	return strcmp(val_checker, temp_arr);
}
