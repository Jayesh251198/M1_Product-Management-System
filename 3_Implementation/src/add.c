/**
 * @file add.c
 * @author Aditi Iyer
 * @brief 
 * @version 0.1
 * @date 2021-09-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "op.h"


void add_item()
{
	int cn=5757;
	int ind, val;
	char c;
	int a=0;
	

	FILE *fp;


	do
	{
		system("cls");
		printf("Company code is %d\n", cn);
		printf("============ Enter Product Details ============");
		int ID;
	
		fp = fopen("ViewStorage.dat","a+");

		if((fp = fopen("ViewStorage.dat","a+"))!=NULL)
		{
			I:
			printf("\nCosmetic Code\t :");
			scanf("%i",&ID);
			while(fscanf(fp,"%s %s %i %i %i", st.cosmeticproductname, st.cosmeticproductcomp, &st.cosmeticprice, &st.cosmeticproductid,&st.cosmeticquantity)!=EOF)
			{
				
				if(ID == st.cosmeticproductid)
				{
					printf("\n\tThe Cosmetic Code already exists.Kindly enter a different Cosmetic Code.\n");
					goto I;
				}
			}
			st.cosmeticproductid = ID;
		}
		else//runs if sfile is empty
		{
			printf("\nCosmetic Code\t :");
			scanf("%i",&st.cosmeticproductid);
		}

	//add Cosmetic Name
		do
		{	
			fflush(stdin);
			printf("\nCosmetic Name\t :");
			gets(st.cosmeticproductname); // get input string
			st.cosmeticproductname[0]=toupper(st.cosmeticproductname[0]);
			//iterate for every character in string
			for (ind=0; ind<strlen(st.cosmeticproductname); ++ind)
			{	//check if character is val or not
				if(isalpha(st.cosmeticproductname[ind]))
					val = 1;
				else
				{
					val = 0;
					break;
				}
			}
			if (!val)
			{
				printf("\n Name contains invalid characters. Please 'Enter' the Cosmetic Name again");
				getch();


			}
		}while(!val);	//while end here


		//Cosmetic Company
			do
		{
			char cosmeticproductcomp[40];
			fflush(stdin);
			printf("\nCosmetic Company\t :");
			gets(st.cosmeticproductcomp); // get input string
			st.cosmeticproductcomp[0]=toupper(st.cosmeticproductcomp[0]);
			//iterate for every character in string
			for (ind=0; ind<strlen(st.cosmeticproductcomp); ++ind)
			{	//check if character is val or not
				if(isalpha(st.cosmeticproductcomp[ind]))
					val = 1;
				else
				{
					val = 0;
					break;
				}
			}
			if (!val)
			{
				printf("\n Name contains invalid character. Please 'Enter' the Cosmetic Company again");
				getch();


			}
		}while(!val);

		//cosmeticproductid
		
				printf("\nCosmetic Price\t:");
				scanf("%i",&st.cosmeticprice);
				

				
				printf("\nCosmetic Quantity :");
				scanf("%i",&st.cosmeticquantity);
				


		fp=fopen("ViewStorage.dat","a");
		fprintf(fp,"\n%s %s %i %i %i", st.cosmeticproductname, st.cosmeticproductcomp,st.cosmeticprice, st.cosmeticproductid,st.cosmeticquantity);
		fclose(fp);
		printf("\nPress 'Enter' to add more item and any other key to go to main menu");
		
	

	}
	while((c = getch()) =='\r');
	
}




