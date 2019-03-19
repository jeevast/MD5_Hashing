#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>
#include<stdlib.h>
#define ascii_len 256


unsigned char * val_checker;
unsigned char* hash_fun(char val[]);
void func(void);
unsigned char val[] = {0x51, 0x67};
int cmp_hash(unsigned char * arr_ver);




        EVP_MD_CTX *mdctx;
	const EVP_MD *md;
	unsigned char md_value[EVP_MAX_MD_SIZE];
        unsigned int md_len, i;



int main()
{


     char arg_val[] = "md5";
     md = EVP_get_digestbyname(arg_val);
     

	char arr[] = "harD";
	unsigned char * mymessage = hash_fun(arr);
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
							if(cmp_hash(message) == 1)
							{
								p = 0;
								for(int n = 0; n < strlen(en); n++)
									{
										printf("%02x", en[n]);
									}
								
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


int cmp_hash(unsigned char * arr_var)
{
	int count = 0;
	for(int i = 0; i < 2; i++)
		{
			if(arr_var[i] == val[i])
				{
					count++;

				}
		}
	if (count == 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	

