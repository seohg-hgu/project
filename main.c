#include "student.h"

#ifndef DEBUG
#define DEBUG
#endif

void create_record();
void read_record();
void read_submitRecord();
void list_record();
void search_record_by_number();
void load_file();
void save_file();
void print_stats();
void save_reportFile();
void update_record();
void sort_record_by_name();
void delete_record_by_name();
void arrange_record();

int main(){
        s_init();
        int menu;
        while(1){
                printf("\nMenu : 1.Create 2.Read 3.list of submit student 4.Update 5.Delete 6.List 7.Search(student number) 8.Sort(by name) 9.load 10.save 11.arrange records 12.stats 13.save(report file)  0.Quit > ");
                scanf("%d", &menu);
                printf("\n");
                switch(menu){
                case 1:
                        create_record();
                        break;
                case 2:
                        read_record();
                        break;
                case 3:
                        read_submitRecord();
                        break;
                case 4:
                        update_record();
                        break;
                case 5:
                         delete_record_by_name();
                         break;
                case 6:
                        list_record();
                        break;
                case 7:
                        search_record_by_number();
                        break;
                case 8: sort_record_by_name();
                        break;
                case 9: load_file();
                        break;
                case 10: save_file();
                         break;

                case 11: arrange_record();
                         break;
                case 12: print_stats();
                         break;
                case 13: save_reportFile();
                         break;
                case 0:
                default:
                        return 0;
                }
        }
        return 0;
}

void create_record(){
        if (!s_is_available()){
                printf("There is no space!\n");
                return;
        }
        char name[20], number[10], assignment;
        int score;

        printf("Enter a new student's info.\n");
        printf("Student name > ");
        scanf("%s", name);
        getchar();
        if (s_search_by_name(name)){
                printf("Duplicated name!\n");
                return;
        }
        printf("Student number > ");
        scanf("%s", number);
        getchar();
        printf("Assignment submit (Y / N) > ");
        scanf("%c", &assignment);
        getchar();
        printf("Assignment score > ");
        scanf("%d", &score);
        s_create(name, number, assignment, score);
}
void read_record(){
        char name[20];
        printf("Enter a student name > ");
        scanf("%s", name);


        STUDENT* p=s_search_by_name(name);
        if(p){
                printf("Student info.\n");
                printf("Student name : %s\n", s_getname(p));
                printf("Student number : %s\n", s_getnumber(p));
                printf("Assignment submit : %c\n", s_getassignment(p));
                printf("Assignment score : %d\n", s_getscore(p));
        }
        else{
                printf("No such member!\n");
        }
}

void read_submitRecord(){
        //과제를 제출한 학생 목록 출력
        printf("List of students who submitted assignments\n");
        STUDENT* records[MAX_STUDENTS];
        int num=s_get_submitStudent(records);
        if(num==0){
                printf("No student.\n");
        }
        for(int i=0;i<num;i++){
                STUDENT* p = records[i];
                printf("%d. %s\n", i + 1,s_to_string(p));
        }
}

void list_record(){
        // 전체 리스트 출력
        printf("All records.\n");
        int size = s_count();
        STUDENT* records[MAX_STUDENTS];
        s_get_all(records);
        for(int i=0;i<size;i++){
                STUDENT* p = records[i];
                printf("%d. %s\n", i + 1, s_to_string(p));
        }
}
void search_record_by_number(){
        //학번 앞 3자리로 검색
        char number[4];
        printf("Enter a first 3 digits of Student number ex)219 > ");
        scanf("%s", number);
        STUDENT* records[MAX_STUDENTS];
        int size = s_get_all_by_number(records, number);
        printf("%d records found.\n", size);
        for (int i=0;i<size;i++){
                STUDENT* p = records[i];
                printf("%d. %s\n", i + 1, s_to_string(p));
        }
}

void load_file(){
        printf("All data will be deleted and new records will be reloaded.\n");
        printf("1.Yes 0.No > ");
        int yesno;
        scanf("%d" , &yesno);
        if(yesno==0) return;
        s_init(); //레코드 모두 제거

        FILE* f=fopen("students.txt", "r");
        char name[20], number[20], assignment;
        int score;
        while(!feof(f)){
                if(!s_is_available()){
                        printf("[Load] There is no space!\n");
                        break;
                }
                int n=fscanf(f, "%s %s %c %d",name, number, &assignment, &score);
                if(n<4) break;

                if(s_search_by_name(name)) {
                        printf("[Load] Duplicated name(%s)! loading.\n", name);
                        continue;
                }
                s_create(name, number, assignment, score);
                printf("[Load] load %s\n", name);
        }
        printf("%d records are read from file!\n", s_count());
        fclose(f);
}


void save_file(){
        FILE* f=fopen("students.txt", "w");
        int size=s_count();
        STUDENT* records[MAX_STUDENTS];
        s_get_all(records);
        for(int i=0;i<size;i++){
                STUDENT* p=records[i];
                fprintf(f, "%s\n", s_to_string_save(p));
        }
        fclose(f);
}

void print_stats(){
        int *a;
        printf("%d students submitted.\n",s_count_submitStudent());
        printf("score average: %.1lf\n",s_getAveragScore());
        printf("Grade\n");
        a=s_get_grade();
        printf("A: %d명\n",a[0]);
        printf("B: %d명\n",a[1]);
        printf("C: %d명\n",a[2]);
        printf("D: %d명\n",a[3]);
        printf("E: %d명\n",a[4]);
}

void save_reportFile(){
        int *a;
        FILE* f=fopen("students_stats.txt","w");
        fprintf(f, "%s\n", s_to_string_stats_save());
        fprintf(f,"Grade\n");
        a=s_get_grade();
        fprintf(f,"A: %d명\n",a[0]);
        fprintf(f,"B: %d명\n",a[1]);
        fprintf(f,"C: %d명\n",a[2]);
        fprintf(f,"D: %d명\n",a[3]);
        fprintf(f,"E: %d명\n",a[4]);
        fclose(f);

}
void update_record(){

        printf("students who didn't submit assignments.\n");
        int size = s_count();
        STUDENT* records[MAX_STUDENTS];
        s_get_all(records);
        for(int i=0;i<size;i++){
                STUDENT* p = records[i];
                if(p->assignment=='N') printf("%d. %s\n", i + 1, s_to_string(p));
        }
        char name[20], number[20], assignment;
        int score;
        printf("Enter a name> ");
        scanf("%s" , name);

        STUDENT *p=s_search_by_name(name);
        if(p){
                printf("Enter a updated info.\n");
                printf("number > ");
                scanf("%s",number);
                printf("assignment submit (Y / N) > ");
                scanf(" %c", &assignment);
                printf("score > ");
                scanf("%d", &score);

                s_update(p, number, assignment, score);

        }else{
                printf("No such member!\n");
        }


}
void sort_record_by_name(STUDENT* p){
        printf("Sorted records\n");
        int size=s_count();
        STUDENT* records[MAX_STUDENTS];
        s_sort_by_name(records);
        for(int i=0;i<size;i++){
                STUDENT* p=records[i];
                printf("%d. %s\n",i+1,s_to_string(p));
        }
}
void delete_record_by_name(){

        char name[20];
        printf("Enter a name > ");
        scanf("%s", name);

        STUDENT* p=s_search_by_name(name);
        if(p){
                s_delete(p);
                printf("The record is deleted!\n");
        }else{
                printf("No such member!\n");
        }
}

void arrange_record(){
        print_debug();
        printf("Arrange records\n");
        arrange();
        print_debug();
}


