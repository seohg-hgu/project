#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 5

typedef struct student{
	char name[20];  // 학생 이름
        char number[10]; // 학생 학번
        char assignment; // 과제 제출 여부(Y or N)
        int score; // 과제 점수
}STUDENT;


void s_init(); //모든 정보 제거
int s_is_available();       // 추가할 수 있는 데이터 공간이 있는지 확인한다.
STUDENT* s_search_by_name(char* n);     //  입력받은 이름과 일치하는 레코드 포인터를 찾아 리턴한다.
int s_first_available();    // 추가할 수 있는 가장 빠른 포인터 배열의 인덱스를 찾는다.
void s_create(char* n, char* num, char a, int s);   // 새로운 학생의 정보를 추가한다.
char* s_getname(STUDENT* p);   // 특정 학생의 이름 가져오기
char* s_getnumber(STUDENT* p);  // 특정 학생의 학번 가져오기
char s_getassignment(STUDENT* p);       // 특정 학생의 과제제출여부 가져오기
int  s_getscore(STUDENT* p);   // 특정 학생의 과제점수 가져오기
int s_count();              // 저장된 학생 레코드 수를 리턴한다.
int s_count_submitStudent();              // 과제를 제출한 학생 수를 리턴한다.
void s_get_all(STUDENT* a[]);  // 회원정보가 들어있는 모든 레코드 포인터의 배열을 만들기
char* s_to_string(STUDENT* p); // 특정 학생의 정보를 문자열로 가져오기
double s_getAveragScore();    // 과제를 제출한 학생들의 평균 점수를 계산하여 리턴한다.
int s_get_all_by_number(STUDENT* a[], char* n); //학번 앞자리 3자리가 입력값과 일치하는 모든 포인터의 배열 만들기, 일치하는 학생의 수 리턴
char* s_to_string_save(STUDENT* p); //특정 학생의 정보를 파일 저장용 문자열로 가져오기
char* s_to_string_stats_save(); //과제 제출 통계를 보고서 파일 저장용 문자열로 가져오기
int s_get_submitStudent(STUDENT* a[]);// 과제 제출 학생 배열 만들고 제출 학생수 리턴
void s_update(STUDENT* p, char* num,  char a, int s);  // 특정 학생의 정보 업데이트
void s_sort_by_name(STUDENT* a[]); //학생 레코드를 이름으로 정렬한다.
void s_delete(STUDENT* p);     // 특정 학생의 정보를 제거한다
