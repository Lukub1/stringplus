#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define s21_NULL (void *)0
typedef unsigned long long s21_size_t;
#define BLANKS " \n\t\r\f\v"
#define BUFF_SIZE 1024

#if defined(__APPLE__) || defined(__MACH__)
#define LMAX 107
#define PREFIX "Unknown error: "
#define S21_ERRORS                                       \
  char s21_errors[LMAX][50] = {                          \
      "Undefined error: 0",                              \
      "Operation not permitted",                         \
      "No such file or directory",                       \
      "No such process",                                 \
      "Interrupted system call",                         \
      "Input/output error",                              \
      "Device not configured",                           \
      "Argument list too long",                          \
      "Exec format error",                               \
      "Bad file descriptor",                             \
      "No child processes",                              \
      "Resource deadlock avoided",                       \
      "Cannot allocate memory",                          \
      "Permission denied",                               \
      "Bad address",                                     \
      "Block device required",                           \
      "Resource busy",                                   \
      "File exists",                                     \
      "Cross-device link",                               \
      "Operation not supported by device",               \
      "Not a directory",                                 \
      "Is a directory",                                  \
      "Invalid argument",                                \
      "Too many open files in system",                   \
      "Too many open files",                             \
      "Inappropriate ioctl for device",                  \
      "Text file busy",                                  \
      "File too large",                                  \
      "No space left on device",                         \
      "Illegal seek",                                    \
      "Read-only file system",                           \
      "Too many links",                                  \
      "Broken pipe",                                     \
      "Numerical argument out of domain",                \
      "Result too large",                                \
      "Resource temporarily unavailable",                \
      "Operation now in progress",                       \
      "Operation already in progress",                   \
      "Socket operation on non-socket",                  \
      "Destination address required",                    \
      "Message too long",                                \
      "Protocol wrong type for socket",                  \
      "Protocol not available",                          \
      "Protocol not supported",                          \
      "Socket type not supported",                       \
      "Operation not supported",                         \
      "Protocol family not supported",                   \
      "Address family not supported by protocol family", \
      "Address already in use",                          \
      "Can't assign requested address",                  \
      "Network is down",                                 \
      "Network is unreachable",                          \
      "Network dropped connection on reset",             \
      "Software caused connection abort",                \
      "Connection reset by peer",                        \
      "No buffer space available",                       \
      "Socket is already connected",                     \
      "Socket is not connected",                         \
      "Can't send after socket shutdown",                \
      "Too many references: can't splice",               \
      "Operation timed out",                             \
      "Connection refused",                              \
      "Too many levels of symbolic links",               \
      "File name too long",                              \
      "Host is down",                                    \
      "No route to host",                                \
      "Directory not empty",                             \
      "Too many processes",                              \
      "Too many users",                                  \
      "Disc quota exceeded",                             \
      "Stale NFS file handle",                           \
      "Too many levels of remote in path",               \
      "RPC struct is bad",                               \
      "RPC version wrong",                               \
      "RPC prog. not avail",                             \
      "Program version wrong",                           \
      "Bad procedure for program",                       \
      "No locks available",                              \
      "Function not implemented",                        \
      "Inappropriate file type or format",               \
      "Authentication error",                            \
      "Need authenticator",                              \
      "Device power is off",                             \
      "Device error",                                    \
      "Value too large to be stored in data type",       \
      "Bad executable (or shared library)",              \
      "Bad CPU type in executable",                      \
      "Shared library version mismatch",                 \
      "Malformed Mach-o file",                           \
      "Operation canceled",                              \
      "Identifier removed",                              \
      "No message of desired type",                      \
      "Illegal byte sequence",                           \
      "Attribute not found",                             \
      "Bad message",                                     \
      "EMULTIHOP (Reserved)",                            \
      "No message available on STREAM",                  \
      "ENOLINK (Reserved)",                              \
      "No STREAM resources",                             \
      "Not a STREAM",                                    \
      "Protocol error",                                  \
      "STREAM ioctl timeout",                            \
      "Operation not supported on socket",               \
      "Policy not found",                                \
      "State not recoverable",                           \
      "Previous owner died",                             \
      "Interface output queue is full"}
#elif defined(__linux__)
#define LMAX 134
#define PREFIX "Unknown error "
#define S21_ERRORS                                         \
  char s21_errors[LMAX][50] = {                            \
      "Success",                                           \
      "Operation not permitted",                           \
      "No such file or directory",                         \
      "No such process",                                   \
      "Interrupted system call",                           \
      "Input/output error",                                \
      "No such device or address",                         \
      "Argument list too long",                            \
      "Exec format error",                                 \
      "Bad file descriptor",                               \
      "No child processes",                                \
      "Resource temporarily unavailable",                  \
      "Cannot allocate memory",                            \
      "Permission denied",                                 \
      "Bad address",                                       \
      "Block device required",                             \
      "Device or resource busy",                           \
      "File exists",                                       \
      "Invalid cross-device link",                         \
      "No such device",                                    \
      "Not a directory",                                   \
      "Is a directory",                                    \
      "Invalid argument",                                  \
      "Too many open files in system",                     \
      "Too many open files",                               \
      "Inappropriate ioctl for device",                    \
      "Text file busy",                                    \
      "File too large",                                    \
      "No space left on device",                           \
      "Illegal seek",                                      \
      "Read-only file system",                             \
      "Too many links",                                    \
      "Broken pipe",                                       \
      "Numerical argument out of domain",                  \
      "Numerical result out of range",                     \
      "Resource deadlock avoided",                         \
      "File name too long",                                \
      "No locks available",                                \
      "Function not implemented",                          \
      "Directory not empty",                               \
      "Too many levels of symbolic links",                 \
      "Unknown error 41",                                  \
      "No message of desired type",                        \
      "Identifier removed",                                \
      "Channel number out of range",                       \
      "Level 2 not synchronized",                          \
      "Level 3 halted",                                    \
      "Level 3 reset",                                     \
      "Link number out of range",                          \
      "Protocol driver not attached",                      \
      "No CSI structure available",                        \
      "Level 2 halted",                                    \
      "Invalid exchange",                                  \
      "Invalid request descriptor",                        \
      "Exchange full",                                     \
      "No anode",                                          \
      "Invalid request code",                              \
      "Invalid slot",                                      \
      "Unknown error 58",                                  \
      "Bad font file format",                              \
      "Device not a stream",                               \
      "No data available",                                 \
      "Timer expired",                                     \
      "Out of streams resources",                          \
      "Machine is not on the network",                     \
      "Package not installed",                             \
      "Object is remote",                                  \
      "Link has been severed",                             \
      "Advertise error",                                   \
      "Srmount error",                                     \
      "Communication error on send",                       \
      "Protocol error",                                    \
      "Multihop attempted",                                \
      "RFS specific error",                                \
      "Bad message",                                       \
      "Value too large for defined data type",             \
      "Name not unique on network",                        \
      "File descriptor in bad state",                      \
      "Remote address changed",                            \
      "Can not access a needed shared library",            \
      "Accessing a corrupted shared library",              \
      ".lib section in a.out corrupted",                   \
      "Attempting to link in too many shared libraries",   \
      "Cannot exec a shared library directly",             \
      "Invalid or incomplete multibyte or wide character", \
      "Interrupted system call should be restarted",       \
      "Streams pipe error",                                \
      "Too many users",                                    \
      "Socket operation on non-socket",                    \
      "Destination address required",                      \
      "Message too long",                                  \
      "Protocol wrong type for socket",                    \
      "Protocol not available",                            \
      "Protocol not supported",                            \
      "Socket type not supported",                         \
      "Operation not supported",                           \
      "Protocol family not supported",                     \
      "Address family not supported by protocol",          \
      "Address already in use",                            \
      "Cannot assign requested address",                   \
      "Network is down",                                   \
      "Network is unreachable",                            \
      "Network dropped connection on reset",               \
      "Software caused connection abort",                  \
      "Connection reset by peer",                          \
      "No buffer space available",                         \
      "Transport endpoint is already connected",           \
      "Transport endpoint is not connected",               \
      "Cannot send after transport endpoint shutdown",     \
      "Too many references: cannot splice",                \
      "Connection timed out",                              \
      "Connection refused",                                \
      "Host is down",                                      \
      "No route to host",                                  \
      "Operation already in progress",                     \
      "Operation now in progress",                         \
      "Stale file handle",                                 \
      "Structure needs cleaning",                          \
      "Not a XENIX named type file",                       \
      "No XENIX semaphores available",                     \
      "Is a named type file",                              \
      "Remote I/O error",                                  \
      "Disk quota exceeded",                               \
      "No medium found",                                   \
      "Wrong medium type",                                 \
      "Operation canceled",                                \
      "Required key not available",                        \
      "Key has expired",                                   \
      "Key has been revoked",                              \
      "Key was rejected by service",                       \
      "Owner died",                                        \
      "State not recoverable",                             \
      "Operation not possible due to RF-kill",             \
      "Memory page has hardware error"}

#endif

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
void s21_itoa(char *str, long int n);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  int precision;
  int is_precision_set;
  int width;
  char length;
  char specifier;
} flags;

int s21_sprintf(char *str, const char *format, ...);
void whole_num_to_string(int64_t val, char *ret, int base);
void unsigned_num_to_string(uint64_t val, char *ret, int base);
bool check_integer_specifier(char c);
bool is_all_zeroes(char *buff);
void to_upper(char *str);
void prepend_ox(char *buff, flags f);
void double_to_string(long double val, char *ret, flags f);
void prepend_mantiss(char *str, int pow, char sign);
void remove_trailing_zeroes(char *buff);

const char *get_flags(const char *format, flags *f);
const char *get_width(const char *format, flags *f, va_list va);
const char *get_precision(const char *format, flags *f, va_list va);
const char *get_length(const char *format, flags *f);

void handle_value(flags f, char *buff, va_list va);
void parse_int(flags, char *buff, va_list va);
void parse_unsigned(flags f, char *buff, va_list va);
void parse_octal(flags f, char *buff, va_list va);
void parse_hex(flags f, char *buff, va_list va);
void parse_char(flags f, char *buff, va_list va);
void parse_string(flags f, char *buff, va_list va);
void parse_pointer(flags f, char *buff, va_list va);
void parse_float(flags f, char *buff, va_list va);
void parse_mantiss(flags f, char *buff, va_list va);
void parse_float_g_G(flags f, char *buff, va_list va);

void format_precision(char *buff, flags f);
void format_flags(char *buff, flags f);
void format_gG_precision(char *buff, int precision);
void format_wchar(flags f, char *buff, wchar_t w_c);
void format_char(flags f, char *buff, char c);
void format_string(flags f, char *buff, char *str);
void format_wide_string(flags f, char *buff, wchar_t *wstr);

int s21_isdigit(char c);
int s21_atoi(const char *str);

int s21_sscanf(const char *str, const char *format, ...);
struct args {
  short spot;
  int width;
  char mod;
  int flg;
};
int d_processing(va_list valist, const char *str, struct args *lst);
int c_processing(va_list valist, const char *str, struct args *lst);
int s_processing(va_list valist, const char *str, struct args *lst);
int f_processing(va_list valist, const char *str, struct args *lst,
                 int *gen_cnt);
void f_write(va_list valist, struct args *lst, long double *res);
void d_write(va_list valist, struct args *lst, long int *res);
int e_processing(const char *str, long double *res, int *len, struct args *lst);
int u_processing(va_list valist, const char *str, struct args *lst);
int o_processing(va_list valist, const char *str, struct args *lst);
int x_processing(va_list valist, const char *str, struct args *lst);
long x_read(const char *str, struct args *lst, int *len);
int i_processing(va_list valist, const char *str, struct args *lst);
int p_processing(va_list valist, const char *str, struct args *lst);
long s21_sscanf_atoi(const char *str, struct args *lst, int *len);

#endif  // SRC_S21_STRING_H_
