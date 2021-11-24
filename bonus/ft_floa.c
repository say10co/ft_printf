#include <math.h>
#include <stdio.h>

void ft_reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int ft_intToStr(int x, char *res, int d)
{
	int i;

	i  = 0;
	while (x)
	{
		res[i] =  (x % 10) + '0';
		x /= 10;
		i++;
	}
	while (i < d)
	{
		res[i] = '0';
		i++;
	}	
	ft_reverse(res, i);
	res[i] = '\0';
	return (i);
}
/*
int ft_pow(int a, int b)
{
	int t;

	t =  a;
	while (b--)
		a *= t;
	return (a);
}
*/
void ft_ftoa(float n, char* res, int afterpoint)
{
	int ipart; 
	float fpart;
  	int i;
		
	i = 0;
	ipart = (int)n;
	i = ft_intToStr(ipart, res, 0);
	fpart = n - (float)ipart;
	if (afterpoint != 0) {
		res[i] = '.';
		
		fpart = fpart * pow(10, afterpoint);

		ft_intToStr((int)fpart, res + i + 1, afterpoint);
	}
}
