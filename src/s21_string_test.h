#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_
#include <check.h>
#include <limits.h>
#include <unistd.h>
#define MAX 1024
#define BUF 128

void string_reset(char *arr1, char *arr2);

char origin[MAX] = "\0";
char test[MAX] = "\0";

char tc1[BUF] = "Hello world\0";
char tc2[BUF] = "Hi, world\n\0";
char tc3[BUF] = "a\n\0";
char tc4[BUF] = " \n\0";
char tc5[BUF] = " \0";
char tc6[BUF] = "\n\0";
char tc7[BUF] = "\0";
char tc8[BUF] = "01234567890\0";
char tc9[BUF] = "Iehgffffgfhgfhgfllo\0";
char tc10[BUF] = "source\\folder1\\folder2\\filename\0";
char tc11[BUF] = "\n\n\f\r\t\0";
char tc12[BUF] = "      \0";
char tc13[BUF] = "    world    ";
char *t;

#endif  // SRC_S21_STRING_TEST_H_
