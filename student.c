#include "student.h"
#include <malloc.h>

STUDENT* students[MAX_STUDENTS]; //학생 정보 데이터


int _count=0;
int sCount=0;

void s_init(){
        //모든 레코드 제거
        int i;
        for(i=0;i<MAX_STUDENTS;i++){
                if(students[i]!=NULL){
                        free(students[i]);
                }
                students[i]=NULL;
        }
        _count=0;
	sCount=0;
#ifdef DEBUG
	printf("[DEBUG]Initializing Records _count: %d sCount: %d\n",_count, sCount);
#endif
}

int s_is_available(){
        int i;
        for (i=0;i<MAX_STUDENTS;i++){
                if(students[i]==NULL) return 1;
        }
        return 0;
}

STUDENT* s_search_by_name(char* n){
        int i;
        for (i=0;i<_count;i++){
                if (students[i]!= NULL&&strcmp(students[i]->name,n)==0) return students[i];
        }
        return NULL;
}


void s_create(char* n, char* num, char a, int s){
        int index=s_first_available();
#ifdef DEBUG
	printf("[DEBUG]first available index: %d\n ", index);
#endif
        students[index]=(STUDENT*)malloc(sizeof(STUDENT));
        STUDENT* p=students[index];
#ifdef DEBUG
	printf("[DEBUG]memory allocate %lu byte \n", malloc_usable_size(p));
#endif
	strcpy(p->name,n);
        strcpy(p->number,num);
        p->assignment = a; 
        if (p->assignment=='Y'){
                sCount++;
        }
        p->score = s;
        _count++;

#ifdef DEBUG
    printf("[DEBUG]new  record is created: %s %s %c %d\n ",s_getname(p),s_getnumber(p),s_getassignment(p), s_getscore(p));
#endif
}

int s_first_available(){
        int i;
        for(i=0;i<MAX_STUDENTS;i++){
                if(students[i]==NULL) return i;
        }
        return -1;
}

char* s_getname(STUDENT* p){
        return p->name;
}

char* s_getnumber(STUDENT* p){
        return p->number;
}

char s_getassignment(STUDENT* p){
        return p->assignment;
}

int s_getscore(STUDENT* p){
        return p->score;
}
int s_count(){
        return _count;
}

int s_count_submitStudent(){
        return sCount;
}
void s_get_all(STUDENT* a[]){
        int i, c = 0;
        for (i=0;i<MAX_STUDENTS;i++){
                if (students[i]!=NULL) {
                        a[c]=students[i];
                        c++;
                }
        }
#ifdef DEBUG
	printf("[DEBUG]get %d records\n",c);
#endif 
}

char* s_to_string(STUDENT* p){
        static char str[80];
        sprintf(str, "%s\t%s\t%c\t%d", p->name, p->number, p->assignment, p->score);
#ifdef DEBUG
	printf("[DEBUG]string: %s\t%s\t%c\t%d\n", p->name, p->number, p->assignment, p->score);
#endif

        return str;

}

double s_getAveragScore(){
  // 과제를 제출한 학생들의 평균 점수를 계산하여 리턴한다.
	int sum=0;
	double average;
	for(int i=0;i<_count;i++){
		if (students[i]!= NULL&&students[i]->assignment=='Y'){
                        sum+=students[i]->score;
                }
        }
	average=(double)sum/(double)sCount;
#ifdef DEBUG
	printf("[DEBUG]return average(%.1f)\n", average);
#endif
	return average;
}    


int s_get_all_by_number(STUDENT* a[], char* n){
        // 학번 앞 3자리가 일치하는 모든 레코드 포인터의 배열 만들기
        int i, c = 0;
        for(i=0;i<_count;i++){
                if (students[i]!= NULL&&students[i]->number[0]==n[0]&&students[i]->number[1]==n[1]&&students[i]->number[2]==n[2]){
                        a[c] = students[i];
                        c++;
                }
        }
#ifdef DEBUG
	printf("[DEBUG]get %d correspoding  records\n",c);
#endif 
        return c;

}


char* s_to_string_save(STUDENT* p){
        static char str[80];
        sprintf(str, "%s %s %c %d", p->name, p->number, p->assignment, p->score);

#ifdef DEBUG
	printf("[DEBUG]string(for save): %s\t%s\t%c\t%d\n", p->name, p->number, p->assignment, p->score);
#endif
        return str;


}

int s_get_submitStudent(STUDENT* a[]){
        int c=0;
        for(int i=0;i<_count;i++){
                if(students[i]!=NULL&&students[i]->assignment=='Y'){
                        a[c]=students[i];
                        c++;
                }
        }
#ifdef DEBUG
	printf("[DEBUG]get %d submit student\n", c);
#endif
        return c;
}

char* s_to_string_stats_save(){
        static char str[200];
        sprintf(str, "%d students submitted\nscore average: %.1lf\n",s_count_submitStudent(),s_getAveragScore());
#ifdef DEBUG
	printf("[DEBUG]string(for save stats): %d students submitted\nscore average: %.1lf\n",s_count_submitStudent(),s_getAveragScore());
#endif
        return str;
}
