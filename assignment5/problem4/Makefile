# Makefile 시작

# 변수 정의
CC = gcc
CFLAGS = -Wall -g

# 대상 실행 파일
TARGET = main_v2

# 컴파일할 소스들
OBJS = main.o copy.o

# 기본 명령: make만 치면 이게 실행됨
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 개별 파일 컴파일 규칙
main.o: main.c copy.h
	$(CC) $(CFLAGS) -c main.c

copy.o: copy.c copy.h
	$(CC) $(CFLAGS) -c copy.c

# clean: 컴파일된 파일 삭제
clean:
	rm -f $(TARGET) *.o

