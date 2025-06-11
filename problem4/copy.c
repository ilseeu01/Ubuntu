#include <stdio.h>
#include "copy.h"

/*  from을 to에 복사, to가 충분히 크다고 가정한다 */
void copy(char from[], char to[])
{
   int i;

   i = 0; // 인덱스 변수 초기화
   while ((to[i] = from[i]) != '\0') //null 문자를 만날 때까지 문자 복사
       ++i; // 다음 문자로 이동
} 
