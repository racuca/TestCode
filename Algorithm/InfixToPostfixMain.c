#include <stdio.h>
#include "InfixToPostfix.h"
#include "InfixToPrefix.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	char exp4[] = "(1+2)*(3-4)";
	char exp5[] = "(1*2+3)/4";
	char exp6[] = "1+2-3/4";

	// 후위표기법
	char* convexp1 = ConvToRPNExp(exp1);
	char* convexp2 = ConvToRPNExp(exp2);
	char* convexp3 = ConvToRPNExp(exp3);
	char* convexp4 = ConvToRPNExp(exp4);
	char* convexp5 = ConvToRPNExp(exp5);
	char* convexp6 = ConvToRPNExp(exp6);

	// 전위표기법
	char* prefix1 = infix_to_prefix(exp1);
	char* prefix2 = infix_to_prefix(exp2);
	char* prefix3 = infix_to_prefix(exp3);
	char* prefix4 = infix_to_prefix(exp4);
	char* prefix5 = infix_to_prefix(exp5);
	char* prefix6 = infix_to_prefix(exp6);

	printf("%s => %s , %s\n", exp1, convexp1, prefix1);
	printf("%s => %s , %s\n", exp2, convexp2, prefix2);
	printf("%s => %s , %s\n", exp3, convexp3, prefix3);
	printf("%s => %s , %s\n", exp4, convexp4, prefix4);
	printf("%s => %s , %s\n", exp5, convexp5, prefix5);
	printf("%s => %s , %s\n", exp6, convexp6, prefix6);
	return 0;
}