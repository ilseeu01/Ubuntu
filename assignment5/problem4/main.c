#include <stdio.h>
#include <string.h>
#include "copy.h"

char line[MAXLINE];  	// 현재 입력 줄을 저장할 배열
char longest[MAXLINE]; 	// 현재까지 가장 긴 줄을 저장할 배열

/* 입력 줄 가운데 가장 긴 줄을 출력한다. */
int main()
{
    int len; // 현재 입력 줄의 길이
    int max; // 가장 긴 줄의 길이 초기화

    max = 0;

    while (fgets(line, MAXLINE, stdin) != NULL) { //표준 입력에서 줄을 하나씩 읽어들임
        len = strlen(line); // 현재 줄의 길이 계산
        if (len > max) { // 지금까지의 최대 길이보다 크면
            max = len; // 최대 길이 갱신
            copy(line, longest); // 현재 줄을 longet에 복사
        }
    }

    if (max > 0)   // 입력 줄이 존재한다면
       printf("%s", longest); //가장 긴 줄 출력

   printf("코드 종료\n"); 
   return 0;
}
