#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main(void)
{
	/*char	*c;
	int i;

	i = -1;
	c = (char *)malloc(sizeof(char) * 11);
	while (++i < 10)
		c[i] = 'a';
	printf("point: %#5.5p\n", c);
	ft_printf("mypoint: %#5.5p\n", c);*/
	//ft_printf("%%%%Hello_%-20.5s, %s\n", "My_NaMe_is_qmartina", NULL);
//	printf("HELLO!%015.5s!\n", "this is test");//HELLO!          this !
//	printf("HELLO!%+15.5s!\n", "this is test");
//	printf("HELLO!%0-015.5s!\n", "this is test");
//	printf("HELLO!%015.5s!\n", "this is test");
//	printf("HELLO!% 15.5s!\n", "this is test");
	//printf("orig: %-10.5d!\n", 123456789);
	//ft_printf("test: %-10.5d!\n", 123456789);
	printf("orig: u:%u;o:%o;x:%x;X:%X;\n", 1234, 1234, 1234, 1234);
	ft_printf("test: u:%u;o:%o;x:%x;X:%X;\n", 1234, 1234, 1234, 1234);
}