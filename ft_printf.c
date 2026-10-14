#include "ft_printf.h"

#include <stdio.h>

#include <string.h>

static int ft_conversion(const char type, va_list vargs)
{
	if(type=='c')
		return(ft_putchar(va_arg(vargs,int)));
	else if(type=='u')
		return (ft_putnbr(va_arg(vargs,unsigned int)));
	else if(type=='i' || type=='d')
		return (ft_putnbr(va_arg(vargs,int)));
	else if(type=='s')
		return (ft_putstr(va_arg(vargs,char *)));
	else if(type=='x'|| type=='X')
		return (ft_puthex(va_arg(vargs,unsigned int),type));
	else if(type=='p')
		return (ft_putptr(va_arg(vargs,void *)));
	else if(type=='%')
		return ft_putchar('%');
	return -1;
}

int ft_printf(const char *str, ... )
{
	va_list args;
	va_start(args,str);
	int len=0;
	int check=0;
	while(*str)
	{
		if(*str=='%')
		{
			check=ft_conversion(*(++str),args);
			if(check==-1)
				return -1;
			len+=check;
		}
		else
		{
			if(write(1,str,1)==-1)
				return -1;
			len++;
		}
		str++;
	}
	va_end(args);
	return len;
}

int main()
{
	//int maxnum=max(4,10,12,14,16);
	//max(4,10,12,14,16);
	//printf("%d",maxnum);
	char* null=NULL;
	char* s="";
	char stri[]="i love mama empty string %s  NULL string %s ";
	ft_printf(stri,s,null);
	return 0;
}
