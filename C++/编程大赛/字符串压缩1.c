#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char buff1[] = "aaAaaBBBBcBbbbgggFFGGFfff";
char buff2[] = {0};


void CompressStr(const char *SrcStr, char *DstStr){
    unsigned int count=0;
    while(*SrcStr!='\0'){
        if(*SrcStr==*(SrcStr+1)){
            count++;
        }else if(count>0){
            *DstStr=*SrcStr;
            DstStr++;
            *(DstStr)='0'+count+1;
            DstStr++;
            count=0;
        }else *DstStr++=*SrcStr;
        SrcStr++;
    }
    *DstStr='\0';//字符串输出最后记得加上\0
}
int main(void)
{
	
	CompressStr(buff1, buff2);

	printf("%s\n", buff2);

	return 0;
}


