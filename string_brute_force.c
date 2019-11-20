#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

static const char alphabet[] =
"lev"
"LEV";
int result=0;
static const int alphabetSize = sizeof(alphabet) - 1;

void bruteImpl(char* str, int index, int maxDepth)
{
    for (int i = 0; i < alphabetSize; ++i)
    {
        str[index] = alphabet[i];

        if (index == maxDepth - 1) 
	  
	{  char firstStr[]="exploit_";
	   strcat(firstStr,str);
	   //printf("\n%s\n", firstStr);
	   char command[50];
           char str1[]="echo -n ";
           char str2[]=" |";
           char str3[]=" md5sum";
           strcat(str1,firstStr);
           //printf("İlk atama %s\n",str1);
           strcat(str1,str2);
	   //printf("İkinci atama %s\n",str1);
           strcat(str1,str3);
	   //printf("Üçüncü atama %s\n",str1);
 
           strcpy( command,  str1);
	   char appendFile[]=" >> a.txt";
	   strcat(command,appendFile);
           system(command);
	   FILE *fp;

           fp = fopen("a.txt", "a+");
           fprintf(fp, " %s\n",firstStr);
           
           fclose(fp);

	}
        else bruteImpl(str, index + 1, maxDepth);
    }

}

void bruteSequential(int maxLen)
{
    char* buf = malloc(maxLen + 1);

    for (int i = 1; i <= maxLen; ++i)
    {
        memset(buf, 0, maxLen + 1);
        bruteImpl(buf, 0, i);
    }

    free(buf);
}

int main(void)
{   clock_t start, end; 
    start = clock(); 
    bruteSequential(5);
    end = clock()-start;
    double time_taken = ((double)end)/CLOCKS_PER_SEC;
    printf("Taking time: %.2f\n",time_taken);
    return 0;
}
// cat a.txt | grep -A 1 0b0d839247b9e564905bb851a4b12b01
