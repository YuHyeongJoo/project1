#include "crud.h"
void list_record();
void create_record();
void read_record();
void partial_search_print();
void make_report();
void read_file();
void bubblesort();
void write_record();
int main(){
    int menu;
    while(1){
        printf("\nMenu : 1.Add student 2.Read 3.List 4.Search and print all 5. Create reportfile 6. Make file 7. Read file 8.Sort grade point 0.Quit > ");
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
                list_record();
                break;
            case 4:
                partial_search_print();
                break;
	    case 5:
		make_report();
		break;
	    case 6:
		write_record();
		break;
 	    case 7:
		read_file();
		break;
	    case 8:
		bubblesort();
		break;
            case 0:
            default:
                return 0;
        }
    }
    return 0;
}

void create_record(){
    int c =m_count();
    if(c>=MAX_MEMBERS){
      printf("There is no space");
      return;
    }
    char name[20], sub[20],   gender[20];
    int id, sem, grade;
    printf("Enter a new member's info.\n");
    printf("Name > ");
    scanf("%s", name);

    printf("Subject > ");
    scanf("%s", sub);
    printf("StudentID > ");
    scanf("%d", &id);
    printf("Semester > ");
    scanf("%d", &sem);
    printf("Gender > ");
    scanf("%s", gender);
    printf("Grade > ");
    scanf("%d", &grade);
    m_create(name, sub, id, sem, gender, grade);
}
void partial_search_print(){
  char search[20];
  T_Record* records[MAX_MEMBERS];
  int count;
  printf("Search for the name you want to find: ");
  scanf("%s", search);
  count = m_partial_search(search, records);

  for(int i=0; i<count; i++){
      T_Record* p = records[i];
      printf("%d. %s\n", i+1, m_to_string(p));
  }
}
void list_record(){
    // 전체 리스트 출력
    printf("All records.\n");
    int size = m_count();
    T_Record* records[MAX_MEMBERS];
    m_get_all(records);
    for(int i=0; i<size; i++){
        T_Record* p = records[i];
        printf("%d. %s\n", i+1, m_to_string(p));
    }
}
void read_record(){
  char name[20];
  printf("Enter a neme>");
  scanf("%s",name);
  T_Record* p = m_search_by_name(name);
  if(p !=NULL){
    printf("student info\n");
    printf("Name: %s\n",m_getname(p));
    printf("Subject: %s\n",m_getsubject(p));
    printf("studentID: %d\n",m_getstudentID(p));
    printf("semester: %d\n",m_getsemester(p));
    printf("Gender: %s\n", m_getgender(p));
    printf("Grade : %d \n", m_getgrade(p));
  }
  else{
    printf("No such member!!");
  }
}

void make_report(){
  int size = m_count();
  T_Record* records[MAX_MEMBERS];
  m_get_all(records);
  FILE *fp = fopen("Report.txt", "w");
  for(int i =0; i<size; i++){
    T_Record* p = records[i];
    fprintf(fp,"%d. %s: %s %s: %s %s: %d %s: %d %s: %s %s: %d\n", i+1, "Name",m_getname(p), "\tSubject", m_getsubject(p), "\tStudendID",m_getstudentID(p),
    "\tSemester", m_getsemester(p), "\tGender", m_getgender(p), "\tGrade", m_getgrade(p));
  }

  fclose(fp);
}
void write_record(){
  T_Record* records[MAX_MEMBERS];
  m_get_all(records);
  FILE *fp = fopen("records.txt", "w");
  for(int i = 1; ;i++ ){
    T_Record* p = records[i-1];
     fprintf(fp, "%s %s %d %d %s %d",m_getname(p), m_getgender(p),m_getstudentID(p) ,m_getsemester(p),m_getsubject(p), m_getgrade(p));
     if( i>= m_count())break;
     fprintf(fp,"\n");
  }
  fclose(fp);
  return;
}
void read_file(){
  char name[20],  sub[20], gender[20];
  int id, sem, grade;
  FILE *fp = fopen("records.txt", "r");
  while(1){
    if(feof(fp)) break;
    int c =m_count();
    if(c>4){
      printf("There is no space");
      return;
    }
    fscanf(fp, "%s %s %d %d %s %d", name, gender ,&id, &sem, sub, &grade);
    m_create(name, sub, id, sem, gender, grade);
  }
}
void bubblesort(){
  T_Record* records[MAX_MEMBERS];
  m_get_all(records);
  int c = m_count();
  if(c==0){
    printf("No data\n");
    return;
  }
 
  int x;
  printf("1 for ascending order 2 for descendng order \n");
  scanf("%d", &x);
  if(x==1){
    for(int i=0; i<c-1; i++){
        for(int j=0; j<c-1; j++){
          if(m_getgrade(records[j])>m_getgrade(records[j+1])){
            bubbleswap(j,j+1);
            m_get_all(records);
         }
        }
      }
  }
  else{
    for(int i=0; i<c-1; i++){
        for(int j=0; j<c-1; j++){
          if(m_getgrade(records[j])<m_getgrade(records[j+1])){
            bubbleswap(j,j+1);
            m_get_all(records);
         }
        }
      }
  }

}

