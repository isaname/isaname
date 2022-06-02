#ifndef STUDNET_H
#define STUDNET_H
struct student
{
    int id;//学号
    double math;
    double chinese;
    double english;
    double physics;
    double chemistry;
    int rank;//排名
};//学生结构体
typedef struct student Student;
#endif
