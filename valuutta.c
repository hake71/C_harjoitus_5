/**
	* Version: 0.0.1
	* Author: Hannu Harju
	*/

/**
	*
	* Calculate given formula
	*/
	
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CURR_TBL_SIZE  4
char CurrTbl[CURR_TBL_SIZE][4] = {
	"USD\0", "FIN\0", "JNE\0", "EUR\0"
	};

float RateTbl[CURR_TBL_SIZE] = {
	1.0,
	5.1,
	230.32,
	0.7522
};

char CheckCurr(char *curr)
{
	int i = 0;
	int Found = 0;
	
	do{
		Found = strncmp((const char *)curr \
			, (const char *)&CurrTbl[i], 3);
		i++;
	}while((Found) && (i<CURR_TBL_SIZE));
	
	if(Found){
		return 0;
	}
	return i;	
}

int main(int argc, char *argv[]) {

	int result;
	float money_amount = 0.0;
	float tmp_value = 0.0;
	float target_value = 0.0;
	char From, To;

	/* Read and check parameters */
	if(argc < 4){
		printf(" ERROR: Missing parameters \n");
		return 1;
	}
	/* Check number of money */
	result = sscanf(argv[1], "%f", &money_amount);
	if(result < 0){
		printf(" ERROR: Number not correct %d\n",result);
		return 1;
	}
	/* Check source currency */
	From = CheckCurr(argv[2]);
	if(	From == 0 ){
		printf(" --> NOK\n");
		return 1;
	}
	/* Check target currency */
	To = CheckCurr(argv[3]);
	if( To == 0 ){
		printf(" --> NOK\n");
		return 1;
	}
	
	/* Actual conversion */
	tmp_value = RateTbl[From-1];
	tmp_value = money_amount / tmp_value;
	
	target_value = RateTbl[To-1];
	target_value = target_value * tmp_value;

	/* Print result */
	printf("%.2f %s = %.2f %s (Conversion rate: 1 %s = %.4f %s)\n", \
		money_amount, CurrTbl[From-1], \
		target_value, CurrTbl[To-1], \
		CurrTbl[From-1], target_value/money_amount, \
		CurrTbl[To-1]);
	
	return 0;
}
