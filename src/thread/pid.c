//
// Created by zts1993 on 15-7-17.
//
#include "pid.h"


void print_pid()
{


    printf("pid %d \r\n", getpid() );

    pid_t pid_t1 = fork();

    printf("pid %d \r\n", pid_t1 );

    printf("pid %d \r\n", getpid() );




}