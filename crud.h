#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMBERS 50
typedef struct st_member{
    char name[20];  //
    char subject[20]; //
    int studentID;  //
    int semester;  //
    char gender[20];
    int grade; //
} T_Record;
void m_update(T_Record* p, char* su, int gr, int se);
void m_delete(T_Record* p);
void m_get_all(T_Record* a[]);  // 회원정보가 들어있는 모든 레코드 포인터의 배열을 만들기
char* m_to_string(T_Record* p); // 특정 회원 레코드의 내용을 문자열로 가져오기
char* m_getname(T_Record* p);   // 특정 회원 레코드의 회원이름 가져오기
int m_getstudentID(T_Record* p);  // 특정 회원 레코드의 회원전화번호 가져오기
int m_getsemester(T_Record* p);// 특정 회원 레코드의 회원생년 가져오기
int m_getgrade(T_Record* p);   // 특정 회원 레코드의 회원거주도시 가져오기
char* m_getgender(T_Record*);
char* m_getsubject(T_Record* p);
int m_count();
int m_first_available();
void m_create(char* n, char* su, int id, int sem ,char* g, int gr);
T_Record* m_search_by_name(char* n);
int m_partial_search(char* n, T_Record* a[]);
void bubbleswap(int g1, int g2);
