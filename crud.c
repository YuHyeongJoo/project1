#include "crud.h"
//ver_B
T_Record* members[MAX_MEMBERS]; // 회원정보데이터 (전역)
int _count = 0;

void m_update(T_Record* p, char* su, int gr, int se){
 	strcpy(p->subject, su);
	p->grade = gr;
	p->semester = se;
}

int m_first_available(){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]==NULL) return i;
    }
    return -1;
}
int m_count(){
    return _count;
}

int m_partial_search(char* n, T_Record* a[]){
  int c =0;
  for(int i=0; i<MAX_MEMBERS; i++){
    if(!members[i]) break;
    if(strstr(members[i]->name, n)){
      a[c]= members[i];
	c++;      
	#ifdef DEBUG
          printf("Struct pointer index %d is saved in the arry\n", i);
      #endif
    }
  }
  return c;
}

void bubbleswap(int g1, int g2){
	 T_Record* tem;
	 tem = members[g1];
	 members[g1]=members[g2];
	 members[g2]= tem;
	#ifdef DEBUG
      		printf("Struct array (index %d) and (index %d)  is swapped \n", g1,g2);
  	#endif
}


void m_create(char* n, char* su, int id, int sem ,char* g, int gr){
    int index = m_first_available();
    members[index] = (T_Record*)malloc(sizeof(T_Record));
    T_Record* p = members[index];
    strcpy(p->name, n);
    #ifdef DEBUG
        printf("Name: %s is saved in the list\n",n);
    #endif
    strcpy(p->subject, su);
    #ifdef DEBUG
        printf("Subject: %s is saved in the list\n", su);
    #endif
    p->studentID = id;
    #ifdef DEBUG
        printf("StudentID: %d is saved in the list\n", id);
    #endif
    p->semester = sem;
    #ifdef DEBUG
        printf("Semester: %d is saved in the list\n", sem);
    #endif
    strcpy(p->gender, g);
    #ifdef DEBUG
        printf("Gender: %s is saved in the list\n", g);
    #endif
    p->grade =gr;
    #ifdef DEBUG
        printf("Grade: %d is saved in the list\n", gr);
    #endif
    _count++;
    #ifdef DEBUG
        printf("Count-variable is incresed into %d\n", _count);
    #endif
}

T_Record* m_search_by_name(char* n){
    int i;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i] && strcmp(members[i]->name, n)==0) return members[i];
    }
    return NULL;
}

char* m_to_string(T_Record* p){
    static char str[80];
    sprintf(str, "[%d] %s / %s / %d / %s / %d", p->studentID, p->name, p->subject, p->semester, p->gender, p->grade);
    return str;
}

void m_delete(T_Record* p){
    int i, index;
    for(i=0; i<MAX_MEMBERS; i++)
        if(members[i]==p) {
            index=i;
            break;
        }
    free(p);
    for(int k = index; k<_count-1; k++){
	members[k] = members[k+1];
}
    members[_count-1] = NULL;
    _count--;
}
void m_get_all(T_Record* a[]){
    int i, c=0;
    for(i=0; i<MAX_MEMBERS; i++){
        if(members[i]){
        	 a[c]=members[i];
           	 c++;
	   	 #ifdef DEBUG
               		 printf("Struct pointer index %d is saved in the arry\n", i);
           	 #endif
        }
    }
}

char* m_getname(T_Record* p){
    return p->name;
}

char* m_getsubject(T_Record* p){
    return p->subject;
}

int m_getstudentID(T_Record* p){
    return p->studentID;
}

int m_getsemester(T_Record* p){
    return p->semester;
}

char* m_getgender(T_Record* p){
  return p->gender;

}

int m_getgrade(T_Record* p){
  return p-> grade;

}
