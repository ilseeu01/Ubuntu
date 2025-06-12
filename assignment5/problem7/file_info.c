#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct stat st;

    if (stat(argv[1], &st) != 0) {
        perror("stat");
        return 1;
    }

    printf("파일 이름: %s\n", argv[1]);
    printf("inode 번호: %ld\n", st.st_ino);
    printf("파일 크기: %ld 바이트\n", st.st_size);
    printf("하드링크 수: %ld\n", st.st_nlink);
    printf("접근 시간: %s", ctime(&st.st_atime));
    printf("수정 시간: %s", ctime(&st.st_mtime));
    printf("권한: %o\n", st.st_mode & 0777);

    return 0;
}

