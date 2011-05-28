#include <stdio.h>
int main(void)
{
    int ii;
    for(ii=0;ii<21;ii++) {
	float val = ii / 20.0;
	printf("%8.3f => %4.1f\n", val, val);
    }
}
