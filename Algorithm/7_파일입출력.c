#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // fopen, fwrite, fclose 함수가 선언된 헤더 파일
#include <string.h>    // strlen 함수가 선언된 헤더 파일

int main()
{
	char *s1 = "Hello, world!";
	char data[20];
	char buffer1[100], buffer2[100];

	FILE *fp = fopen("hello.txt", "a");    // hello.txt 파일을 쓰기 모드(w)로 열기.
										   // 파일 포인터를 반환
	fputs("Hello, world!", fp);    // 파일에 문자열 저장
	fputs("Hello, world2!", fp);    // 파일에 문자열 저장
	fwrite(s1, strlen(s1), 1, fp);    // strlen으로 문자열의 길이를 구함.
									  // 문자열의 길이만큼 1번 파일에 저장

	fclose(fp);    // 파일 포인터 닫기

	
	fp = fopen("hello.txt", "r");
	fgets(buffer1, sizeof(buffer1), fp); // 한줄만 읽음
	fgets(buffer2, sizeof(buffer2), fp); // 한줄만 읽음
	fread(buffer1, sizeof(buffer1), 1, fp);   // hello.txt에서 버퍼 크기(20바이트)만큼 1번 값을 읽음
	while (fscanf(fp, "%s", &data) != EOF) {
		printf("%d\n", data);
	}

	fclose(fp);

	return 0;
}