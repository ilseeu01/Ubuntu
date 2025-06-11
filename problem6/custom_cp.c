#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char c;
    FILE *fp1, *fp2;
    int count = 0;

    if (argc != 3) {
        fprintf(stderr, "사용법: %s 파일1 파일2\n", argv[0]);
        return 1;
    }

    // STEP 1: 입력 파일이 .txt로 끝나는지 확인
    char *ext = strrchr(argv[1], '.');  // 마지막 '.' 위치 찾기
    int is_text = (ext != NULL && strcmp(ext, ".txt") == 0);

    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);
        return 2;
    }

    fp2 = fopen(argv[2], "w");
    if (fp2 == NULL) {
        fprintf(stderr, "파일 %s 열기 오류\n", argv[2]);
        fclose(fp1);
        return 3;
    }

    // STEP 2: 복사하면서 문자 수 세기
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp2);
        if (is_text)
            count++;
    }

    fclose(fp1);
    fclose(fp2);

    // STEP 3: 문자 수 출력
    if (is_text)
        printf("총 %d개의 문자를 복사했습니다.\n", count);

    return 0;
}

