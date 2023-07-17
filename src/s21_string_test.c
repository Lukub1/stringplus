#include "s21_string.h"

#include "s21_string_test.h"

/* Чистит массив*/
void string_reset(char *arr1, char *arr2) {
  while (*arr1) {
    *arr1++ = 0;
  }
  arr1 = '\0';
  while (*arr2) {
    *arr2++ = 0;
  }
  arr2 = '\0';
}

START_TEST(test_s21_memchr) {
  ck_assert_str_eq(s21_memchr(tc1, ' ', 10), memchr(tc1, ' ', 10));
  ck_assert_ptr_eq(s21_memchr(tc2, '\0', 10), memchr(tc2, '\0', 10));
  ck_assert_ptr_eq(s21_memchr(tc2, '\0', 10), memchr(tc2, '\0', 10));
  ck_assert_ptr_eq(s21_memchr(tc3, 'Z', 5), memchr(tc3, 'Z', 5));
  ck_assert_str_eq(s21_memchr(tc5, ' ', 2), memchr(tc5, ' ', 2));
  ck_assert_ptr_eq(s21_memchr(tc7, '\n', 1), memchr(tc7, '\n', 1));
  ck_assert_ptr_eq(s21_memchr(tc1, 101, 0), memchr(tc1, 101, 0));
  ck_assert_ptr_eq(s21_memchr(tc1, 0, 0), memchr(tc1, 0, 0));
  ck_assert_str_eq(s21_memchr(tc10, '\\', 8), memchr(tc10, '\\', 8));
}
END_TEST

START_TEST(test_s21_memcmp) {
  ck_assert_int_eq(s21_memcmp(tc1, tc2, 100), memcmp(tc1, tc2, 100));
  ck_assert_int_eq(s21_memcmp(tc2, tc1, s21_strlen(tc1)),
                   memcmp(tc2, tc1, s21_strlen(tc1)));
  ck_assert_int_eq(s21_memcmp(tc3, tc4, 1), memcmp(tc3, tc4, 1));
  ck_assert_int_eq(s21_memcmp(tc1, tc2, 0), memcmp(tc1, tc2, 0));
  ck_assert_int_eq(s21_memcmp(tc10, tc11, 10), memcmp(tc10, tc11, 10));
}
END_TEST

START_TEST(test_s21_memcpy) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  ck_assert_str_eq(s21_memcpy(test, tc1, 8), memcpy(origin, tc1, 8));
  ck_assert_str_eq(s21_memcpy(test, tc2, 8), memcpy(origin, tc2, 8));
  ck_assert_str_eq(s21_memcpy(test, tc3, 2), memcpy(origin, tc3, 2));
  ck_assert_str_eq(s21_memcpy(test, tc4, 2), memcpy(origin, tc4, 2));
  ck_assert_str_eq(s21_memcpy(test, tc5, 2), memcpy(origin, tc5, 2));
  ck_assert_str_eq(s21_memcpy(test, tc6, 2), memcpy(origin, tc6, 2));
  ck_assert_str_eq(s21_memcpy(test, tc7, 2), memcpy(origin, tc7, 2));
  ck_assert_str_eq(s21_memcpy(test, tc8, 11), memcpy(origin, tc8, 11));
  ck_assert_str_eq(s21_memcpy(test, tc9, 15), memcpy(origin, tc9, 15));
  ck_assert_str_eq(s21_memcpy(test, tc10, 40), memcpy(origin, tc10, 40));
  ck_assert_str_eq(s21_memcpy(test, tc11, 5), memcpy(origin, tc11, 5));
}
END_TEST

START_TEST(test_s21_memmove) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  char *t = &test[5];
  char *o = &origin[5];
  ck_assert_str_eq(s21_memmove(test, tc1, 8), memmove(origin, tc1, 8));
  ck_assert_str_eq(s21_memmove(test, tc2, 8), memmove(origin, tc2, 8));
  ck_assert_str_eq(s21_memmove(test, tc3, 2), memmove(origin, tc3, 2));
  ck_assert_str_eq(s21_memmove(test, tc4, 2), memmove(origin, tc4, 2));
  ck_assert_str_eq(s21_memmove(test, tc5, 2), memmove(origin, tc5, 2));
  ck_assert_str_eq(s21_memmove(test, tc6, 2), memmove(origin, tc6, 2));
  ck_assert_str_eq(s21_memmove(test, tc7, 2), memmove(origin, tc7, 2));
  ck_assert_str_eq(s21_memmove(test, tc8, 11), memmove(origin, tc8, 11));
  ck_assert_str_eq(s21_memmove(test, tc9, 15), memmove(origin, tc9, 15));
  ck_assert_str_eq(s21_memmove(test, tc10, 40), memmove(origin, tc10, 40));
  ck_assert_str_eq(s21_memmove(test, tc11, 5), memmove(origin, tc11, 5));
  ck_assert_str_eq(s21_memmove(test, t, 19), memmove(origin, o, 19));
  ck_assert_str_eq(s21_memmove(t, test, 19), memmove(o, origin, 19));
}
END_TEST

START_TEST(test_s21_memset) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  ck_assert_str_eq(s21_memset(test, '-', 6), memset(origin, '-', 6));
  ck_assert_str_eq(s21_memset(test, 'X', 2), memset(origin, 'X', 2));
  ck_assert_str_eq(s21_memset(test, ' ', 1), memset(origin, ' ', 1));
  ck_assert_str_eq(s21_memset(test, 0, 0), memset(origin, 0, 0));
  ck_assert_str_eq(s21_memset(test, 'X', 100), memset(origin, 'X', 100));
  ck_assert_str_eq(s21_memset(test, '\0', 1), memset(origin, '\0', 1));
  ck_assert_str_eq(s21_memset(test, 55, 3), memset(origin, 55, 3));
}
END_TEST

START_TEST(test_s21_strcat) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  ck_assert_str_eq(s21_strcat(test, tc5), strcat(origin, tc5));
  ck_assert_str_eq(s21_strcat(test, tc6), strcat(origin, tc6));
  ck_assert_str_eq(s21_strcat(test, tc4), strcat(origin, tc4));
  ck_assert_str_eq(s21_strcat(test, tc3), strcat(origin, tc3));
  ck_assert_str_eq(s21_strcat(test, tc1), strcat(origin, tc1));
  ck_assert_str_eq(s21_strcat(test, tc11), strcat(origin, tc11));
  ck_assert_str_eq(s21_strcat(test, tc13), strcat(origin, tc13));
}
END_TEST

START_TEST(test_s21_strncat) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  ck_assert_str_eq(s21_strncat(test, tc9, s21_strlen(tc9)),
                   strncat(origin, tc9, s21_strlen(tc9)));
  ck_assert_str_eq(s21_strncat(test, tc6, 0), strncat(origin, tc6, 0));
  ck_assert_str_eq(s21_strncat(test, tc4, 1), strncat(origin, tc4, 1));
  ck_assert_str_eq(s21_strncat(test, tc2, 100), strncat(origin, tc2, 100));
  ck_assert_str_eq(s21_strncat(test, tc11, 10), strncat(origin, tc11, 10));
  ck_assert_str_eq(s21_strncat(test, tc13, 10), strncat(origin, tc13, 10));
}
END_TEST

START_TEST(test_s21_strchr) {
  ck_assert_str_eq(s21_strchr(tc1, ' '), strchr(tc1, ' '));
  ck_assert_ptr_eq(s21_strchr(tc2, 'X'), strchr(tc2, 'X'));
  ck_assert_str_eq(s21_strchr(tc3, '\n'), strchr(tc3, '\n'));
  ck_assert_str_eq(s21_strchr(tc9, 'l'), strchr(tc9, 'l'));
  ck_assert_ptr_eq(s21_strchr(tc7, 1), strchr(tc7, 1));
  ck_assert_str_eq(s21_strchr(tc7, 0), strchr(tc7, 0));
  ck_assert_str_eq(s21_strchr(tc7, '\0'), strchr(tc7, '\0'));
  ck_assert_str_eq(s21_strchr(tc10, '\\'), strchr(tc10, '\\'));
  ck_assert_str_eq(s21_strchr(tc11, '\t'), strchr(tc11, '\t'));
}
END_TEST
#if defined(__APPLE__) || defined(__MACH__)
START_TEST(test_s21_strcmp) {
  ck_assert_int_eq(s21_strcmp(tc1, tc1), strcmp(tc1, tc1));
  ck_assert_int_eq(s21_strcmp(tc2, tc3), strcmp(tc2, tc3));
  ck_assert_int_eq(s21_strcmp(tc5, tc6), strcmp(tc5, tc6));
  ck_assert_int_eq(s21_strcmp(tc8, tc7), strcmp(tc8, tc7));
  ck_assert_int_eq(s21_strcmp(tc10, tc11), strcmp(tc10, tc11));
  ck_assert_int_eq(s21_strcmp(tc12, tc13), strcmp(tc12, tc13));
}
END_TEST

START_TEST(test_s21_strncmp) {
  ck_assert_int_eq(s21_strncmp(tc1, tc1, 0), strncmp(tc1, tc1, 0));
  ck_assert_int_eq(s21_strncmp(tc1, tc1, 1), strncmp(tc1, tc1, 1));
  ck_assert_int_eq(s21_strncmp(tc1, tc1, 100), strncmp(tc1, tc1, 100));
  ck_assert_int_eq(s21_strncmp(tc1, tc2, 0), strncmp(tc1, tc2, 0));
  ck_assert_int_eq(s21_strncmp(tc1, tc2, 1), strncmp(tc1, tc2, 1));
  ck_assert_int_eq(s21_strncmp(tc1, tc2, 100), strncmp(tc1, tc2, 100));
  ck_assert_int_eq(s21_strncmp(tc7, tc9, 0), strncmp(tc7, tc9, 0));
  ck_assert_int_eq(s21_strncmp(tc7, tc9, 1), strncmp(tc7, tc9, 1));
  ck_assert_int_eq(s21_strncmp(tc9, tc7, 0), strncmp(tc9, tc7, 0));
  ck_assert_int_eq(s21_strncmp(tc9, tc7, 1), strncmp(tc9, tc7, 1));
  ck_assert_int_eq(s21_strncmp(tc10, tc11, 10), strncmp(tc10, tc11, 10));
  ck_assert_int_eq(s21_strncmp(tc12, tc13, 10), strncmp(tc12, tc13, 10));
}
END_TEST
#endif
START_TEST(test_s21_strcpy) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  ck_assert_str_eq(s21_strcpy(test, tc5), strcpy(origin, tc5));
  ck_assert_str_eq(s21_strcpy(test, tc6), strcpy(origin, tc6));
  ck_assert_str_eq(s21_strcpy(test, tc4), strcpy(origin, tc4));
  ck_assert_str_eq(s21_strcpy(test, tc1), strcpy(origin, tc1));
  ck_assert_str_eq(s21_strcpy(test, tc7), strcpy(origin, tc7));
  ck_assert_str_eq(s21_strcpy(test, tc9), strcpy(origin, tc9));
  ck_assert_str_eq(s21_strcpy(test, tc8), strcpy(origin, tc8));
  ck_assert_str_eq(s21_strcpy(test, tc11), strcpy(origin, tc11));
  ck_assert_str_eq(s21_strcpy(test, tc13), strcpy(origin, tc13));
}
END_TEST

START_TEST(test_s21_strncpy) {
  char test[MAX] = "S0me text\0";
  char origin[MAX] = "S0me text\0";
  ck_assert_str_eq(s21_strncpy(test, tc1, 1), strncpy(origin, tc1, 1));
  ck_assert_str_eq(s21_strncpy(test, tc1, 100), strncpy(origin, tc1, 100));
  ck_assert_str_eq(s21_strncpy(test, tc2, 1), strncpy(origin, tc2, 1));
  ck_assert_str_eq(s21_strncpy(test, tc2, 100), strncpy(origin, tc2, 100));
  ck_assert_str_eq(s21_strncpy(test, tc8, 1), strncpy(origin, tc8, 1));
  ck_assert_str_eq(s21_strncpy(test, tc11, 10), strncpy(origin, tc11, 10));
  ck_assert_str_eq(s21_strncpy(test, tc13, 10), strncpy(origin, tc13, 10));
}
END_TEST

START_TEST(test_s21_strcspn) {
  ck_assert_int_eq(s21_strcspn(tc1, tc2), strcspn(tc1, tc2));
  ck_assert_int_eq(s21_strcspn(tc2, tc1), strcspn(tc2, tc1));
  ck_assert_int_eq(s21_strcspn(tc1, tc5), strcspn(tc1, tc5));
  ck_assert_int_eq(s21_strcspn(tc5, tc1), strcspn(tc5, tc1));
  ck_assert_int_eq(s21_strcspn(tc2, tc6), strcspn(tc2, tc6));
  ck_assert_int_eq(s21_strcspn(tc6, tc2), strcspn(tc6, tc2));
  ck_assert_int_eq(s21_strcspn(tc3, tc4), strcspn(tc3, tc4));
  ck_assert_int_eq(s21_strcspn(tc4, tc3), strcspn(tc4, tc3));
  ck_assert_int_eq(s21_strcspn(tc7, tc8), strcspn(tc7, tc8));
  ck_assert_int_eq(s21_strcspn(tc9, tc7), strcspn(tc9, tc7));
  ck_assert_int_eq(s21_strcspn(tc1, tc8), strcspn(tc1, tc8));
  ck_assert_int_eq(s21_strcspn(tc8, tc1), strcspn(tc8, tc1));
  ck_assert_int_eq(s21_strcspn(tc8, "54"), strcspn(tc8, "54"));
  ck_assert_int_eq(s21_strcspn(tc8, "e"), strcspn(tc8, "e"));
  ck_assert_int_eq(s21_strcspn(tc10, tc11), strcspn(tc10, tc11));
  ck_assert_int_eq(s21_strcspn(tc7, tc7), strcspn(tc7, tc7));
  ck_assert_int_eq(s21_strcspn(tc12, tc13), strcspn(tc12, tc13));
}
END_TEST

START_TEST(test_s21_strerror) {
  for (int i = -10000; i < 10000; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(test_s21_strlen) {
  ck_assert_int_eq(s21_strlen(tc1), strlen(tc1));
  ck_assert_int_eq(s21_strlen(tc2), strlen(tc2));
  ck_assert_int_eq(s21_strlen(tc3), strlen(tc3));
  ck_assert_int_eq(s21_strlen(tc4), strlen(tc4));
  ck_assert_int_eq(s21_strlen(tc5), strlen(tc5));
  ck_assert_int_eq(s21_strlen(tc6), strlen(tc6));
  ck_assert_int_eq(s21_strlen(tc7), strlen(tc7));
  ck_assert_int_eq(s21_strlen(tc8), strlen(tc8));
  ck_assert_int_eq(s21_strlen(tc9), strlen(tc9));
  ck_assert_int_eq(s21_strlen(tc10), strlen(tc10));
  ck_assert_int_eq(s21_strlen(tc11), strlen(tc11));
}
END_TEST

START_TEST(test_s21_strpbrk) {
  ck_assert_str_eq(s21_strpbrk(tc1, tc5), strpbrk(tc1, tc5));
  ck_assert_str_eq(s21_strpbrk(tc5, tc1), strpbrk(tc5, tc1));
  ck_assert_str_eq(s21_strpbrk(tc2, tc6), strpbrk(tc2, tc6));
  ck_assert_str_eq(s21_strpbrk(tc6, tc2), strpbrk(tc6, tc2));
  ck_assert_str_eq(s21_strpbrk(tc3, tc4), strpbrk(tc3, tc4));
  ck_assert_str_eq(s21_strpbrk(tc4, tc3), strpbrk(tc4, tc3));
  ck_assert_ptr_eq(s21_strpbrk(tc7, tc1), strpbrk(tc7, tc1));
  ck_assert_ptr_eq(s21_strpbrk(tc1, tc7), strpbrk(tc1, tc7));
  ck_assert_ptr_eq(s21_strpbrk(tc8, tc9), strpbrk(tc8, tc9));
  ck_assert_ptr_eq(s21_strpbrk(tc9, tc8), strpbrk(tc9, tc8));
  ck_assert_ptr_eq(s21_strpbrk(tc10, tc11), strpbrk(tc10, tc11));
  ck_assert_str_eq(s21_strpbrk(tc12, tc13), strpbrk(tc12, tc13));
}
END_TEST

START_TEST(test_s21_strrchr) {
  ck_assert_ptr_eq(s21_strrchr(tc1, 'e'), strrchr(tc1, 'e'));
  ck_assert_str_eq(s21_strrchr(tc2, ' '), strrchr(tc2, ' '));
  ck_assert_ptr_eq(s21_strrchr(tc2, 'X'), strrchr(tc2, 'X'));
  ck_assert_str_eq(s21_strrchr(tc3, '\n'), strrchr(tc3, '\n'));
  ck_assert_str_eq(s21_strrchr(tc9, 'l'), strrchr(tc9, 'l'));
  ck_assert_ptr_eq(s21_strrchr(tc7, 1), strrchr(tc7, 1));
  ck_assert_str_eq(s21_strrchr(tc7, 0), strrchr(tc7, 0));
  ck_assert_ptr_eq(s21_strrchr(tc10, '\\'), strrchr(tc10, '\\'));
  ck_assert_str_eq(s21_strrchr(tc11, '\t'), strrchr(tc11, '\t'));
  ck_assert_str_eq(s21_strrchr(tc12, ' '), strrchr(tc12, ' '));
  ck_assert_str_eq(s21_strrchr(tc13, ' '), strrchr(tc13, ' '));
}
END_TEST

START_TEST(test_s21_strspn) {
  ck_assert_int_eq(s21_strspn(tc1, tc2), strspn(tc1, tc2));
  ck_assert_int_eq(s21_strspn(tc2, tc1), strspn(tc2, tc1));
  ck_assert_int_eq(s21_strspn(tc2, tc3), strspn(tc2, tc3));
  ck_assert_int_eq(s21_strspn(tc3, tc2), strspn(tc3, tc2));
  ck_assert_int_eq(s21_strspn(tc5, tc6), strspn(tc5, tc6));
  ck_assert_int_eq(s21_strspn(tc6, tc5), strspn(tc6, tc5));
  ck_assert_int_eq(s21_strspn(tc7, tc1), strspn(tc7, tc1));
  ck_assert_int_eq(s21_strspn(tc1, tc7), strspn(tc1, tc7));
  ck_assert_int_eq(s21_strspn(tc8, "123\0"), strspn(tc8, "123\0"));
  ck_assert_int_eq(s21_strspn(tc8, "12sdf34\0"), strspn(tc8, "12sdf34\0"));
  ck_assert_int_eq(s21_strspn(tc8, "ghj\0"), strspn(tc8, "ghj\0"));
  ck_assert_int_eq(s21_strspn(tc8, "09876543210\0"),
                   strspn(tc8, "09876543210\0"));
  ck_assert_int_eq(s21_strspn("12345\0", "5qw4w3qwe2qweqw1\0"),
                   strspn("12345\0", "5qw4w3qwe2qweqw1\0"));
  ck_assert_int_eq(s21_strspn(tc9, tc8), strspn(tc9, tc8));
  ck_assert_int_eq(s21_strspn(tc10, tc11), strspn(tc10, tc11));
  ck_assert_int_eq(s21_strspn(tc12, tc13), strspn(tc12, tc13));
}
END_TEST

START_TEST(test_s21_strstr) {
  ck_assert_str_eq(s21_strstr(tc1, "\0"), strstr(tc1, "\0"));
  ck_assert_str_eq(s21_strstr(tc1, "wo\0"), strstr(tc1, "wo\0"));
  ck_assert_str_eq(s21_strstr(tc2, "\n\0"), strstr(tc2, "\n\0"));
  ck_assert_str_eq(s21_strstr(tc2, ", \0"), strstr(tc2, ", \0"));
  ck_assert_str_eq(s21_strstr(tc5, " \0"), strstr(tc5, " \0"));
  ck_assert_str_eq(s21_strstr(tc6, "\n\0"), strstr(tc6, "\n\0"));
  ck_assert_str_eq(s21_strstr(tc7, "\0"), strstr(tc7, "\0"));
  ck_assert_str_eq(s21_strstr(tc1, "Hello world\0"),
                   strstr(tc1, "Hello world\0"));
  ck_assert_str_eq(s21_strstr(tc8, "234567\0"), strstr(tc8, "234567\0"));
  ck_assert_str_eq(s21_strstr(tc9, "f\0"), strstr(tc9, "f\0"));
  ck_assert_str_eq(s21_strstr(tc10, "\0"), strstr(tc10, "\0"));
  ck_assert_str_eq(s21_strstr(tc11, "\n\f\r\0"), strstr(tc11, "\n\f\r\0"));
  ck_assert_str_eq(s21_strstr("Hell0 Hello Hello\0", "Hello\0"),
                   strstr("Hell0 Hello Hello\0", "Hello\0"));
  ck_assert_ptr_eq(s21_strstr(tc1, "notinstring\0"),
                   strstr(tc1, "notinstring\0"));
  ck_assert_ptr_eq(s21_strstr(tc5, "notinstring\0"),
                   strstr(tc5, "notinstring\0"));
  ck_assert_ptr_eq(s21_strstr(tc7, "notinstring\0"),
                   strstr(tc7, "notinstring\0"));
}
END_TEST

START_TEST(test_s21_strtok) {
  ck_assert_str_eq(s21_strtok(tc1, "wo\0"), strtok(tc1, "wo\0"));
  ck_assert_str_eq(s21_strtok(tc2, "\n\0"), strtok(tc2, "\n\0"));
  ck_assert_ptr_eq(s21_strtok(tc2, ", \0"), strtok(tc2, ", \0"));
  ck_assert_ptr_eq(s21_strtok(tc5, " \0"), strtok(tc5, " \0"));
  ck_assert_ptr_eq(s21_strtok(tc6, "\n\0"), strtok(tc6, "\n\0"));
  ck_assert_ptr_eq(s21_strtok(tc7, "\0"), strtok(tc7, "\0"));
  ck_assert_ptr_eq(s21_strtok(tc1, "Hello world\0"),
                   strtok(tc1, "Hello world\0"));
  ck_assert_str_eq(s21_strtok(tc8, "234567\0"), strtok(tc8, "234567\0"));
  ck_assert_str_eq(s21_strtok(tc9, "f\0"), strtok(tc9, "f\0"));
  ck_assert_str_eq(s21_strtok(tc10, "\\\0"), strtok(tc10, "\\\0"));
  ck_assert_str_eq(s21_strtok(tc11, "\t\0"), strtok(tc11, "\t\0"));
  char str[] = "One, two/three, four five.six\0";
  char *s21_token = s21_strtok(str, ",/ .\0");
  char *token = strtok(str, ",/ .\0");
  while (token != s21_NULL) {
    ck_assert_str_eq(s21_token, token);
    s21_token = s21_strtok(s21_NULL, ",/ .\0");
    token = strtok(s21_NULL, ",/ .\0");
  }
}
END_TEST

START_TEST(test_s21_to_upper) {
  t = (char *)s21_to_upper("Hello world\0");
  ck_assert_str_eq(t, "HELLO WORLD\0");
  free(t);
  t = (char *)s21_to_upper("Hi, world\n\0");
  ck_assert_str_eq(t, "HI, WORLD\n\0");
  free(t);
  t = (char *)s21_to_upper("a\n\0");
  ck_assert_str_eq(t, "A\n\0");
  free(t);
  t = (char *)s21_to_upper(" \n\0");
  ck_assert_str_eq(t, " \n\0");
  free(t);
  t = (char *)s21_to_upper(" \0");
  ck_assert_str_eq(t, " \0");
  free(t);
  t = (char *)s21_to_upper("\n\0");
  ck_assert_str_eq(t, "\n\0");
  free(t);
  t = (char *)s21_to_upper("\0");
  ck_assert_str_eq(t, "\0");
  free(t);
  t = (char *)s21_to_upper("aor aA eas zzzZ\0");
  ck_assert_str_eq(t, "AOR AA EAS ZZZZ\0");
  free(t);
  t = (char *)s21_to_upper("Iehgffffgfhgfhgfllo\0");
  ck_assert_str_eq(t, "IEHGFFFFGFHGFHGFLLO\0");
  free(t);
  t = (char *)s21_to_upper("01234567890\0");
  ck_assert_str_eq(t, "01234567890\0");
  free(t);
  t = (char *)s21_to_upper("source\\folder1\\folder2\\filename\0");
  ck_assert_str_eq(t, "SOURCE\\FOLDER1\\FOLDER2\\FILENAME\0");
  free(t);
  t = (char *)s21_to_upper("\n\n\f\r\t\0");
  ck_assert_str_eq(t, "\n\n\f\r\t\0");
  free(t);
  t = (char *)s21_to_upper("aor aA\0 eas zzzZ\0");
  ck_assert_str_eq(t, "AOR AA\0");
  free(t);
  t = (char *)s21_to_upper(s21_NULL);
  ck_assert_ptr_eq(t, s21_NULL);
  free(t);
}
END_TEST

START_TEST(test_s21_to_lower) {
  t = (char *)s21_to_lower("Hello world\0");
  ck_assert_str_eq(t, "hello world");
  free(t);
  t = (char *)s21_to_lower("Hi, world\n\0");
  ck_assert_str_eq(t, "hi, world\n");
  free(t);
  t = (char *)s21_to_lower("a\n\0");
  ck_assert_str_eq(t, "a\n");
  free(t);
  t = (char *)s21_to_lower(" \n\0");
  ck_assert_str_eq(t, " \n");
  free(t);
  t = (char *)s21_to_lower(" \0");
  ck_assert_str_eq(t, " ");
  free(t);
  t = (char *)s21_to_lower("\n\0");
  ck_assert_str_eq(t, "\n");
  free(t);
  t = (char *)s21_to_lower("\0");
  ck_assert_str_eq(t, "");
  free(t);
  t = (char *)s21_to_lower("AOr aA eAS zZZZ");
  ck_assert_str_eq(t, "aor aa eas zzzz");
  free(t);
  t = (char *)s21_to_lower("01234567890\0");
  ck_assert_str_eq(t, "01234567890");
  free(t);
  t = (char *)s21_to_lower("aor aA\0 eas zzzZ");
  ck_assert_str_eq(t, "aor aa");
  free(t);
  t = (char *)s21_to_lower("\n\n\f\r\t\0");
  ck_assert_str_eq(t, "\n\n\f\r\t");
  free(t);
  t = (char *)s21_to_lower(s21_NULL);
  ck_assert_ptr_eq(t, s21_NULL);
  free(t);
}
END_TEST

START_TEST(test_s21_insert) {
  t = (char *)s21_insert("Hello world\0", "Hi, world\n\0", 5);
  ck_assert_str_eq(t, "HelloHi, world\n world\0");
  free(t);
  t = (char *)s21_insert("\0", "Hello world\0", 0);
  ck_assert_str_eq(t, "Hello world\0");
  free(t);
  t = (char *)s21_insert("Hello world\0", "Iehgffffgfhgfhgfllo\0", 5);
  ck_assert_str_eq(t, "HelloIehgffffgfhgfhgfllo world\0");
  free(t);
  t = (char *)s21_insert(" \0", "01234567890\0", 1);
  ck_assert_str_eq(t, " 01234567890");
  free(t);
  t = (char *)s21_insert("source\\folder1\\folder2\\filename\0", "\n\n\f\r\t\0",
                         8);
  ck_assert_str_eq(t, "source\\f\n\n\f\r\tolder1\\folder2\\filename");
  free(t);
  t = (char *)s21_insert("      \0", "    world    ", 5);
  ck_assert_str_eq(t, "         world     ");
  free(t);
}
END_TEST

START_TEST(test_s21_trim) {
  t = (char *)s21_trim(" \n\v\rHello world\t\f\0", s21_NULL);
  ck_assert_str_eq(t, "Hello world\0");
  free(t);
  t = (char *)s21_trim("Hello world\0", "Hd \0");
  ck_assert_str_eq(t, "ello worl\0");
  free(t);
  t = (char *)s21_trim("Hello world\0", "abc\0");
  ck_assert_str_eq(t, "Hello world");
  free(t);
  t = (char *)s21_trim("Hello world\0", "\0");
  ck_assert_str_eq(t, "Hello world\0");
  free(t);
  t = (char *)s21_trim("Hi, world\n\0", "Hi, \n\0");
  char *tmp = {"world\0"};
  ck_assert_str_eq(t, tmp);
  free(t);
  t = (char *)s21_trim("Hi, world\0", "ld");
  ck_assert_str_eq(t, "Hi, wor\0");
  free(t);
  t = (char *)s21_trim("a\n\0", "abc \0");
  ck_assert_str_eq(t, "\n\0");
  free(t);
  t = (char *)s21_trim(" \n\0", "abc \0");
  ck_assert_str_eq(t, "\n\0");
  free(t);
  t = (char *)s21_trim(" \n\0", "\0");
  ck_assert_str_eq(t, "\0");
  free(t);
  t = (char *)s21_trim(" \0", "abc \0");
  ck_assert_str_eq(t, "\0");
  free(t);
  t = (char *)s21_trim("\n\0", "\n\0");
  ck_assert_str_eq(t, "\0");
  free(t);
  t = (char *)s21_trim("    world    \0", " \0");
  ck_assert_str_eq(t, "world\0");
  free(t);
  t = (char *)s21_trim("    world    \0", "\0");
  ck_assert_str_eq(t, "world\0");
  free(t);
  t = (char *)s21_trim("    world    \0", s21_NULL);
  ck_assert_str_eq(t, "world\0");
  free(t);
  t = (char *)s21_trim("abc\0", s21_NULL);
  ck_assert_str_eq(t, "abc\0");
  free(t);
  t = (char *)s21_trim(s21_NULL, s21_NULL);
  ck_assert_ptr_eq(t, s21_NULL);
  free(t);
  t = (char *)s21_trim("\0", s21_NULL);
  ck_assert_str_eq(t, "\0");
  free(t);
  t = (char *)s21_trim("\0", "\0");
  ck_assert_str_eq(t, "\0");
  free(t);
}
END_TEST

START_TEST(test_s21_sprintf_s) {
  ck_assert_int_eq(s21_sprintf(test, "Hello"), sprintf(origin, "Hello"));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "Hello"), sprintf(origin, "Hello"));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "Hello %s", "world!"),
                   sprintf(origin, "Hello %s", "world!"));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%.1000s-END", tc1),
                   sprintf(origin, "BEGIN-%.1000s-END", tc1));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%.5s-END", tc1),
                   sprintf(origin, "BEGIN-%.5s-END", tc1));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%.0s-END", tc1),
                   sprintf(origin, "BEGIN-%.0s-END", tc1));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%.1000s-END", tc7),
                   sprintf(origin, "BEGIN-%.1000s-END", tc7));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B_%200s_E", tc2),
                   sprintf(origin, "B_%200s_E", tc2));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B_%200s_E", tc7),
                   sprintf(origin, "B_%200s_E", tc7));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(
      s21_sprintf(test, "B#@/*&%-100s-M-%-100s-#@/*&E", tc12, tc10),
      sprintf(origin, "B#@/*&%-100s-M-%-100s-#@/*&E", tc12, tc10));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-100s", tc7),
                   sprintf(origin, "%-100s", tc7));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-100.100s", tc10),
                   sprintf(origin, "%-100.100s", tc10));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-100.100s", tc7),
                   sprintf(origin, "%-100.100s", tc7));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(
      s21_sprintf(test, "%1s%2s%3s%4s%5s%6c", tc1, tc2, tc3, tc4, tc5, '!'),
      sprintf(origin, "%1s%2s%3s%4s%5s%6c", tc1, tc2, tc3, tc4, tc5, '!'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);
}
END_TEST

START_TEST(test_s21_sprintf_c) {
  ck_assert_int_eq(s21_sprintf(test, "Ok == %1c%c", 'O', 'k'),
                   sprintf(origin, "Ok == %1c%c", 'O', 'k'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "Ok == %1c %c", 'O', 'k'),
                   sprintf(origin, "Ok == %1c %c", 'O', 'k'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "Ok != %2c %5c", 'O', 'k'),
                   sprintf(origin, "Ok != %2c %5c", 'O', 'k'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%10c-MIDDLE-%2c-END", 'M', 'e'),
                   sprintf(origin, "BEGIN-%10c-MIDDLE-%2c-END", 'M', 'e'));
  ck_assert_str_eq(test, origin);
  string_reset(origin, test);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%100c %2c-END", 10, 20),
                   sprintf(origin, "BEGIN-%100c %2c-END", 10, 20));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200c", 10),
                   sprintf(origin, "%200c", 10));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "BEGIN-%-1c-MIDDLE%-c-END", 10, 20),
                   sprintf(origin, "BEGIN-%-1c-MIDDLE%-c-END", 10, 20));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-200c %-20c-E", 'H', 'z'),
                   sprintf(origin, "B-%-200c %-20c-E", 'H', 'z'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(
      s21_sprintf(test, "B-%1c%2c%3c%4c%5c%6c%7c%8c%9c%10c%11c%12c-E", 'H', 'e',
                  'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd'),
      sprintf(origin, "B-%1c%2c%3c%4c%5c%6c%7c%8c%9c%10c%11c%12c-E", 'H', 'e',
              'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "Ok == %1c%c", 'O', 'k'),
                   sprintf(origin, "Ok == %1c%c", 'O', 'k'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
  ck_assert_int_eq(s21_sprintf(test, "B-%%-E"), sprintf(origin, "B-%%-E"));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%%-M-%%-E"),
                   sprintf(origin, "B-%%-M-%%-E"));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%% %c%%-E", '%'),
                   sprintf(origin, "B-%% %c%%-E", '%'));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"),
                   sprintf(origin, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);
}
END_TEST

START_TEST(test_s21_sprintf_f) {
  ck_assert_int_eq(s21_sprintf(test, "%f", 100000.0000005),
                   sprintf(origin, "%f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%f", -100000.0000005),
                   sprintf(origin, "%f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%f", 0.0000001),
                   sprintf(origin, "%f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%f", -0.0000001),
                   sprintf(origin, "%f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%f", 1.0000001),
                   sprintf(origin, "%f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%f", -1.0000001),
                   sprintf(origin, "%f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+015f", 100000.0000005),
                   sprintf(origin, "%+015f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+015f", -100000.0000005),
                   sprintf(origin, "%+015f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+015f", 0.0000001),
                   sprintf(origin, "%+015f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+015f", -0.0000001),
                   sprintf(origin, "%+015f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+015f", 1.0000001),
                   sprintf(origin, "%+015f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+015f", -1.0000001),
                   sprintf(origin, "%+015f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0f", 100000.0000005),
                   sprintf(origin, "%.0f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0f", -100000.0000005),
                   sprintf(origin, "%.0f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0f", 0.0000001),
                   sprintf(origin, "%.0f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0f", -0.0000001),
                   sprintf(origin, "%.0f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0f", 1.0000001),
                   sprintf(origin, "%.0f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0f", -1.0000001),
                   sprintf(origin, "%.0f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0f", 100000.0000005),
                   sprintf(origin, "%0f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0f", -100000.0000005),
                   sprintf(origin, "%0f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0f", 0.0000001),
                   sprintf(origin, "%0f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0f", -0.0000001),
                   sprintf(origin, "%0f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0f", 1.0000001),
                   sprintf(origin, "%0f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0f", -1.0000001),
                   sprintf(origin, "%0f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200f", 100000.0000005),
                   sprintf(origin, "%200f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200f", -100000.0000005),
                   sprintf(origin, "%200f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200f", 0.0000001),
                   sprintf(origin, "%200f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200f", -0.0000001),
                   sprintf(origin, "%200f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200f", 1.0000001),
                   sprintf(origin, "%200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200f", -1.0000001),
                   sprintf(origin, "%200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200f", 100000.0000005),
                   sprintf(origin, "%0200f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200f", -100000.0000005),
                   sprintf(origin, "%0200f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200f", 0.0000001),
                   sprintf(origin, "%0200f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200f", -0.0000001),
                   sprintf(origin, "%0200f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200f", 1.0000001),
                   sprintf(origin, "%0200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200f", -1.0000001),
                   sprintf(origin, "%0200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+f", 100000.0000005),
                   sprintf(origin, "%+f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+f", -100000.0000005),
                   sprintf(origin, "%+f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+f", 0.0000001),
                   sprintf(origin, "%+f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+f", -0.0000001),
                   sprintf(origin, "%+f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+f", 1.0000001),
                   sprintf(origin, "%+f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+f", -1.0000001),
                   sprintf(origin, "%+f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200f", 100000.0000005),
                   sprintf(origin, "%-200f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200f", -100000.0000005),
                   sprintf(origin, "%-200f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200f", 0.0000001),
                   sprintf(origin, "%-200f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200f", -0.0000001),
                   sprintf(origin, "%-200f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200f", 1.0000001),
                   sprintf(origin, "%-200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200f", -1.0000001),
                   sprintf(origin, "%-200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200f", 100000.0000005),
                   sprintf(origin, "%-+200f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200f", -100000.0000005),
                   sprintf(origin, "%-+200f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200f", 0.0000001),
                   sprintf(origin, "%-+200f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200f", -0.0000001),
                   sprintf(origin, "%-+200f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200f", 1.0000001),
                   sprintf(origin, "%-+200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200f", -1.0000001),
                   sprintf(origin, "%-+200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+200f", -1.0000001),
                   sprintf(origin, "%+200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+200f", 1.0000001),
                   sprintf(origin, "%+200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%#+200f", 100000.0000005),
                   sprintf(origin, "%#+200f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%#+200f", -100000.0000005),
                   sprintf(origin, "%#+200f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%#+200f", 0.0000001),
                   sprintf(origin, "%#+200f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%#+200f", -0.0000001),
                   sprintf(origin, "%#+200f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%#+200f", 1.0000001),
                   sprintf(origin, "%#+200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%#-+200f", -1.0000001),
                   sprintf(origin, "%#-+200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#+200f-E", -0.5),
                   sprintf(origin, "B-%#+200f-E", -0.5));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200f", 100000.0000005),
                   sprintf(origin, "% 200f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200f", -100000.0000005),
                   sprintf(origin, "% 200f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200f", 0.0000001),
                   sprintf(origin, "% 200f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200f", -0.0000001),
                   sprintf(origin, "% 200f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200f", 1.0000001),
                   sprintf(origin, "% 200f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200f", -1.0000001),
                   sprintf(origin, "% 200f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.f", 100000.0000005),
                   sprintf(origin, "% 200.f", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.f", -100000.0000005),
                   sprintf(origin, "% 200.f", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.f", 0.0000001),
                   sprintf(origin, "% 200.f", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.f", -0.0000001),
                   sprintf(origin, "% 200.f", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.f", 1.0000001),
                   sprintf(origin, "% 200.f", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.f", -1.0000001),
                   sprintf(origin, "% 200.f", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#.0f-E", 100000.0000005),
                   sprintf(origin, "B-%#.0f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#.0f-E", -100000.0000005),
                   sprintf(origin, "B-%#.0f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#.0f-E", 0.0000001),
                   sprintf(origin, "B-%#.0f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#.0f-E", -0.0000001),
                   sprintf(origin, "B-%#.0f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#.0f-E", 1.0000001),
                   sprintf(origin, "B-%#.0f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#.0f-E", -1.0000001),
                   sprintf(origin, "B-%#.0f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+1f-E", 100000.0000005),
                   sprintf(origin, "B-%0+1f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+15f-E", 100000.0000005),
                   sprintf(origin, "B-%0+15f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+15f-E", -100000.0000005),
                   sprintf(origin, "B-%0+15f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+15f-E", 0.0000001),
                   sprintf(origin, "B-%0+15f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+15f-E", -0.0000001),
                   sprintf(origin, "B-%0+15f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+15f-E", 1.0000001),
                   sprintf(origin, "B-%0+15f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+15f-E", -1.0000001),
                   sprintf(origin, "B-%0+15f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% -200.10f-E", 100000.0000005),
                   sprintf(origin, "B-% -200.10f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% -200.10f-E", -100000.0000005),
                   sprintf(origin, "B-% -200.10f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% -200.10f-E", 0.0000001),
                   sprintf(origin, "B-% -200.10f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% -200.10f-E", -0.0000001),
                   sprintf(origin, "B-% -200.10f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% -200.10f-E", 1.0000001),
                   sprintf(origin, "B-% -200.10f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% -200.10f-E", -1.0000001),
                   sprintf(origin, "B-% -200.10f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200.10f-E", 100000.0000005),
                   sprintf(origin, "B-%- 200.10f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200.10f-E", -100000.0000005),
                   sprintf(origin, "B-%- 200.10f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200.10f-E", 0.0000001),
                   sprintf(origin, "B-%- 200.10f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200.10f-E", -0.0000001),
                   sprintf(origin, "B-%- 200.10f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200.10f-E", 1.0000001),
                   sprintf(origin, "B-%- 200.10f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200.10f-E", -1.0000001),
                   sprintf(origin, "B-%- 200.10f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0 200.10f-E", 100000.0000005),
                   sprintf(origin, "B-%0 200.10f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0 200.10f-E", -100000.0000005),
                   sprintf(origin, "B-%0 200.10f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0 200.10f-E", 0.0000001),
                   sprintf(origin, "B-%0 200.10f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0 200.10f-E", -0.0000001),
                   sprintf(origin, "B-%0 200.10f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0 200.10f-E", 1.0000001),
                   sprintf(origin, "B-%0 200.10f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0 200.10f-E", -1.0000001),
                   sprintf(origin, "B-%0 200.10f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% 0200.10f-E", 100000.0000005),
                   sprintf(origin, "B-% 0200.10f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% 0200.10f-E", -100000.0000005),
                   sprintf(origin, "B-% 0200.10f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% 0200.10f-E", 0.0000001),
                   sprintf(origin, "B-% 0200.10f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% 0200.10f-E", -0.0000001),
                   sprintf(origin, "B-% 0200.10f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% 0200.10f-E", 1.0000001),
                   sprintf(origin, "B-% 0200.10f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-% 0200.10f-E", -1.0000001),
                   sprintf(origin, "B-% 0200.10f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%+-200.10f-E", 100000.0000005),
                   sprintf(origin, "B-%+-200.10f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%+-200.10f-E", -100000.0000005),
                   sprintf(origin, "B-%+-200.10f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%+-200.10f-E", 0.0000001),
                   sprintf(origin, "B-%+-200.10f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%+-200.10f-E", -0.0000001),
                   sprintf(origin, "B-%+-200.10f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%+-200.10f-E", 1.0000001),
                   sprintf(origin, "B-%+-200.10f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%+-200.10f-E", -1.0000001),
                   sprintf(origin, "B-%+-200.10f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-+200.10f-E", 100000.0000005),
                   sprintf(origin, "B-%-+200.10f-E", 100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-+200.10f-E", -100000.0000005),
                   sprintf(origin, "B-%-+200.10f-E", -100000.0000005));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-+200.10f-E", 0.0000001),
                   sprintf(origin, "B-%-+200.10f-E", 0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-+200.10f-E", -0.0000001),
                   sprintf(origin, "B-%-+200.10f-E", -0.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-+200.10f-E", 1.0000001),
                   sprintf(origin, "B-%-+200.10f-E", 1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-+200.10f-E", -1.0000001),
                   sprintf(origin, "B-%-+200.10f-E", -1.0000001));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%#+200.10f-M-%0.0f-M-% -200.5f-E", -0.5,
                               -0.00001, 1.9999),
                   sprintf(origin, "B-%#+200.10f-M-%0.0f-M-% -200.5f-E", -0.5,
                           -0.00001, 1.9999));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);
}
END_TEST

START_TEST(test_s21_sprintf_d) {
  ck_assert_int_eq(s21_sprintf(test, "%*.5d", -5, -1),
                   sprintf(origin, "%*.5d", -5, -1));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%*d", 0, 0),
                   sprintf(origin, "%*d", 0, 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%d", 0), sprintf(origin, "%d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%d", INT_MIN),
                   sprintf(origin, "%d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%d", INT_MIN),
                   sprintf(origin, "%d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%d", INT_MAX),
                   sprintf(origin, "%d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% d", 0), sprintf(origin, "% d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% d", INT_MIN),
                   sprintf(origin, "% d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% d", INT_MAX),
                   sprintf(origin, "% d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200d", 0),
                   sprintf(origin, "% 200d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200d", INT_MIN),
                   sprintf(origin, "% 200d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200d", INT_MAX),
                   sprintf(origin, "% 200d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.100d", 0),
                   sprintf(origin, "% 200.100d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.100d", INT_MIN),
                   sprintf(origin, "% 200.100d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.100d", INT_MAX),
                   sprintf(origin, "% 200.100d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0d", 0), sprintf(origin, "%.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.0d", 0),
                   sprintf(origin, "% 200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.0d", INT_MIN),
                   sprintf(origin, "% 200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 200.0d", INT_MAX),
                   sprintf(origin, "% 200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200.0d", 0),
                   sprintf(origin, "%-200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200.0d", INT_MIN),
                   sprintf(origin, "%-200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200.0d", INT_MAX),
                   sprintf(origin, "%-200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+200.0d", 0),
                   sprintf(origin, "%+200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+200.0d", INT_MIN),
                   sprintf(origin, "%+200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+200.0d", INT_MAX),
                   sprintf(origin, "%+200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+0200d", 0),
                   sprintf(origin, "%+0200d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+0200d", INT_MIN),
                   sprintf(origin, "%+0200d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+0200d", INT_MAX),
                   sprintf(origin, "%+0200d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0+200d", 0),
                   sprintf(origin, "%0+200d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0+200d", INT_MIN),
                   sprintf(origin, "%0+200d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0+200d", INT_MAX),
                   sprintf(origin, "%0+200d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%0+10d-E", INT_MIN),
                   sprintf(origin, "B-%0+10d-E", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 0200d", 0),
                   sprintf(origin, "% 0200d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 0200d", INT_MIN),
                   sprintf(origin, "% 0200d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% 0200d", INT_MAX),
                   sprintf(origin, "% 0200d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0 200d", 0),
                   sprintf(origin, "%0 200d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0 200d", INT_MIN),
                   sprintf(origin, "%0 200d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0 200d", INT_MAX),
                   sprintf(origin, "%0 200d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200d", 0),
                   sprintf(origin, "%0200d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200d", INT_MIN),
                   sprintf(origin, "%0200d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200d", INT_MAX),
                   sprintf(origin, "%0200d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0d", 0),
                   sprintf(origin, "%-+200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0d", INT_MIN),
                   sprintf(origin, "%-+200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0d", INT_MAX),
                   sprintf(origin, "%-+200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+-200.0d", 0),
                   sprintf(origin, "%+-200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+-200.0d", INT_MIN),
                   sprintf(origin, "%+-200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%+-200.0d", INT_MAX),
                   sprintf(origin, "%+-200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% -200.0d", 0),
                   sprintf(origin, "% -200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% -200.0d", INT_MIN),
                   sprintf(origin, "% -200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "% -200.0d", INT_MAX),
                   sprintf(origin, "% -200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%- 200.0d", 0),
                   sprintf(origin, "%- 200.0d", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%- 200.0d", INT_MIN),
                   sprintf(origin, "%- 200.0d", INT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%- 200.0d", INT_MAX),
                   sprintf(origin, "%- 200.0d", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200.0ld", LONG_MIN),
                   sprintf(origin, "%-200.0ld", LONG_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0ld", LONG_MAX),
                   sprintf(origin, "%-+200.0ld", LONG_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0hd", 0),
                   sprintf(origin, "%-+200.0hd", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0hd", SHRT_MIN),
                   sprintf(origin, "%-+200.0hd", SHRT_MIN));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-+200.0hd", SHRT_MAX),
                   sprintf(origin, "%-+200.0hd", SHRT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%- 200d-M-%-100.100d-M-%0+200d-E",
                               INT_MIN, 0, INT_MAX),
                   sprintf(origin, "B-%- 200d-M-%-100.100d-M-%0+200d-E",
                           INT_MIN, 0, INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(sprintf(origin, "%10hd", SHRT_MAX + 1),
                   s21_sprintf(test, "%10hd", SHRT_MAX + 1));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);
}
END_TEST

START_TEST(test_s21_sprintf_u) {
  ck_assert_int_eq(s21_sprintf(test, "%u", 0), sprintf(origin, "%u", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%u", INT_MAX),
                   sprintf(origin, "%u", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200u", 0), sprintf(origin, "%200u", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%200u", INT_MAX),
                   sprintf(origin, "%200u", INT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0u", 0), sprintf(origin, "%.0u", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%.0u", UINT_MAX),
                   sprintf(origin, "%.0u", UINT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200.0u", 0),
                   sprintf(origin, "%-200.0u", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%-200.0u", UINT_MAX),
                   sprintf(origin, "%-200.0u", UINT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200u", 0),
                   sprintf(origin, "%0200u", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200u", UINT_MAX),
                   sprintf(origin, "%0200u", UINT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200lu", ULONG_MAX),
                   sprintf(origin, "%0200lu", ULONG_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200hu", 0),
                   sprintf(origin, "%0200hu", 0));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "%0200hu", USHRT_MAX),
                   sprintf(origin, "%0200hu", USHRT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);

  ck_assert_int_eq(s21_sprintf(test, "B-%-200u-M-%-100.100u-M-%0200u-E",
                               UINT_MAX, 0, UINT_MAX),
                   sprintf(origin, "B-%-200u-M-%-100.100u-M-%0200u-E", UINT_MAX,
                           0, UINT_MAX));
  ck_assert_str_eq(test, origin);
  string_reset(test, origin);
}
END_TEST

START_TEST(check_sprintf1) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res =
        sprintf(str, "%c, %d, %i, %u, %f, %e, %g, %o, %x, %s %n", 'W', 46341,
                956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my, "%c, %d, %i, %u, %f, %e, %g, %o, %x, %s %n", 'W', 46341, 956,
        -844, 0.0099, 0.9999, 9.9999, 5648, 4545, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf2) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(
        str,
        "%15c, %15d, %15i, %15u, %15f, %15e, %15g, %15o, %15x, %15p, %15s %n",
        'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545, &point,
        "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my,
        "%15c, %15d, %15i, %15u, %15f, %15e, %15g, %15o, %15x, %15p, %15s %n",
        'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545, &point,
        "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf3) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %015d, %015i, %015u, %015f, %015e, %015g, %015o, "
                      "%015x, %15p, %15s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%15c, %015d, %015i, %015u, %015f, %015e, %015g, "
                             "%015o, %015x, %15p, %15s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf4) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %+015d, %+015i, %015u, %+015f, %+015e, %+015g, "
                      "%015o, %015x, %15p, %15s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%15c, %+015d, %+015i, %015u, %+015f, %+015e, "
                             "%+015g, %015o, %015x, %15p, %15s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf5) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %+15d, %+15i, %15u, %+15f, %+15e, %+15g, %15o, "
                      "%15x, %15p, %15s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%15c, %+15d, %+15i, %15u, %+15f, %+15e, %+15g, "
                             "%15o, %15x, %15p, %15s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf6) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "%c, %d, %i, %u, %#f, %#E, %G, %#o, %#X, %p, %s, %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my, "%c, %d, %i, %u, %#f, %#E, %G, %#o, %#X, %p, %s, %n", 'W',
        46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545, &point, "Hello",
        &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf7) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %15.d, %15.i, %15.u, %15.f, %15e, %15g, %15.o, "
                      "%15.x, %15p, %15.s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%15c, %15.d, %15.i, %15.u, %15.f, %15e, %15g, "
                             "%15.o, %15.x, %15p, %15.s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf8) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %15.1d, %15.1i, %15.1u, %15.1f, %15e, "
                      "%15g,%15.1o, %15.1x, %15p, %15.1s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%15c, %15.1d, %15.1i, %15.1u, %15.1f, %15e, "
                             "%15g,%15.1o, %15.1x, %15p, %15.1s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf9) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %15.3d, %15.3i, %15.3u, %15.3f, %15e, "
                      "%15g,%15.3o, %15.3x, %15p, %15.3s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%15c, %15.3d, %15.3i, %15.3u, %15.3f, %15e, "
                             "%15g,%15.3o, %15.3x, %15p, %15.3s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf10) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%15c, %15.2d, %15.10i, %15.10u, %15.10f, %15.10e, "
                      "%15.10g, %15.10o, %15.10x, %15p, %15.10s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my =
        s21_sprintf(str_my,
                    "%15c, %15.2d, %15.10i, %15.10u, %15.10f, %15.10e, "
                    "%15.10g, %15.10o, %15.10x, %15p, %15.10s %n",
                    'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                    &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf11) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%-15c, %-15d, %-15i, %-15u, %-15f, %-15e, %-15g, %-15o, "
                      "%-15x, %-15p, %-15s %n",
                      'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999, 5648, 4545,
                      &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(str_my,
                             "%-15c, %-15d, %-15i, %-15u, %-15f, %-15e, %-15g, "
                             "%-15o, %-15x, %-15p, %-15s %n",
                             'W', 46341, 956, -844, 0.0099, 0.9999, 9.9999,
                             5648, 4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf12) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str,
                      "%-15c, %-15d, %-15i, %-15u, %-15f, %*e, %-15g,%-15o, "
                      "%-15x, %-15p, %-15s %n",
                      'W', 46341, 956, -844, 0.0099, 15, 0.9999, 9.9999, 5648,
                      4545, &point, "Hello", &point);
    int point_2 = point;
    int res_my =
        s21_sprintf(str_my,
                    "%-15c, %-15d, %-15i, %-15u, %-15f, %*e, %-15g,%-15o, "
                    "%-15x, %-15p, %-15s %n",
                    'W', 46341, 956, -844, 0.0099, 15, 0.9999, 9.9999, 5648,
                    4545, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf13) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res =
        sprintf(str, "%c, %hd, %hi, %lu, %Lf, %Le, %Lg, %lo, %hx, %p, %s %n",
                'W', 46341, 956, -844l, 0.0099l, 0.9999l, 9.9999l, 5648l, 4545,
                &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my, "%c, %hd, %hi, %lu, %Lf, %Le, %Lg, %lo, %hx, %p, %s %n", 'W',
        46341, 956, -844l, 0.0099l, 0.9999l, 9.9999l, 5648l, 4545, &point,
        "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf14) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "%c, %d, %i, %u, %f, %e, %g, %o, %x, %p, %s %n", 'W',
                      0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    int point_2 = point;
    int res_my =
        s21_sprintf(str_my, "%c, %d, %i, %u, %f, %e, %g, %o, %x, %p, %s %n",
                    'W', 0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf15) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res =
        sprintf(str, "%c, %+d, %+i, %u, %+f, %+e, %+g, %ho, %#5x, %p, %s %n",
                'W', 0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my, "%c, %+d, %+i, %u, %+f, %+e, %+g, %ho, %#5x, %p, %s %n", 'W', 0,
        0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf16) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(
        str, "%c, %+.d, %+.i, %.u, %+.f, %+.e, %+g, %.o, %.x, %p, %.s %n", 'W',
        0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my, "%c, %+.d, %+.i, %.u, %+.f, %+.e, %+g, %.o, %.x, %p, %.s %n",
        'W', 0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf17) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(
        str, "%c, %+.d, %+.i, %.u, %+#.f, %+#e, %+g, %#o, %#.x, %p, %.s, %n",
        'W', 0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    int point_2 = point;
    int res_my = s21_sprintf(
        str_my, "%c, %+.d, %+.i, %.u, %+#.f, %+#e, %+g, %#o, %#.x, %p, %.s, %n",
        'W', 0, 0, 0, 0., 1., 0., 1, 0, &point, "Hello", &point);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf18) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "% hd, % hd, % d, % ld", -47385345, -47385345,
                      -47385345, -47385345l);
    int point_2 = point;
    int res_my = s21_sprintf(str_my, "% hd, % hd, % d, % ld", -47385345,
                             -47385345, -47385345, -47385345l);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf19) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "%hd, %hd, %d, %ld", 47385345, 47385345, 47385345,
                      47385345l);
    int point_2 = point;
    int res_my = s21_sprintf(str_my, "%hd, %hd, %d, %ld", 47385345, 47385345,
                             47385345, 47385345l);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf20) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "%hu, %hu, %u, %lu", -47385345, -47385345, -47385345,
                      -47385345l);
    int point_2 = point;
    int res_my = s21_sprintf(str_my, "%hu, %hu, %u, %lu", -47385345, -47385345,
                             -47385345, -47385345l);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf21) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "% f, % f, % e, % Lf, % Lf, % Le",
                      -675849.64636368939, -0.000000000064636368939,
                      -675849.64636368939, -675849.64636368939L,
                      -675849.64636368939L, -675849.64636368939L);
    int point_2 = point;
    int res_my = s21_sprintf(str_my, "% f, % f, % e, % Lf, % Lf, % Le",
                             -675849.64636368939, -0.000000000064636368939,
                             -675849.64636368939, -675849.64636368939L,
                             -675849.64636368939L, -675849.64636368939L);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST

START_TEST(check_sprintf22) {
  {
    char str[1000] = {0};
    char str_my[1000] = {0};
    int point = 9;
    int res = sprintf(str, "%% % hd, % hd, % d, % ld, % ld", 47385345,
                      -47385345, 47385345, 7385345l, -47385345l);
    int point_2 = point;
    int res_my = s21_sprintf(str_my, "%% % hd, % hd, % d, % ld, % ld", 47385345,
                             -47385345, 47385345, 7385345l, -47385345l);
    ck_assert_str_eq(str_my, str);
    ck_assert_int_eq(res_my, res);
    ck_assert_int_eq(point, point_2);
  }
}
END_TEST
START_TEST(simple_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(precise_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(minus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(padding_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_width_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0*d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(star_precision_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_flags_many_ints) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_short_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(flags_another_long_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%0.*ld";
  long val = 8581385185;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(zero_precision_zero_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.0d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(space_flag_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% d";
  int val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(unsigned_val_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_hash) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(octal_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_short) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(hex_one_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(hex_two_longer_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(one_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(string_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(ptr_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(s21_NULL_ptr) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];

//   char *format = "%p";
//   char *ptr = s21_NULL;
//   ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format,
//   ptr));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(string_width_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(n_specifier) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int ret = 0;
  char *format = "Hello, my sexy little aboba abobushka abobina %n";
  ck_assert_int_eq(s21_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(float_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(float_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(e_precision) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char *format = "%.17Le";
//   long double val = 15.35;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(e_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_precision_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_precision_huge_negative) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(e_huge) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_width) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(e_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST
// START_TEST(E_int) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char *format = "%.17LE";
//   long double val = 4134121;
//   ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format,
//   val));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST
START_TEST(all_empty) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'),
                   sprintf(str2, "%c%c%c%c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_string) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i", -0), sprintf(str2, "%i", -0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_int) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%i%i%i%i", -999, 0, 666, -100),
                   sprintf(str2, "%i%i%i%i", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_float) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001),
      sprintf(str2, "%f%f%f%f", -999.666, 0.0001, 666.999, -100.001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_unsigned_dec) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%u%u%u%u", 999, 0, 666, 100),
                   sprintf(str2, "%u%u%u%u", (unsigned)999, (unsigned)0,
                           (unsigned)666, (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_char_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_char_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'),
      sprintf(str2, "%3c%-11c%10c%-2c%c", '\t', '\n', '0', 'S', 's'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(s21_sprintf(str1, "%x", (unsigned)INT32_MIN),
                   sprintf(str2, "%x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%x", INT32_MAX),
                   sprintf(str2, "%x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%X", (unsigned)INT32_MIN),
                   sprintf(str2, "%X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", 0), sprintf(str2, "%x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%X", INT32_MAX),
                   sprintf(str2, "%X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%x%x%x%x%x", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-3x", (unsigned)INT32_MIN),
                   sprintf(str2, "%-3x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", 0), sprintf(str2, "%-3x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-3x", INT32_MAX),
                   sprintf(str2, "%-3x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%13x", (unsigned)INT32_MIN),
                   sprintf(str2, "%13x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", 0), sprintf(str2, "%13x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%13x", INT32_MAX),
                   sprintf(str2, "%13x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_left) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MIN),
                   sprintf(str2, "%-60X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", 0), sprintf(str2, "%-60X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%-60X", INT32_MAX),
                   sprintf(str2, "%-60X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_alignment_right) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%7X", (unsigned)INT32_MIN),
                   sprintf(str2, "%7X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", 0), sprintf(str2, "%7X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%7X", INT32_MAX),
                   sprintf(str2, "%7X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2x%-7x%9x%11x%0x", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_alignment) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  ck_assert_int_eq(
      s21_sprintf(str1, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999),
      sprintf(str2, "%2X%-7X%9X%11X%0X", 12340987, 100, 0, 1, -666999));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MIN),
                   sprintf(str2, "%#x", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", 0), sprintf(str2, "%#x", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#x", INT32_MAX),
                   sprintf(str2, "%#x", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MIN),
                   sprintf(str2, "%#X", (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", 0), sprintf(str2, "%#X", 0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%#X", INT32_MAX),
                   sprintf(str2, "%#X", INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#x%#x%3x%#32x%#-1x", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_hashtag_and_alignm) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0,
                  123213123),
      sprintf(str2, "%#X%#X%3X%#32X%#-1X", 87, 1222224535, -13, -0, 123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MIN),
                   sprintf(str2, "%*x", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, 0),
                   sprintf(str2, "%*x", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*x", 11, INT32_MAX),
                   sprintf(str2, "%*x", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MIN),
                   sprintf(str2, "%*X", 11, (unsigned)INT32_MIN));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, 0),
                   sprintf(str2, "%*X", 11, 0));
  ck_assert_str_eq(str1, str2);

  ck_assert_int_eq(s21_sprintf(str1, "%*X", 11, INT32_MAX),
                   sprintf(str2, "%*X", 11, INT32_MAX));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_width_star_and_align_and_hashtag) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*x%*x%-12x%3x%*x", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*x%*x%-12x%3x%*x", 9, 127312897, -0, -1,
                           199, -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_width_star) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1,
                               199, -123978, 3, -1251),
                   sprintf(str2, "%#*X%*X%-12X%3X%*X", 9, 127312897, 0, -1, 199,
                           -123978, 3, -1251));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6x", 11, 0);
  int b = sprintf(str2, "%*.6x", 11, 0);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  int a = s21_sprintf(str1, "%*.6X", 11, INT32_MIN);
  int b = sprintf(str2, "%*.6X", 11, (unsigned)INT32_MIN);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_lower_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int a = s21_sprintf(
      str1, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x", 3, 126714,
      4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9, 41, -41, 33);
  int b = sprintf(str2, "%#3.*x%#3x%-7.*x%#-1.8x%4.3x%#2.15x%*.*x%*.1x%3x%-1x",
                  3, 126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, 419, 9,
                  41, -41, 33);
  ck_assert_int_eq(a, b);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_many_hex_upper_with_precision_and_other) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(
      s21_sprintf(str1, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X",
                  3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9,
                  41, -41, 33),
      sprintf(str2, "%#3.*X%#3x%-7.*X%#-1.8X%4.3X%#2.15x%*.*X%*.1X%3X%-1X", 3,
              -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41,
              -41, 33));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_lower_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_one_hex_upper_with_length) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%hx", -11),
                   sprintf(str2, "%hx", (unsigned short)-11));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 0),
                   sprintf(str2, "%hx", (unsigned short)0));
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(s21_sprintf(str1, "%hx", 11),
                   sprintf(str2, "%hx", (unsigned short)11));
  ck_assert_str_eq(str1, str2);
  long unsigned int val = INT32_MAX;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", val), sprintf(str2, "%lx", val));
  ck_assert_str_eq(str1, str2);
  long unsigned int v = 0;
  ck_assert_int_eq(s21_sprintf(str1, "%lx", v), sprintf(str2, "%lx", v));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%10ld";

  ck_assert_int_eq(s21_sprintf(str1, format, 1), sprintf(str2, format, 1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.7f";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.123456),
                   sprintf(str2, format, 11.123456));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%li%ld%lu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666666666666, 777, 111),
                   sprintf(str2, format, 666666666666, 777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%hi%hd%hu";

  ck_assert_int_eq(s21_sprintf(str1, format, 666, -777, 111),
                   sprintf(str2, format, 666, -777, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+li%+lu%+d%+lf";

  ck_assert_int_eq(s21_sprintf(str1, format, -123, 321, -5555, -1213.123),
                   sprintf(str2, format, -123, 321, -5555, -1213.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(test_sprintf12) {
//   char str1[BUFF_SIZE];
//   char str2[BUFF_SIZE];
//   char format[] = "%-11.11li%-35.5lu%-3.5ld%33.19Lf";
//   long double k = 333.33213;

//   ck_assert_int_eq(
//       s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k),
//       sprintf(str2, format, 66666666666, 5555555555, 44444444444, k));

//   ck_assert_str_eq(str1, str2);
// }
// END_TEST

START_TEST(test_sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0li% 0.0lu% 0.0ld % 0.0lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% 0.0hi% 0.0hu% 0.0hd % 0.0hf";

  ck_assert_int_eq(s21_sprintf(str1, format, 1, 222, 33333333333, -166513.1232),
                   sprintf(str2, format, 1, 222, 33333333333, -166513.1232));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%+2.1c%+4.2d%+5.4i%+10.2f%+55.55s%+1.1u";

  ck_assert_int_eq(
      s21_sprintf(str1, format, 'f', 21, 42, 666.666,
                  "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11),
      sprintf(str2, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 121.123),
                   sprintf(str2, format, 121.123));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%%"), sprintf(str2, "%%"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  ck_assert_int_eq(s21_sprintf(str1, "%%%%%%%%"), sprintf(str2, "%%%%%%%%"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf28) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  int n1;
  int n2;
  int a = s21_sprintf(str1, "%d%n", 123, &n1);
  int b = sprintf(str2, "%d%n", 123, &n2);

  ck_assert_int_eq(a, b);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf29) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.f";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.111),
                   sprintf(str2, format, 111.111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e";
  double x = 111;
  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e%e%e%e";

  ck_assert_int_eq(s21_sprintf(str1, format, 11.111, 222.2222, 666., -555.125),
                   sprintf(str2, format, 11.111, 222.2222, 666., -555.125));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%Le";
  long double x = 122.1231;

  ck_assert_int_eq(s21_sprintf(str1, format, x), sprintf(str2, format, x));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.10e";

  ck_assert_int_eq(s21_sprintf(str1, format, 111.184314818),
                   sprintf(str2, format, 111.184314818));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.3e%3.2e%lf";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.000111, 111.555, 1.999),
                   sprintf(str2, format, 0.000111, 111.555, 1.999));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.666666),
                   sprintf(str2, format, 0.666666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%E%E%E";

  ck_assert_int_eq(s21_sprintf(str1, format, 0.0000999, 111.9999, 6.666),
                   sprintf(str2, format, 0.0000999, 111.9999, 6.666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%e ABOBA %Lf %Lf %Le";
  long double c = 848181;
  long double a = 0.00000001;
  long double b = 1111111.11;
  ck_assert_int_eq(s21_sprintf(str1, format, 123.123, a, b, c),
                   sprintf(str2, format, 123.123, a, b, c));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf40) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#e Floppa %#E%#f";

  ck_assert_int_eq(s21_sprintf(str1, format, 123.111, 0.0000999, 0.555),
                   sprintf(str2, format, 123.111, 0.0000999, 0.555));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf41) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.Lf";
  long double a = 7.9418438184;

  ck_assert_int_eq(s21_sprintf(str1, format, a), sprintf(str2, format, a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf42) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5p";
  int a = 5;
  ck_assert_int_eq(s21_sprintf(str1, format, &a), sprintf(str2, format, &a));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf43) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5o";

  ck_assert_int_eq(s21_sprintf(str1, format, 12345),
                   sprintf(str2, format, 12345));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf44) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%#5lX";
  long hex = 314818438141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_trailing_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_large) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_small) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_precision_missing) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_many_zeroes_in_front) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_one_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_zero) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_mantiss_flags) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%5.8g";
  double hex = 0.0000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(g_short_no_mantiss) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(LG) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG";
  long double hex = 0.000005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(g_many) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

START_TEST(test_s21_sscanf_sc) {
  char a[40] = {'\0'}, c[40] = {'\0'}, d[40] = {'\0'};
  char b[40] = {'\0'};
  char a2[40] = {'\0'}, c2[40] = {'\0'}, d2[40] = {'\0'};
  char b2[40] = {'\0'};
  const char str[] = "For almost year group smartest mathematicians";
  ck_assert_int_eq(sscanf(str, "%s %s %3c %*s %s", a, b, c, d),
                   s21_sscanf(str, "%s %s %3c %*s %s", a2, b2, c2, d2));
  ck_assert_str_eq(a, a2);
  ck_assert_str_eq(c, c2);
  ck_assert_str_eq(d, d2);
}
END_TEST

START_TEST(test_s21_sscanf_npercent) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "-98765%    -000456000    555    0005 !";
  int r1 = s21_sscanf(str, "%d%% %d %n %d", &a1, &b1, &c1, &d1);
  int r2 = sscanf(str, "%d%% %d %n %d", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_d) {
  int a, a1;
  short b, b1;
  long c, c1, d, d1, e, e1;
  a = b = c = d = 1;
  a1 = b1 = c1 = d1 = 1;
  const char str[] = "-12345 -000456000 111 +0005 666 777";
  ck_assert_int_eq(
      sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a, &b, &c, &d, &e),
      s21_sscanf(str, "%3d %hd %ld %*d %ld %2ld", &a1, &b1, &c1, &d1, &e1));
  ck_assert_int_eq(a, a1);
  ck_assert_int_eq(b, b1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(e, e1);
}
END_TEST

START_TEST(test_s21_sscanf_i) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "2525 999 0x1Aa8 -10 !";
  int r1 = sscanf(str, "%i%i%i%i", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%i%i%i%i", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_u) {
  unsigned int a1, b1, a2, b2;
  unsigned short c1, c2;
  unsigned long d1, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "5 0250 -1 -9876 999 !";
  int r1 = sscanf(str, "%*u%u%u%hu%lu", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%*u%u%u%hu%lu", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_o) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "4444 333 5 -10 !";
  int r1 = sscanf(str, "%o%o%o%o", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%o%o%o%o", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_x) {
  int a1, b1, c1, d1, a2, b2, c2, d2;
  a1 = a2 = b1 = b2 = c1 = c2 = d1 = d2 = 1;
  const char str[] = "9876 025 0x5555 -25 !";
  int r1 = sscanf(str, "%x%x%x%x", &a1, &b1, &c1, &d1);
  int r2 = s21_sscanf(str, "%x%x%x%x", &a2, &b2, &c2, &d2);
  ck_assert_int_eq(r1, r2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_s21_sscanf_p) {
  int i = 5;
  int *p1a = &i;
  int *p2a;
  int *p3a;
  char tmp[50] = {'\0'};
  sprintf(tmp, "%p", p1a);
  sscanf(tmp, "%p", &p2a);
  s21_sscanf(tmp, "%p", &p3a);
  ck_assert_ptr_eq(p2a, p3a);
}
END_TEST

START_TEST(test_s21_sscanf_f) {
  float a1, a2;
  ck_assert_int_eq(s21_sscanf("0.00000000000001", "%1f", &a1),
                   sscanf("0.00000000000001", "%1f", &a2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(s21_sscanf("-0.0000000000000000001", "%10f", &a1),
                   sscanf("-0.0000000000000000001", "%10f", &a2));
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_s21_sscanf_e) {
  float a1, a2;
  ck_assert_int_eq(s21_sscanf("-1123.2332", "%10e", &a1),
                   sscanf("-1123.2332", "%10e", &a2));
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(s21_sscanf("-1123.2332", "%10E", &a1),
                   sscanf("-1123.2332", "%10E", &a2));
  ck_assert_int_eq(a1, a2);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite;
  TCase *core;

  suite = suite_create("S21_string");
  core = tcase_create("Core");
  tcase_add_test(core, test_s21_memchr);
  tcase_add_test(core, test_s21_memcmp);
  tcase_add_test(core, test_s21_memcpy);
  tcase_add_test(core, test_s21_memmove);
  tcase_add_test(core, test_s21_memset);
  tcase_add_test(core, test_s21_strcat);
  tcase_add_test(core, test_s21_strncat);
  tcase_add_test(core, test_s21_strchr);
#if defined(__APPLE__) || defined(__MACH__)
  tcase_add_test(core, test_s21_strcmp);
  tcase_add_test(core, test_s21_strncmp);
#endif
  tcase_add_test(core, test_s21_strcpy);
  tcase_add_test(core, test_s21_strncpy);
  tcase_add_test(core, test_s21_strcspn);
  tcase_add_test(core, test_s21_strerror);
  tcase_add_test(core, test_s21_strlen);
  tcase_add_test(core, test_s21_strpbrk);
  tcase_add_test(core, test_s21_strrchr);
  tcase_add_test(core, test_s21_strspn);
  tcase_add_test(core, test_s21_strstr);
  tcase_add_test(core, test_s21_strtok);
  tcase_add_test(core, test_s21_to_upper);
  tcase_add_test(core, test_s21_to_lower);
  tcase_add_test(core, test_s21_insert);
  tcase_add_test(core, test_s21_trim);

  tcase_add_test(core, test_s21_sprintf_s);
  tcase_add_test(core, test_s21_sprintf_c);
  tcase_add_test(core, test_s21_sprintf_percent);
  tcase_add_test(core, test_s21_sprintf_f);
  tcase_add_test(core, test_s21_sprintf_d);
  tcase_add_test(core, test_s21_sprintf_u);
  tcase_add_test(core, check_sprintf1);
  tcase_add_test(core, check_sprintf2);
  tcase_add_test(core, check_sprintf3);
  tcase_add_test(core, check_sprintf4);
  tcase_add_test(core, check_sprintf5);
  tcase_add_test(core, check_sprintf6);
  tcase_add_test(core, check_sprintf7);
  tcase_add_test(core, check_sprintf8);
  tcase_add_test(core, check_sprintf9);
  tcase_add_test(core, check_sprintf10);
  tcase_add_test(core, check_sprintf11);
  tcase_add_test(core, check_sprintf12);
  tcase_add_test(core, check_sprintf13);
  tcase_add_test(core, check_sprintf14);
  tcase_add_test(core, check_sprintf15);
  tcase_add_test(core, check_sprintf16);
  tcase_add_test(core, check_sprintf17);
  tcase_add_test(core, check_sprintf18);
  tcase_add_test(core, check_sprintf19);
  tcase_add_test(core, check_sprintf20);
  tcase_add_test(core, check_sprintf21);
  tcase_add_test(core, check_sprintf22);
  tcase_add_test(core, simple_int);
  tcase_add_test(core, precise_int);
  tcase_add_test(core, width_int);
  tcase_add_test(core, minus_width_int);
  tcase_add_test(core, plus_width_int);
  tcase_add_test(core, padding_int);
  tcase_add_test(core, star_width_int);
  tcase_add_test(core, star_precision_int);
  tcase_add_test(core, many_flags_many_ints);
  tcase_add_test(core, flags_long_int);
  tcase_add_test(core, flags_short_int);
  tcase_add_test(core, flags_another_long_int);
  tcase_add_test(core, zero_precision_zero_int);
  tcase_add_test(core, space_flag_int);
  tcase_add_test(core, unsigned_val);
  tcase_add_test(core, unsigned_val_width);
  tcase_add_test(core, unsigned_val_flags);
  tcase_add_test(core, unsigned_val_precision);
  tcase_add_test(core, unsigned_val_many_flags);
  tcase_add_test(core, unsigned_val_short);
  tcase_add_test(core, unsigned_val_long);
  tcase_add_test(core, unsigned_val_many);
  tcase_add_test(core, octal);
  tcase_add_test(core, octal_width);
  tcase_add_test(core, octal_flags);
  tcase_add_test(core, octal_precision);
  tcase_add_test(core, octal_many_flags);
  tcase_add_test(core, octal_short);
  tcase_add_test(core, octal_long);
  tcase_add_test(core, octal_many);
  tcase_add_test(core, octal_zero);
  tcase_add_test(core, octal_hash);
  tcase_add_test(core, unsigned_zero);
  tcase_add_test(core, hex_width);
  tcase_add_test(core, hex_flags);
  tcase_add_test(core, hex_precision);
  tcase_add_test(core, hex_many);
  tcase_add_test(core, hex_many_flags);
  tcase_add_test(core, hex_zero);
  tcase_add_test(core, hex_huge);
  tcase_add_test(core, hex_short);
  tcase_add_test(core, hex_long);
  tcase_add_test(core, hex_one_longer_width);
  tcase_add_test(core, hex_two_longer_width);
  tcase_add_test(core, one_char);
  tcase_add_test(core, one_precision);
  tcase_add_test(core, one_flags);
  tcase_add_test(core, one_width);
  tcase_add_test(core, one_many);
  tcase_add_test(core, one_many_flags);
  tcase_add_test(core, string);
  tcase_add_test(core, string_precision);
  tcase_add_test(core, string_width);
  tcase_add_test(core, string_flags);
  tcase_add_test(core, string_long);
  tcase_add_test(core, string_many);
  tcase_add_test(core, ptr);
  tcase_add_test(core, ptr_width);
  tcase_add_test(core, ptr_precision);
  // tcase_add_test(core, s21_NULL_ptr);
  tcase_add_test(core, n_specifier);
  tcase_add_test(core, string_width_huge);
  tcase_add_test(core, float_precision);
  tcase_add_test(core, float_width);
  tcase_add_test(core, float_precision_zero);
  tcase_add_test(core, float_precision_empty);
  tcase_add_test(core, float_precision_huge);
  tcase_add_test(core, float_precision_huge_negative);
  tcase_add_test(core, float_huge);
  tcase_add_test(core, float_flags);
  tcase_add_test(core, float_many);
  // tcase_add_test(core, e_precision);
  tcase_add_test(core, e_precision_zero);
  tcase_add_test(core, e_precision_empty);
  tcase_add_test(core, e_precision_huge);
  tcase_add_test(core, e_precision_huge_negative);
  tcase_add_test(core, e_huge);
  tcase_add_test(core, e_many);
  tcase_add_test(core, e_width);
  tcase_add_test(core, e_flags);
  // tcase_add_test(core, E_int);
  tcase_add_test(core, all_empty);
  tcase_add_test(core, empty_format_and_parameters);
  tcase_add_test(core, test_one_char);
  tcase_add_test(core, test_many_char);
  tcase_add_test(core, test_one_string);
  tcase_add_test(core, test_many_string);
  tcase_add_test(core, test_one_dec);
  tcase_add_test(core, test_many_dec);
  tcase_add_test(core, test_one_int);
  tcase_add_test(core, test_many_int);
  tcase_add_test(core, test_one_float);
  tcase_add_test(core, test_many_float);
  tcase_add_test(core, test_one_unsigned_dec);
  tcase_add_test(core, test_many_unsigned_dec);
  tcase_add_test(core, test_one_char_with_alignment_left);
  tcase_add_test(core, test_one_char_with_alignment_right);
  tcase_add_test(core, test_many_char_with_alignment);
  tcase_add_test(core, test_one_hex_lower);
  tcase_add_test(core, test_one_hex_upper);
  tcase_add_test(core, test_many_hex_lower);
  tcase_add_test(core, test_many_hex_upper);
  tcase_add_test(core, test_one_hex_lower_with_alignment_left);
  tcase_add_test(core, test_one_hex_lower_with_alignment_right);
  tcase_add_test(core, test_one_hex_upper_with_alignment_left);
  tcase_add_test(core, test_one_hex_upper_with_alignment_right);
  tcase_add_test(core, test_many_hex_lower_with_alignment);
  tcase_add_test(core, test_many_hex_upper_with_alignment);
  tcase_add_test(core, test_one_hex_with_hashtag);
  tcase_add_test(core, test_one_hex_upper_with_hashtag);
  tcase_add_test(core, test_many_hex_lower_with_hashtag_and_alignm);
  tcase_add_test(core, test_many_hex_upper_with_hashtag_and_alignm);
  tcase_add_test(core, test_one_hex_lower_with_width_star);
  tcase_add_test(core, test_one_hex_upper_with_width_star);
  tcase_add_test(core,
                 test_many_hex_lower_with_width_star_and_align_and_hashtag);
  tcase_add_test(core, test_many_hex_upper_with_width_star);
  tcase_add_test(core, test_one_hex_lower_with_precision);
  tcase_add_test(core, test_one_hex_upper_with_precision);
  tcase_add_test(core, test_many_hex_lower_with_precision_and_other);
  tcase_add_test(core, test_many_hex_upper_with_precision_and_other);
  tcase_add_test(core, test_one_hex_lower_with_length);
  tcase_add_test(core, test_one_hex_upper_with_length);
  tcase_add_test(core, test_sprintf1);
  tcase_add_test(core, test_sprintf2);
  tcase_add_test(core, test_sprintf3);
  tcase_add_test(core, test_sprintf4);
  tcase_add_test(core, test_sprintf6);
  tcase_add_test(core, test_sprintf7);
  tcase_add_test(core, test_sprintf8);
  tcase_add_test(core, test_sprintf9);
  tcase_add_test(core, test_sprintf10);
  tcase_add_test(core, test_sprintf11);
  // tcase_add_test(core, test_sprintf12);
  tcase_add_test(core, test_sprintf14);
  tcase_add_test(core, test_sprintf15);
  tcase_add_test(core, test_sprintf16);
  tcase_add_test(core, test_sprintf17);
  tcase_add_test(core, test_sprintf18);
  tcase_add_test(core, test_sprintf19);
  tcase_add_test(core, test_sprintf20);
  tcase_add_test(core, test_sprintf24);
  tcase_add_test(core, test_sprintf25);
  tcase_add_test(core, test_sprintf26);
  tcase_add_test(core, test_sprintf27);
  tcase_add_test(core, test_sprintf28);
  tcase_add_test(core, test_sprintf29);
  tcase_add_test(core, test_sprintf30);
  tcase_add_test(core, test_sprintf31);
  tcase_add_test(core, test_sprintf32);
  tcase_add_test(core, test_sprintf33);
  tcase_add_test(core, test_sprintf35);
  tcase_add_test(core, test_sprintf36);
  tcase_add_test(core, test_sprintf37);
  tcase_add_test(core, test_sprintf38);
  tcase_add_test(core, test_sprintf39);
  tcase_add_test(core, test_sprintf40);
  tcase_add_test(core, test_sprintf41);
  tcase_add_test(core, test_sprintf42);
  tcase_add_test(core, test_sprintf43);
  tcase_add_test(core, test_sprintf44);
  tcase_add_test(core, g_trailing_zero);
  tcase_add_test(core, g_large);
  tcase_add_test(core, g_small);
  tcase_add_test(core, g_precision);
  tcase_add_test(core, g_precision_zero);
  tcase_add_test(core, g_precision_missing);
  tcase_add_test(core, g_many_zeroes_in_front);
  tcase_add_test(core, g_one_zero);
  tcase_add_test(core, g_mantiss);
  tcase_add_test(core, g_mantiss_flags);
  tcase_add_test(core, g_short_no_mantiss);
  tcase_add_test(core, LG);
  tcase_add_test(core, g_many);
  tcase_add_test(core, g_zero);
  tcase_add_test(core, width_char);

  tcase_add_test(core, test_s21_sscanf_sc);
  tcase_add_test(core, test_s21_sscanf_npercent);
  tcase_add_test(core, test_s21_sscanf_d);
  tcase_add_test(core, test_s21_sscanf_i);
  tcase_add_test(core, test_s21_sscanf_u);
  tcase_add_test(core, test_s21_sscanf_o);
  tcase_add_test(core, test_s21_sscanf_x);
  tcase_add_test(core, test_s21_sscanf_p);
  tcase_add_test(core, test_s21_sscanf_f);
  tcase_add_test(core, test_s21_sscanf_e);

  suite_add_tcase(suite, core);

  return (suite);
}

int main(void) {
  int failed = 0;
  Suite *suite;

  SRunner *runner;

  suite = s21_string_suite();
  runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
