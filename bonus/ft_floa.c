#include <math.h>
#include <stdio.h>

void reverse(char* str, int len)
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

int intToStr(int x, char *res, int d)
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
		res[i] = 's';
		i++;
	}	
	reverse(res, i);
	res[i] = '\0';
	return (i);
}

void ftoa(float n, char* res, int afterpoint)
{
	int ipart; 
	float fpart;
  	int i;
		
	i = 0;
	ipart = (int)n;
	i = intToStr(ipart, res, 0);
	fpart = n - (float)ipart;

	if (afterpoint != 0) {
		res[i] = '.';

		fpart = fpart * pow(10, afterpoint);

		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}


int main()
{
	char res[20];
	float n = 1337.4200;
	ftoa(n, res, 10);
	printf("\"%s\"\n", res);
	return 0;
}

