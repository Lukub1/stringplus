#include "s21_string.h"

/* Выполняет поиск первого вхождения символа c в первых n байтах строки.*/
void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;
  char *s = (char *)str;
  while (n--) {
    if (*s != c) {
      s++;
    } else {
      res = ((void *)s);
    }
  }
  return res;
}

/* Сравнивает первые n байтов str1 и str2.*/
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  s21_size_t i = 0;
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  if (n == 0) {
  } else {
    while (++i < n && *s1 == *s2) {
      s1++;
      s2++;
    }
    res = (*s1 - *s2);
  }
  return res;
}

/* Копирует n символов из src в dest.*/
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  unsigned char *s = (unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }

  return dest;
}

/* Еще одна функция для копирования n символов из src в dest.*/
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char *to = (char *)dest;
  char *from = (char *)src;

  char *tmp = (char *)malloc(sizeof(char) * n);

  if (tmp) {
    s21_memcpy(tmp, from, n);
    s21_memcpy(to, tmp, n);
    free(tmp);
  }
  return dest;
}

/* Копирует символ c в первые n символов строки.*/
void *s21_memset(void *str, int c, s21_size_t n) {
  char *s = (char *)str;
  while (n) {
    *s++ = c;
    n--;
  }
  return str;
}

/* Добавляет строку src в конец строки dest.*/
char *s21_strcat(char *dest, const char *src) {
  int dest_len = s21_strlen(dest);
  int i = 0;

  for (; src[i]; i++) {
    dest[dest_len + i] = src[i];
  }

  dest[dest_len + i] = '\0';

  return dest;
}

/* Добавляет строку src в конец строки dest длиной до n символов.*/
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *c = dest;
  for (c = dest; *c != '\0'; ++c) {
  }
  for (; 0 < n && *src != '\0'; --n) {
    *c++ = *src++;
  }
  *c = '\0';
  return dest;
}

/* Выполняет поиск первого вхождения символа c в строке str.*/
char *s21_strchr(const char *str, int c) {
  char *s = s21_NULL;

  for (s21_size_t i = 0; i <= s21_strlen(str); i++) {
    if (str[i] == c) {
      s = ((char *)str) + i;
      break;
    }
  }

  return s;
}

/* Сравнивает строку str1 со строкой str2.*/
int s21_strcmp(const char *str1, const char *str2) {
  int res = 0;
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  res = *str1 - *str2;
  return res;
}

/* Сравнивает не более первых n байтов str1 и str2.*/
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  const char *end = str1 + n;
  int res = 0;
  for (; res == 0 && str1 != end && (*str1 || *str2);
       res = *(str1++) - *(str2++)) {
  }
  return res;
}

/* Копирует строку, на которую указывает src в dest.*/
char *s21_strcpy(char *dest, const char *src) {
  for (int i = 0; src[i]; i++) {
    dest[i] = src[i];
  }
  dest[s21_strlen(src)] = '\0';
  return dest;
}

/* Копирует до n символов из строки src в dest.*/
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *s = dest;
  for (; 0 < n && *src != '\0'; --n) {
    *s++ = *src++;
  }
  for (; 0 < n; --n) {
    *s++ = '\0';
  }
  return dest;
}

/* Вычисляет длину начального сегмента str1, который полностью состоит из
 символов, не входящих в str2.*/
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  const char *s1 = str1;
  const char *s2 = str2;
  s21_size_t flg = 0;
  for (s1 = str1; *s1 != '\0'; ++s1) {
    for (s2 = str2; *s2 != '\0'; ++s2) {
      if (*s1 == *s2) {
        flg = 1;
        break;
      }
    }
    if (flg) break;
  }
  return s1 - str1;
}

/* Добавляет целое число n к строке str.*/
void s21_itoa(char *str, long int n) {
  long unsigned int rank = 1;
  char *res = (char *)str;
  long int cnt = n;
  if (n < 0) {
    n *= -1;
  }
  while (cnt != 0) {
    cnt /= 10;
    rank *= 10;
  }
  while (rank / 10 != 0) {
    rank /= 10;
    *res = '0' + n / rank;
    n %= rank;
    res++;
  }
  *res = '\0';
}

/* Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
указатель на строку с сообщением об ошибке. Нужно объявить макросы,
содержащие массивы сообщений об ошибке для операционных систем mac и linux.
Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
осуществляется с помощью директив.*/
char *s21_strerror(int errnum) {
  char num[20] = {'\0'};
  char prefix[40] = PREFIX;
  S21_ERRORS;
  static char res[100] = "";
  if (errnum > LMAX - 1 || errnum < 0) {
    if (errnum < 0) {
      s21_strncat(prefix, "-", 1);
    }
    s21_itoa(num, errnum);
    s21_strcat(prefix, num);
    s21_strcpy(res, prefix);
  } else {
    s21_strcpy(res, s21_errors[errnum]);
  }

  return res;
}

/* Вычисляет длину строки str, не включая завершающий нулевой символ.*/
s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str) {
    for (int i = 0; str[i]; i++) {
      len++;
    }
  }
  return len;
}

/* Находит первый символ в строке str1, который соответствует любому символу,
указанному в str2.*/
char *s21_strpbrk(const char *str1, const char *str2) {
  int flg = 0;
  char *res = s21_NULL;
  for (s21_size_t i = 0; str1[i] != '\0' && flg == 0; i++) {
    for (s21_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        flg++;
        res = (char *)str1 + i;
      }
    }
  }
  return res;
}

/* Выполняет поиск последнего вхождения символа c в строке str.*/
char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  int i = s21_strlen(str);
  while (i >= 0) {
    if (str[i] == (char)c) {
      res = ((char *)(str + i));
      i = 0;
    }
    i--;
  }
  return res;
}

/* Вычисляет длину начального сегмента str1, который полностью состоит из
символов str2.*/
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  const char *s = str2;
  for (res = 0; *str1; str1++, res++) {
    for (s = str2; *s && *s != *str1; s++) {
    }
    if (!*s) break;
  }
  return res;
}

/* Находит первое вхождение всей строки needle (не включая завершающий нулевой
символ), которая появляется в строке haystack.*/
char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t len1 = s21_strlen(haystack);
  s21_size_t len2 = s21_strlen(needle);
  s21_size_t flg = 1;
  char *res = s21_NULL;
  if (!len2) {
    res = (char *)haystack;
    flg = 0;
  }
  while (len1 >= len2 && flg) {
    len1--;
    if (!s21_memcmp(haystack, needle, len2)) {
      res = (char *)haystack;
      flg = 0;
    }
    if (flg) haystack++;
  }
  return res;
}

/* Разбивает строку str на ряд токенов, разделенных delim.*/
char *s21_strtok(char *str, const char *delim) {
  char *b = 0, *e = 0;
  static char *s = "";

  b = str ? str : s;
  b += s21_strspn(b, delim);
  if (*b != '\0') {
    e = b + s21_strcspn(b, delim);
    if (*e != '\0') *e++ = '\0';
    s = e;

  } else {
    b = s21_NULL;
  }

  return b;
}

/* Возвращает копию строки (str), преобразованной в верхний регистр. В случае
какой-либо ошибки следует вернуть значение NULL.*/
void *s21_to_upper(const char *str) {
  char *res = s21_NULL;
  s21_size_t cnt = 0;
  if (str != s21_NULL) {
    res = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    if (res != s21_NULL) {
      s21_size_t i;
      for (i = 0; i < s21_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          res[i] = str[i] - 32;
        } else {
          res[i] = str[i];
        }
        cnt++;
      }
      res[cnt] = '\0';
    }
  }
  return res;
}

/* Возвращает копию строки (str), преобразованной в нижний регистр. В случае
какой-либо ошибки следует вернуть значение NULL.*/
void *s21_to_lower(const char *str) {
  char *res = s21_NULL;
  s21_size_t cnt = 0;
  if (str != s21_NULL) {
    res = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    if (res != s21_NULL) {
      s21_size_t i;
      for (i = 0; i < s21_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          res[i] = str[i] + 32;
        } else {
          res[i] = str[i];
        }
        cnt++;
      }
      res[cnt] = '\0';
    }
  }
  return res;
}

/* Возвращает новую строку, в которой указанная строка (str) вставлена в
указанную позицию (start_index) в данной строке (src). В случае какой-либо
ошибки следует вернуть значение NULL.*/
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  if (src != s21_NULL && str != s21_NULL && start_index <= s21_strlen(src)) {
    s21_size_t length = s21_strlen(str) + s21_strlen(src);
    res = (char *)calloc(length + 1, sizeof(char));
    if (res != s21_NULL) {
      s21_size_t i, j;
      for (i = 0; i < start_index; i++) {
        res[i] = src[i];
      }
      for (i = start_index, j = 0; i < (start_index + s21_strlen(str));
           i++, j++) {
        res[i] = str[j];
      }
      for (i = (start_index + s21_strlen(str)), j = start_index; i < length;
           i++, j++) {
        res[i] = src[j];
      }
      res[i] = '\0';
    }
  }
  return res;
}

/* Возвращает новую строку, в которой удаляются все начальные и конечные
вхождения набора заданных символов (trim_chars) из данной строки (src). В
случае какой-либо ошибки следует вернуть значение NULL.*/
void *s21_trim(const char *src, const char *trim_chars) {
  char *res = 0;
  if (src != s21_NULL) {
    if (!s21_strlen(src)) {
      res = (char *)calloc(1, sizeof(char));
      res[0] = '\0';
    } else {
      if (!trim_chars || !trim_chars[0] || trim_chars == s21_NULL) {
        trim_chars = BLANKS;
      }
      s21_size_t start = 0, end, i, j = 0;
      while (src[start] && s21_strchr(trim_chars, src[start])) {
        start++;
      }
      end = s21_strlen(src) - 1;
      while (end > start && s21_strchr(trim_chars, src[end])) {
        end--;
      }
      res = (char *)calloc((end - start + 2), sizeof(char));
      if (res != s21_NULL) {
        for (i = start; j < end - start + 1; i++, j++) {
          res[j] = src[i];
        }
      }
      res[j] = '\0';
    }
  } else {
    res = s21_NULL;
  }
  return res;
}

/* Отправляет форматированный вывод в строку, на которую указывает str.*/
int s21_sprintf(char *str, const char *format, ...) {
  flags f = {0};
  va_list va;
  va_start(va, format);
  char *str_beginning = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&f, 0, sizeof(flags));
    }

    format = get_flags(format, &f);
    format = get_width(format, &f, va);
    format = get_precision(format, &f, va);
    format = get_length(format, &f);

    f.specifier = *format;
    format++;

    char buff[BUFF_SIZE] = {'\0'};
    handle_value(f, buff, va);
    for (int i = 0; buff[i]; i++, str++) *str = buff[i];

    if (f.specifier == 'n') {
      int *ret = va_arg(va, int *);
      *ret = str - str_beginning;
    }
  }

  *str = '\0';
  va_end(va);
  return str - str_beginning;
}

/* Считывает переданные флаги в структуру.*/
const char *get_flags(const char *format, flags *f) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '0' ||
         *format == '#') {
    switch (*format) {
      case '0':
        f->zero = true;
        break;
      case '-':
        f->minus = true;
        break;
      case '+':
        f->plus = true;
        break;
      case ' ':
        f->space = true;
        break;
      case '#':
        f->hash = true;
        break;
    }
    format++;
  }
  return format;
}

/* Считывает значение ширины в структуру.*/
const char *get_width(const char *format, flags *f, va_list va) {
  if (*format == '*') {
    format++;
    f->width = va_arg(va, int);
  } else if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
    f->width = s21_atoi(tmp);
  }
  return format;
}

/* Считывает значение точности в структуру.*/
const char *get_precision(const char *format, flags *f, va_list va) {
  if (*format == '.') {
    f->is_precision_set = true;
    format++;
  }
  if (*format == '*') {
    format++;
    f->precision = va_arg(va, int);
  }
  if (s21_isdigit(*format)) {
    char tmp[BUFF_SIZE] = {'\0'};
    for (int i = 0; s21_isdigit(*format); i++, format++) tmp[i] = *format;
    f->precision = s21_atoi(tmp);
  }
  return format;
}

/* Считывает значение длины в структуру.*/
const char *get_length(const char *format, flags *f) {
  switch (*format) {
    case 'h':
      f->length = 'h';
      format++;
      break;
    case 'l':
      f->length = 'l';
      format++;
      break;
    case 'L':
      f->length = 'L';
      format++;
  }
  return format;
}

/* Вызывает оработчик в соответствии со спецификатором.*/
void handle_value(flags f, char *buff, va_list va) {
  if (f.specifier == 'd' || f.specifier == 'i')
    parse_int(f, buff, va);
  else if (f.specifier == 'u')
    parse_unsigned(f, buff, va);
  else if (f.specifier == 'o')
    parse_octal(f, buff, va);
  else if (f.specifier == 'x' || f.specifier == 'X')
    parse_hex(f, buff, va);
  else if (f.specifier == '%')
    buff[0] = '%';
  else if (f.specifier == 'c')
    parse_char(f, buff, va);
  else if (f.specifier == 's')
    parse_string(f, buff, va);
  else if (f.specifier == 'p')
    parse_pointer(f, buff, va);
  else if (f.specifier == 'f')
    parse_float(f, buff, va);
  else if (f.specifier == 'e' || f.specifier == 'E')
    parse_mantiss(f, buff, va);
  else if (f.specifier == 'g' || f.specifier == 'G')
    parse_float_g_G(f, buff, va);
  if (f.specifier == 'G' || f.specifier == 'E' || f.specifier == 'X')
    to_upper(buff);
}

/* Считывает целое число из форматной строки.*/
void parse_int(flags f, char *buff, va_list va) {
  int64_t val = va_arg(va, int64_t);
  switch (f.length) {
    case 0:
      val = (int32_t)val;
      break;
    case 'h':
      val = (int16_t)val;
  }
  whole_num_to_string(val, buff, 10);
  format_precision(buff, f);
  format_flags(buff, f);
}

/* Добавляет целое число val по основанию base в массив символов ret.*/
void whole_num_to_string(int64_t val, char *ret, int base) {
  char tmp[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;

  bool neg = val < 0 ? 1 : 0;
  val = neg ? -val : val;

  if (val == 0) tmp[idx] = '0';
  if (val < 0) {
    while (val < 0) {
      idx--;
      tmp[idx] = "0123456789abcdef"[(val % base) * -1];
      val /= base;
    }
  } else {
    while (val > 0) {
      idx--;
      tmp[idx] = "0123456789abcdef"[val % base];
      val /= base;
    }
  }
  for (int j = 0; tmp[idx]; idx++, j++) {
    if (neg && j == 0) {
      ret[j++] = '-';
    }

    ret[j] = tmp[idx];
  }
}

/* Заплонение строки в соответствии с переданным значением точности.*/
void format_precision(char *buff, flags f) {
  char tmp[BUFF_SIZE] = {'\0'};

  int sign = 0;
  int len = s21_strlen(buff);

  if (buff[0] == '-') {
    tmp[0] = '-';
    len--;
    sign = 1;
  }

  if (f.precision > len) {
    int idx;
    for (idx = sign; idx < f.precision - len + sign; idx++) tmp[idx] = '0';

    for (int i = sign; buff[i]; i++, idx++) tmp[idx] = buff[i];

    s21_strcpy(buff, tmp);
  }

  if (f.is_precision_set && f.precision == 0 &&
      check_integer_specifier(f.specifier) && buff[0] == '0')
    buff[0] = '\0';
}

/* Возвращает true если спецификатор относится к целочисленным, иначе false.*/
bool check_integer_specifier(char c) {
  char specs[] = {'d', 'i', 'o', 'u', 'x', 'X'};
  bool res = false;
  for (s21_size_t i = 0; i < sizeof(specs); i++) {
    if (specs[i] == c) {
      res = true;
      break;
    }
  }
  return res;
}

/* Заплонение строки в соответствии с переданными флагами.*/
void format_flags(char *buff, flags f) {
  char tmp[BUFF_SIZE + 1] = {'\0'};
  if (f.plus && f.specifier != 'u') {
    tmp[0] = buff[0] == '-' ? buff[0] : '+';
    s21_strcpy(tmp + 1, buff[0] == '-' ? buff + 1 : buff);
    s21_strcpy(buff, tmp);
  } else if (f.space && !f.zero && buff[0] != '-' && f.specifier != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);

  } else if (f.width && f.zero && f.space && f.specifier != 'u' &&
             buff[0] != '-') {
    tmp[0] = ' ';
  } else if (!f.width && f.zero && f.space && f.specifier != 'u' &&
             buff[0] != '-') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buff);
    s21_strcpy(buff, tmp);
  }
  if (f.width > (int)s21_strlen(buff)) {
    int idx = f.width - s21_strlen(buff);
    if (!f.minus) {
      char tmp2[BUFF_SIZE + 1] = {'\0'};
      if (f.zero && (buff[0] == '-' || buff[0] == '+')) {
        tmp2[0] = buff[0];
        s21_memset(tmp, f.zero ? '0' : ' ', idx);
        s21_strcpy(tmp + idx, buff + 1);
        s21_strcat(tmp2, tmp);
        s21_strcpy(tmp, tmp2);
      } else if (f.zero && f.space && f.specifier != 'u' && buff[0] != '-') {
        s21_memset(tmp2, '0', idx - 1);
        s21_strcat(tmp, tmp2);
        s21_strcat(tmp, buff);
      } else {
        s21_memset(tmp, f.zero ? '0' : ' ', idx);
        s21_strcpy(tmp + idx, buff);
      }
    } else {
      s21_strcpy(tmp, buff);
      s21_memset(tmp + s21_strlen(tmp), ' ', idx);
    }
    s21_strcpy(buff, tmp);
  }
}

/* Добавляет беззнаковое целое число val по основанию base в массив символов
 * ret.*/
void unsigned_num_to_string(uint64_t val, char *ret, int base) {
  char buf[BUFF_SIZE + 1] = {'\0'};
  int idx = BUFF_SIZE - 1;
  if (val == 0) {
    buf[idx] = '0';
    idx--;
  }

  for (; val && idx; --idx, val /= base)
    buf[idx] = "0123456789abcdef"[val % base];
  for (int j = 0; buf[idx + 1]; idx++, j++) ret[j] = buf[idx + 1];
}

/* Считывает беззнаковое целое число из форматной строки.*/
void parse_unsigned(flags f, char *buff, va_list va) {
  uint64_t val = va_arg(va, uint64_t);
  switch (f.length) {
    case 'h':
      val = (uint16_t)val;
      break;
    case 'l':
      val = (uint64_t)val;
      break;
    case 0:
      val = (uint32_t)val;
  }
  unsigned_num_to_string(val, buff, 10);
  format_precision(buff, f);
  format_flags(buff, f);
}

/* Обрабатывает целое число по основанию 8 из форматной строки.*/
void parse_octal(flags f, char *buff, va_list va) {
  buff[0] = '0';
  whole_num_to_string(va_arg(va, int64_t), buff + f.hash, 8);
  format_precision(buff, f);
  format_flags(buff, f);
}

/* Переводит строку в верхний регистр.*/
void to_upper(char *str) {
  while (*str) {
    if (*str >= 'a' && *str <= 'z') *str = *str - 'a' + 'A';
    str++;
  }
}

/* Возвращает true если массив символов состоит из нулей, иначе false.*/
bool is_all_zeroes(char *buff) {
  for (int i = 0; buff[i]; i++)
    if (buff[i] != '0') return false;
  return true;
}

/* Обрабатывает целое число по основанию 16 из форматной строки.*/
void parse_hex(flags f, char *buff, va_list va) {
  uint64_t val = va_arg(va, uint64_t);
  switch (f.length) {
    case 0:
      val = (uint32_t)val;
      break;
    case 'h':
      val = (uint16_t)val;
      break;
    case 'l':
      val = (uint64_t)val;
      break;
  }
  unsigned_num_to_string(val, buff, 16);
  format_precision(buff, f);
  if (f.hash) {
    prepend_ox(buff, f);
  }
  format_flags(buff, f);
}

/* Добавление префикса к числу по основанию 8.*/
void prepend_ox(char *buff, flags f) {
  if (!is_all_zeroes(buff) || f.specifier == 'p') {
    s21_memmove(buff + 2, buff, s21_strlen(buff));
    buff[0] = '0';
    buff[1] = 'x';
  }
}

/* Считывает символ из форматной строки.*/
void parse_char(flags f, char *buff, va_list va) {
  if (f.length == 'l') {
    wchar_t w_c = va_arg(va, wchar_t);
    format_wchar(f, buff, w_c);
  } else {
    char c = va_arg(va, int);
    format_char(f, buff, c);
  }
}

/* Обрабатывает широкие символы.*/
void format_wchar(flags f, char *buff, wchar_t w_c) {
  if (!f.minus && f.width) {
    for (int i = 0; i < f.width; i++) {
      buff[i] = ' ';
      if (i == f.width - 1) wcstombs(buff, &w_c, BUFF_SIZE);
    }
  } else if (f.width) {
    wcstombs(buff, &w_c, BUFF_SIZE);
    for (int i = s21_strlen(buff); i < f.width; i++) buff[i] = ' ';
  } else {
    wcstombs(buff, &w_c, BUFF_SIZE);
  }
}

/* Заплонение строки buff символом c.*/
void format_char(flags f, char *buff, char c) {
  if (!f.minus && f.width) {
    for (int i = 0; i < f.width; i++) {
      buff[i] = ' ';
      if (i == f.width - 1) buff[i] = c;
    }
  } else if (f.width) {
    buff[0] = c;
    for (int i = 1; i < f.width; i++) buff[i] = ' ';
  } else {
    buff[0] = c;
  }
}

/* Считывает строковый массив из форматной строки.*/
void parse_string(flags f, char *buff, va_list va) {
  if (f.length == 'l') {
    wchar_t *wstr = va_arg(va, wchar_t *);
    format_wide_string(f, buff, wstr);
  } else {
    char *str = va_arg(va, char *);
    format_string(f, buff, str);
  }
}

/* Заплонение строки buff строковым массивом str.*/
void format_string(flags f, char *buff, char *str) {
  char tmp[BUFF_SIZE] = {'\0'};
  s21_strcpy(tmp, str);
  if (f.is_precision_set) tmp[f.precision] = '\0';

  int shift = f.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (f.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

/* Обрабатывает троку широких символов.*/
void format_wide_string(flags f, char *buff, wchar_t *wstr) {
  char tmp[BUFF_SIZE] = {'\0'};
  char str[BUFF_SIZE] = {'\0'};

  wcstombs(str, wstr, BUFF_SIZE);
  s21_strcpy(tmp, str);
  if (f.is_precision_set) tmp[f.precision] = '\0';

  int shift = f.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (f.minus && shift > 0) {
    s21_strcpy(buff, tmp);
    s21_memset(buff + len, ' ', shift);
  } else if (shift > 0) {
    s21_memset(buff, ' ', shift);
    s21_strcpy(buff + shift, tmp);
  } else {
    s21_strcpy(buff, tmp);
  }
}

/* Считывает адрес указателя из форматной строки.*/
void parse_pointer(flags f, char *buff, va_list va) {
  unsigned_num_to_string(va_arg(va, uint64_t), buff, 16);
  format_precision(buff, f);
  prepend_ox(buff, f);
  format_flags(buff, f);
}

/* Считывает число с плавающей точкой из форматной строки.*/
void parse_float(flags f, char *buff, va_list va) {
  long double val = 0;
  if (f.length == 'L') {
    val = va_arg(va, long double);
  } else {
    val = va_arg(va, double);
  }

  if (!f.is_precision_set) {
    f.precision = 6;
  }

  double_to_string(val, buff, f);
  format_flags(buff, f);
}

/* Добавляет число с плавающей точкой в массив символов ret.*/
void double_to_string(long double val, char *ret, flags f) {
  char buff[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;
  bool neg = val < 0 ? 1 : 0;
  val = neg ? val * -1 : val;
  long double l = 0, r = modfl(val, &l);
  if (f.precision == 0) {
    l = roundl(val);
    r = 0;
  }
  char fractions[BUFF_SIZE] = {'\0'};
  for (int i = 0; i < f.precision; i++) {
    r = r * 10;
    fractions[i] = (int)r + '0';
  }
  long long right = roundl(r), left = l;
  if (!right) {
    for (int i = 0; i < f.precision; idx--, i++) buff[idx] = '0';
  } else {
    for (int i = s21_strlen(fractions); right || i > 0; right /= 10, idx--, i--)
      buff[idx] = (int)(right % 10 + 0.05) + '0';
  }
  if ((f.is_precision_set && f.precision != 0) || (int)r ||
      (!f.is_precision_set && val == 0) || s21_strlen(fractions) ||
      ((f.is_precision_set && f.hash)))
    buff[idx--] = '.';
  if (!left) {
    buff[idx] = '0';
    idx--;
  } else {
    for (; left; left /= 10, idx--) buff[idx] = (int)(left % 10) + '0';
  }
  for (int i = 0; buff[idx + 1]; idx++, i++) {
    if (neg && i == 0) {
      ret[i] = '-';
      i++;
    }
    ret[i] = buff[idx + 1];
  }
}

/* Считывает дробную часть числа с плавающей точкой из форматной строки.*/
void parse_mantiss(flags f, char *buff, va_list va) {
  long double val = 0;
  if (f.length == 'L') {
    val = va_arg(va, long double);
  } else {
    val = va_arg(va, double);
  }
  int pow = 0;
  char sign = (int)val == 0 ? '-' : '+';

  if ((int)val - val) {
    while ((int)val == 0) {
      pow++;
      val *= 10;
    }
  } else {
    sign = '+';
  }
  while ((int)val / 10 != 0) {
    pow++;
    val /= 10;
  }

  if (!f.is_precision_set) f.precision = 6;
  double_to_string(val, buff, f);
  prepend_mantiss(buff, pow, sign);
  format_flags(buff, f);
}

/* Обрабатывает дробную часть числа с плавающей точкой.*/
void prepend_mantiss(char *str, int pow, char sign) {
  int len = s21_strlen(str);
  str[len] = 'e';
  str[len + 1] = sign;
  str[len + 3] = pow % 10 + '0';
  pow /= 10;
  str[len + 2] = pow % 10 + '0';
  str[len + 4] = '\0';
}

/* Считывает число с плавающей точкой из форматной строки.*/
void parse_float_g_G(flags f, char *buff, va_list va) {
  long double val = 0;
  if (f.length == 'L') {
    val = va_arg(va, long double);
  } else {
    val = va_arg(va, double);
  }

  if (!f.is_precision_set) {
    f.precision = 6;
  }
  if (f.precision == 0) f.precision = 1;
  int precision = f.precision;
  long double m_val = val;
  int pow = 0;
  if ((int)val - val) {
    while ((int)m_val == 0) {
      pow++;
      m_val *= 10;
    }
  }
  if (pow > 4) {
    f.precision = 0;
    double_to_string(m_val, buff, f);
  } else {
    f.precision = 10;
    double_to_string(val, buff, f);
  }
  format_gG_precision(buff, precision);
  if (pow > 4) prepend_mantiss(buff, pow, '-');
  remove_trailing_zeroes(buff);
  format_flags(buff, f);
}

/* Удаляет незначащие нули на конце строки buff.*/
void remove_trailing_zeroes(char *buff) {
  int len = s21_strlen(buff);
  char *dot = s21_strchr(buff, '.');
  if (dot) {
    for (int i = len - 1; buff[i] != '.'; i--) {
      if (buff[i] == '0')
        buff[i] = '\0';
      else
        break;
    }
    if (dot[1] == '\0') dot[0] = '\0';
  }
}

/* Обработка строки с переданным спецификатором G или g.*/
void format_gG_precision(char *buff, int precision) {
  int sig_digs = 0;
  s21_size_t len = s21_strlen(buff);
  int not_zero_found = 0;
  for (s21_size_t i = 0; i < s21_strlen(buff); i++) {
    if ((buff[i] == '0' && !not_zero_found) || buff[i] == '.')
      continue;
    else
      not_zero_found = 1;

    if (s21_isdigit(buff[i]) && not_zero_found) {
      sig_digs++;
    }
    if (sig_digs == precision && i + 1 < len) {
      int next = buff[i + 1] == '.' ? 2 : 1;
      buff[i] = buff[i + next] - '0' > 5 ? (char)(buff[i] + 1) : buff[i];
      buff[i + 1] = '\0';
      break;
    }
  }
}

/* Возвращает целое число, преобразованное из массива символов.*/
int s21_atoi(const char *str) {
  int res = 0;
  int sign = 1;
  int overflow = 0;

  while (*str == ' ') str++;

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && *str >= '0' && *str <= '9') {
    res = res * 10 + (*str - '0');
    if (res < 0) {
      overflow = 1;
      break;
    }
    str++;
  }
  if (overflow)
    res = sign > 0 ? INT32_MAX : INT32_MIN;
  else
    res *= sign;

  return res;
}

/* Возращает 1 если c явлется цифрой, иначе 0.*/
int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }

/* Считывает форматированный ввод из строки.*/
int s21_sscanf(const char *str, const char *format, ...) {
  int count = 0;
  long total_cnt = 0;
  va_list valist;
  va_start(valist, format);
  while (*format) {
    if (*format++ == '%') {
      long local_cnt = 0;
      char specs[] = "csdieEfgGouxXpn%";
      struct args lst = {0, -1, '\0', 0};
      do {
        switch (*format) {
          case '*':
            lst.spot = 1;
            break;
          case '0' ... '9':
            if (lst.width == -1)
              lst.width = (*format - '0');
            else
              lst.width = lst.width * 10 + (*format - '0');
            break;
          case 'h':
          case 'l':
          case 'L':
            lst.mod = *format;
            break;
          case 'd':
            local_cnt += d_processing(valist, str, &lst);
            break;
          case 'c':
            local_cnt += c_processing(valist, str, &lst);
            break;
          case 's':
            local_cnt += s_processing(valist, str, &lst);
            break;
          case 'e':
          case 'E':
          case 'g':
          case 'G':
          case 'f':
            local_cnt += f_processing(valist, str, &lst, &count);
            break;
          case 'u':
            local_cnt += u_processing(valist, str, &lst);
            break;
          case 'o':
            local_cnt += o_processing(valist, str, &lst);
            break;
          case 'X':
          case 'x':
            local_cnt += x_processing(valist, str, &lst);
            break;
          case 'i':
            local_cnt += i_processing(valist, str, &lst);
            break;
          case 'p':
            local_cnt += p_processing(valist, str, &lst);
            break;
          case 'n':
            while (*str == ' ') {
              str++;
              total_cnt++;
            }
            lst.flg = 1;
            d_write(valist, &lst, &total_cnt);
            break;
          case '%':
            while (*str == ' ' || *str == '%') {
              lst.flg = -1;
              total_cnt++;
              str++;
            }
            break;
        }
      } while (s21_strchr(specs, *format++) == s21_NULL);
      if (lst.flg == 0) break;
      if (lst.spot) lst.flg = 0;
      count += lst.flg;
      str += local_cnt;
      total_cnt += local_cnt;
    }
  }
  va_end(valist);
  return count ? count : -1;
}

/* Обрабатывает спецификатор формата p.*/
int p_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  long dec = x_read(str, lst, &len);
  if (lst->spot == 0) {
    void **dest = va_arg(valist, void **);
    *dest = (void *)(0x0 + dec);
  }
  return len;
}

/* Обрабатывает спецификатор формата i.*/
int i_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  while (*str == ' ') {
    str++;
    len++;
  }
  if (*str == '0') {
    str++;
    len++;
    if (*str == 'x') {
      len += x_processing(valist, str, lst);
    } else {
      len += o_processing(valist, str, lst);
    }
  } else if ((*str >= '0' && *str <= '9') || *str == '-' || *str == '+') {
    len += d_processing(valist, str, lst);
  }
  return len;
}

/* Обрабатывает спецификатор формата x.*/
int x_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  long dec = x_read(str, lst, &len);
  if (lst->spot == 0) d_write(valist, lst, &dec);
  return len;
}

/* Обрабатывает 16-ричное число.*/
long x_read(const char *str, struct args *lst, int *len) {
  long dec = 0;
  int sign = 1;
  while (*str == ' ' || *str == '-' || *str == '+' || *str == '0' ||
         *str == 'x') {
    if (*str == '-') sign = -1;
    str++;
    (*len)++;
  }
  char hex_num[50] = {'\0'};
  int i = 0;
  while ((*str && *str != ' ' && *str != '\n' && lst->width--) ||
         ((hex_num[i] >= '0' && hex_num[i] <= '9') ||
          (hex_num[i] >= 'a' && hex_num[i] <= 'f') ||
          (hex_num[i] >= 'A' && hex_num[i] <= 'F'))) {
    (*len)++;
    hex_num[i++] = *str++;
  }
  int length = s21_strlen(hex_num);
  int temp = 0;
  for (i = 0; hex_num[i] != '\0'; i++) {
    if (hex_num[i] >= '0' && hex_num[i] <= '9') {
      temp = hex_num[i] - 48;
      lst->flg = 1;
    } else if (hex_num[i] >= 'a' && hex_num[i] <= 'f') {
      temp = hex_num[i] - 87;
      lst->flg = 1;
    } else if (hex_num[i] >= 'A' && hex_num[i] <= 'F') {
      temp = hex_num[i] - 55;
      lst->flg = 1;
    }
    dec += temp * pow(16, --length);
  }
  return dec *= sign;
}

/* Обрабатывает спецификатор формата o.*/
int o_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  long octal = s21_sscanf_atoi(str, lst, &len);
  long dec = 0;
  while (*str == ' ' || *str == '-' || *str == '+' || *str == '0') str++;
  int i = 0;
  while (octal != 0 && lst->width--) {
    dec = dec + (octal % 10) * pow(8, i++);
    octal = octal / 10;
  }
  if (lst->spot == 0) d_write(valist, lst, &dec);
  return len;
}

/* Обрабатывает спецификатор формата u.*/
int u_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  if (lst->spot == 0) {
    if (lst->mod == '\0') {
      unsigned int *dest = va_arg(valist, unsigned int *);
      long temp = s21_sscanf_atoi(str, lst, &len);
      *dest = (unsigned int)temp;
    } else if (lst->mod == 'h') {
      unsigned short *dest = va_arg(valist, unsigned short *);
      long temp = s21_sscanf_atoi(str, lst, &len);
      *dest = (unsigned short)temp;
    } else if (lst->mod == 'l') {
      unsigned long *dest = va_arg(valist, unsigned long *);
      long temp = s21_sscanf_atoi(str, lst, &len);
      *dest = (unsigned long)temp;
    }
  } else {
    s21_sscanf_atoi(str, lst, &len);
  }
  return len;
}

/* Обрабатывает спецификатор формата e.*/
int e_processing(const char *str, long double *res, int *len,
                 struct args *lst) {
  str++;
  lst->width--;
  int cnt_e = 1;
  int n = s21_sscanf_atoi(str, lst, &cnt_e);
  if (*str == '+' || (*str >= '0' && *str <= '9')) {
    while (n--) *res *= 10.0;
  } else if (*str == '-') {
    while (n++) *res /= 10.0;
  }
  *len += cnt_e;
  return cnt_e;
}

/* Обрабатывает спецификатор формата f.*/
int f_processing(va_list valist, const char *str, struct args *lst,
                 int *gen_cnt) {
  int len = 0;
  long double prev = s21_sscanf_atoi(str, lst, &len);
  long double res = prev;
  int sign = 1;
  const char *str_temp = str;
  while (*str_temp == ' ') str_temp++;
  if (*str_temp == '-') sign = -1;
  str += len;
  switch (*str) {
    case '.':
      str++;
      int after = 0;
      long double middle = s21_sscanf_atoi(str, lst, &after);
      len += after + 1;
      for (int n = after; n > 0; n--) middle /= 10;
      if (!prev && !middle && sign == -1)
        res = -0.0;
      else if (sign == -1)
        res -= middle;
      else
        res += middle;
      str += after;
      break;
    case 'e':
    case 'E':
      if (lst->width == 1) {
        f_write(valist, lst, &res);
        lst->flg = 0;
        (*gen_cnt)++;
        break;
      }
      str += e_processing(str, &res, &len, lst);
      break;
  }
  if (*str == 'e' || *str == 'E') e_processing(str, &res, &len, lst);
  if (lst->spot == 0 && lst->flg) f_write(valist, lst, &res);
  return len;
}

void f_write(va_list valist, struct args *lst, long double *res) {
  if (lst->mod == 'l') {
    double *dest = va_arg(valist, double *);
    *dest = (double)*res;
  } else if (lst->mod == 'L') {
    long double *dest = va_arg(valist, long double *);
    *dest = (long double)*res;
  } else {
    float *dest = va_arg(valist, float *);
    *dest = (float)*res;
  }
}

/* Обрабатывает спецификатор формата s.*/
int s_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  while (*str == ' ' || *str == '\n') {
    str++;
    len++;
  }
  if (lst->spot == 0) {
    if (lst->mod == 'l') {
      wchar_t *dest = va_arg(valist, wchar_t *);
      while (*str && *str != ' ' && *str != '\n' && lst->width--) {
        len++;
        *dest++ = *str++;
        lst->flg = 1;
      }
      *dest = '\0';
    } else {
      char *dest = va_arg(valist, char *);
      while (*str && *str != ' ' && *str != '\n' && lst->width--) {
        len++;
        *dest++ = *str++;
        lst->flg = 1;
      }
      *dest = '\0';
    }
  } else {
    while (*str && *str != ' ' && *str != '\n' && lst->width--) {
      str++;
      len++;
      lst->flg = 1;
    }
  }
  return len;
}

/* Обрабатывает спецификатор формата c.*/
int c_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  if (lst->width > 0) {
    len += s_processing(valist, str, lst);
  } else if (lst->spot == 0) {
    if (lst->mod == 'l') {
      wchar_t *dest = va_arg(valist, wchar_t *);
      *dest = *str;
    } else {
      char *dest = va_arg(valist, char *);
      *dest = *str;
    }
    len++;
    lst->flg = 1;
  }
  return len;
}

/* Обрабатывает спецификатор формата d.*/
int d_processing(va_list valist, const char *str, struct args *lst) {
  int len = 0;
  long res = s21_sscanf_atoi(str, lst, &len);
  if (lst->spot == 0) d_write(valist, lst, &res);
  return len;
}

void d_write(va_list valist, struct args *lst, long int *res) {
  if (lst->mod == '\0') {
    int *dest = va_arg(valist, int *);
    *dest = (int)*res;
  } else if (lst->mod == 'h') {
    short *dest = va_arg(valist, short *);
    *dest = (short)*res;
  } else if (lst->mod == 'l') {
    long *dest = va_arg(valist, long *);
    *dest = (long)*res;
  }
}

/* Считывает целое число из строки str в n.*/
long s21_sscanf_atoi(const char *str, struct args *lst, int *n) {
  long res = 0;
  int sign = 1;
  while (*str == ' ' || *str == '-' || *str == '+') {
    if (*str == '-') {
      sign = -1;
      lst->width--;
    } else if (*str == '+') {
      lst->width--;
    }
    str++;
    (*n)++;
  }
  while (*str >= '0' && *str <= '9' && lst->width--) {
    res = res * 10 + (*str - '0');
    str++;
    (*n)++;
    lst->flg = 1;
  }
  return res * sign;
}
