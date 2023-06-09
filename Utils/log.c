#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "log.h"

#define ERR "\x1b[31;1m"
#define INFO "\x1b[32;1m"
#define OK "\x1b[94;1m"
#define RESET "\x1b[0m"

#define BUFSIZE 256

void print_err(const char* format, ...){
  va_list args;
  char buffer[BUFSIZE];
  
  fprintf(stderr, "%s[*]%s ", ERR, RESET);
  
  va_start(args, format);
  vsnprintf(buffer, BUFSIZE, format, args);
  fprintf(stderr, "%s\n", buffer);
  va_end(args);
}

void print_info(const char* format, ...){
  va_list args;
  char buffer[BUFSIZE];
  
  fprintf(stdout, "%s[*]%s ", INFO, RESET);
  
  va_start(args, format);
  vsnprintf(buffer, BUFSIZE, format, args);
  fprintf(stdout, "%s\n", buffer);
  va_end(args);
}


void print_ok(const char* format, ...){
  va_list args;
  char buffer[BUFSIZE];
  
  fprintf(stdout, "%s[+]%s ", OK, RESET);
  
  va_start(args, format);
  vsnprintf(buffer, BUFSIZE, format, args);
  fprintf(stdout, "%s\n", buffer);
  va_end(args);
}
