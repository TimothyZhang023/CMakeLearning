//
// Created by zts1993 on 15-7-16.
//

#ifndef LIBEVENTLEARNING_FETCH_H
#define LIBEVENTLEARNING_FETCH_H



/* For sockaddr_in */
#include <netinet/in.h>
/* For socket functions */
#include <sys/socket.h>
/* For gethostbyname */
#include <netdb.h>

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int fetchHttp();

#endif //LIBEVENTLEARNING_FETCH_H
