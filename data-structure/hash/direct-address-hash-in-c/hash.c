#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Number of student in the class.
 */
#define STUDENT_COUNT 40

/**
 * @struct Student
 * @brief Student structure.
 */
typedef struct Student
{
  /**
   * @brief Name of a student.
   */
  char *name;

  /**
   * Roll of a student.
   */
  int roll;

  /**
   * Birthday of a student
   */
  char *birthDate;
} Student;

/**
 * @struct Table
 * @brief
 */
typedef struct Table
{
  Student **students;
  int length;
} Table;

Table *createTable()
{
  Table *t = (Table *)malloc(sizeof(Table));
  if (!t)
  {
    return NULL;
  }

  t->students = calloc(STUDENT_COUNT, sizeof(Student *));
  t->length = 0;

  return t;
}

void insertStudent(Table *t, char *name, int key, char *birthDate)
{
  Student *s = (Student *)malloc(sizeof(Student));
  if (!s)
  {
    printf("[insertStudent]: Failed to create student.\n");
    exit(0);
  }

  s->name = name;
  s->roll = key;
  s->birthDate = birthDate;

  t->students[key] = s;
  t->length++;
}

void deleteStudent(Table *t, int key)
{
  if (!t)
  {
    printf("[deleteStudent]: Table does not exits.\n");
    exit(0);
  }

  Student *s = t->students[key];
  free(s);
  t->students[key] = NULL;
}

Student *searchStudent(Table *t, int key)
{
  if (!t)
  {
    printf("[searchStudent]: Table does not exits.\n");
    exit(0);
  }

  Student *s = t->students[key];
  if (!s)
  {
    return NULL;
  }

  return s;
}

int main()
{
  Table *t = createTable();
  if (!t)
  {
    printf("Failed to create table\n");
    exit(0);
  }

  int key;

  key = 1;
  insertStudent(t, "Badhon Mia", key, "1 Jan");
  key = 30;
  insertStudent(t, "Student 30", key, "30 Jun");
  key = 40;
  insertStudent(t, "Student 40", key, "27 Step");

  deleteStudent(t, 30);

  printf("Roll 1: %s\n", searchStudent(t, 1) ? searchStudent(t, 1)->name : "Not Found");
  printf("Roll 30: %s\n", searchStudent(t, 30) ? searchStudent(t, 30)->name : "Not Found");
  printf("Roll 40: %s\n", searchStudent(t, 40) ? searchStudent(t, 40)->name : "Not Found");

  return 0;
}