#include <unistd.h> 
#include <string.h>//include your libft to use for any function used inside those functions
//this is a utilties file for ft_printf
//it will include all functions needed to remimmick the function printf
//1  %c chars 
//2  %s strings 
//3  %p pointers in hexa format 
//4  %d decimal
//5  %i int
//6  %u prints unsigned decimal
//7  %x number in hexa lowercase
//8  %X number in hexa uppercase
//9  %% percent sign
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_puthex(unsigned long n,char format);

int    ft_putchar(char c) //(1) && (9) %c && %%
{
	int count=0;

        if(count+=write(1, &c, 1)==-1)
		return -1;
	return count;
}

int    ft_putstr(char *s) //(2) %s
{
	int len=0;
	if(s==NULL)
	{
		if(write(1,"(null)",6)==-1)
			return -1;// write failed
		return 6;
	}
	len =strlen(s);//replace with ft_strlen 
	if(write(1, s, len)==-1)
		return -1;//write failed 
	return len;
}

int ft_putptr(void *ptr)//(3) %p
{
	int len;
	int aux;

	len=0;
	aux=0;
	if(ptr==NULL)
	{
		if(ft_putstr("(nil)")==-1)
			return -1;
		return len=5;
	}
	if(ft_putstr("0x")==-1)
		return -1;
	len+=2;
	aux=ft_puthex((unsigned long)ptr,'x');
	if(aux==-1)
		return -1;
	len+=aux;
	return len;
}

int    ft_putnbr(int n) //(4) && (5) && (6) %d && %i && %u
{
        char    digit;
	int count;

	count=0;
 	if (n == -2147483648)
        {
		if(write(1, "-2147483648", 11)==-1)
			return -1; //write failed
                return (write(1, "-2147483648", 11));
        }
        if (n < 0)
        {
                if((count += write(1, "-", 1))==-1)
                	return -1; //write failed
		n = -n;
        }
        if (n > 9)
                count += ft_putnbr(n / 10);
        digit = (n % 10) + '0';
	if(write(1, &digit, 1)==-1)
		return -1; //write failed
        count += write(1, &digit, 1);
	return (count);
}



int ft_puthex(unsigned long n,char format)//7 && 8 %x hexa lower and hexa upper
{
	char	*base;
	int	count;
	int	status;
	count=0;
	if(format=='x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if(n>16)
	{
		status=ft_puthex(n/16, format);
		if(status==-1)
			return -1;
		count+=status;

		status=ft_puthex(n%16, format);
		if(status==-1)
			return-1;
		count+=status;
	}
	else
	{
		count+=ft_putchar(base[n]);
	}
	return count;
}

