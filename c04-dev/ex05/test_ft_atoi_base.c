#include <stdio.h>
#include "ft_atoi_base.c"

int main(void)
{
	char* s1 = "10011";
	printf("Testing: %s, 01\n", s1);
	printf("Result is: %d\n", ft_atoi_base(s1, "01"));
	printf("Correct answer: 19\n\n");

	char* s2 = "78786";
	printf("Testing: %s, 0123456789\n", s2);
	printf("Result is: %d\n", ft_atoi_base(s2, "0123456789"));
	printf("Correct answer: 78786\n\n");

	char* s3 = "ef3dcd";
	printf("Testing: %s, 0123456789abcdef\n", s3);
	printf("Result is: %d\n", ft_atoi_base(s3, "0123456789abcdef"));
	printf("Correct answer: 15678925\n\n");

	char* s4 = "hijklmnop12345";
	printf("Testing: %s, 0123456789abcdef\n", s4);
	printf("Result is: %d\n", ft_atoi_base(s4, "0123456789abcdef"));
	printf("Correct answer: 0 <immediately non base chars>\n\n");

	char* s5 = "";
	printf("Testing: %s, 0123456789\n", s5);
	printf("Result is: %d\n", ft_atoi_base(s5, "0123456789"));
	printf("Correct answer: 0 <empty string>\n\n");

	char* s6 = "      123";
	printf("Testing: %s, 0123456789\n", s6);
	printf("Result is: %d\n", ft_atoi_base(s6, "0123456789"));
	printf("Correct answer: 123 <handles whitespace>\n\n");

	char* s7 = "-+--12345";
	printf("Testing: %s, 0123456789\n", s7);
	printf("Result is: %d\n", ft_atoi_base(s7, "0123456789"));
	printf("Correct answer: -12345 <handles multiple -/+>\n\n");

	char* s8 = "     -+-+-12345abc";
	printf("Testing: %s, 0123456789\n", s8);
	printf("Result is: %d\n", ft_atoi_base(s8, "0123456789"));
	printf("Correct answer: -12345 <handles mixed things>\n\n");

	char* s9 = "     -+-+-12345 123abc";
	printf("Testing: %s, 0123456789\n", s9);
	printf("Result is: %d\n", ft_atoi_base(s9, "0123456789"));
	printf("Correct answer: -12345 <ignores numbers after non num>\n\n");	

	char* s10 = "123";
	printf("Testing: %s, \"\"\n", s10);
	printf("Result is: %d\n", ft_atoi_base(s10, ""));
	printf("Correct answer: 0 <empty base string>\n\n");	


	char* s11 = "123";
	printf("Testing: %s, 0\n", s11);
	printf("Result is: %d\n", ft_atoi_base(s11, "0"));
	printf("Correct answer: 0 <1 length base string>\n\n");	

	char* s12 = "123";
	printf("Testing: %s, 0123456787\n", s12);
	printf("Result is: %d\n", ft_atoi_base(s12, "0123456787"));
	printf("Correct answer: 0 <duplicate char in base string>\n\n");	

	char* s13 = "123";
	printf("Testing: %s, 012345678+\n", s13);
	printf("Result is: %d\n", ft_atoi_base(s13, "012345678+"));
	printf("Correct answer: 0 <+ char in base string>\n\n");	

	char* s14 = "123";
	printf("Testing: %s, -123456789\n", s14);
	printf("Result is: %d\n", ft_atoi_base(s14, "-123456789"));
	printf("Correct answer: 0 <- char in base string>\n\n");	

}

