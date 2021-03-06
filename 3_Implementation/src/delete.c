/**
 * @file delete.c
 * @author Aditi Iyer
 * @brief 
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "op.h"

void deleteproduct(void)
{
	char target[40];
	int found=0;
	FILE *sfile, *tfile;
	sfile=fopen("ViewStorage.dat","r");
	tfile=fopen("DeletedStorage.dat","w+");
	printf("\n Enter Cosmetic Name: ");
	fflush(stdin);
	scanf("%s",target);
	target[0]=toupper(target[0]);
	while (fscanf(sfile,"%s %s %i %i %i\n",st.cosmeticproductname,st.cosmeticproductcomp, &st.cosmeticprice,&st.cosmeticproductid,&st.cosmeticquantity)!=EOF)
	{
		if(strcmp(target,st.cosmeticproductname)==0)
		{
			found=1;
		}
		else
		{
			fprintf(tfile,"%s %s %i %i %i\n", st.cosmeticproductname,st.cosmeticproductcomp, st.cosmeticprice,st.cosmeticproductid,st.cosmeticquantity);
		}
	}
			if(!found)
			{
				printf("\n Cosmetic Product Record not found");
				getch();
				
			}
			else
			{
				printf("\n Cosmetic Product Record deleted");
			}
			fclose(sfile);
			fclose(tfile);
			remove("ViewStorage.dat");
			rename("DeletedStorage.dat","ViewStorage.dat");

			printf("\nPress any key to go to Main Menu!");
		while((st.c = getch()) =='\r');
		
}