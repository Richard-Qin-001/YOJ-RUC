// On Linux x86-64 Plantform
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;

typedef char int8;
typedef short int16;
typedef int int32;
typedef long long int64;

typedef char *va_list;

#define va_start(ap, last_fixed_arg) (ap = (char *)&(last_fixed_arg) + sizeof(last_fixed_arg))
#define va_arg(ap, type) (*(type *)(ap = (char *)ap + sizeof(type), (char *)ap - sizeof(type)))
#define va_end(ap) ((void)0)

const int64 STDIN_FD = 0;
const int64 STDOUT_FD = 1;
const int64 STDERR_FD = 2;

const int64 SYS_read = 0;
const int64 SYS_write = 1;

void write(int64 fd, const char *buf, uint64 count);
int64 read(int64 fd, char *buf, uint64 count);
char *strcpy(char *s, const char *t);
int strcmp(const char *p, const char *q);
uint strlen(const char *s);
void *memset(void *dst, int c, uint64 n);
char *strchr(const char *s, char c);
int atoi(const char *s);
int64 strtoll(const char *s, char **endptr, int base);


    int printf(const char *__format, ...);
int scanf(const char *__format, ...);

void write(int64 fd, const char *buf, uint64 count)
{
    __asm__ volatile(
        "syscall"
        :
        : "a"(SYS_write),
          "D"(fd),
          "S"(buf),
          "d"(count)
        : "rcx", "r11", "memory");
}
int64 read(int64 fd, char *buf, uint64 count)
{
    int64 ret;
    __asm__ volatile(
        "syscall"
        : "=a"(ret)
        : "a"(SYS_read),
          "D"(fd),
          "S"(buf),
          "d"(count)
        : "rcx", "r11", "memory");

    return ret;
}

char *
strcpy(char *s, const char *t)
{
    char *os;
    os = s;
    while ((*s++ = *t++) != 0)
        ;
    return os;
}

int strcmp(const char *p, const char *q)
{
    while (*p && *p == *q)
        p++, q++;
    return (uchar)*p - (uchar)*q;
}

uint strlen(const char *s)
{
    uint n;

    for (n = 0; s[n]; n++)
        ;
    return n;
}

void *
memset(void *dst, int c, uint64 n)
{
    char *cdst = (char *)dst;
    int i;
    for (i = 0; i < n; i++)
    {
        cdst[i] = c;
    }
    return dst;
}

char *
strchr(const char *s, char c)
{
    for (; *s; s++)
        if (*s == c)
            return (char *)s;
    return 0;
}

int atoi(const char *s)
{
    int n = 0;
    while ('0' <= *s && *s <= '9')
        n = n * 10 + *s++ - '0';
    return n;
}

int64 strtoll(const char *s, char **endptr, int base)
{
    int64 n = 0;
    while ('0' <= *s && *s <= '9')
    {
        n = n * base + *s++ - '0';
    }
    return n;
}
char *
strcat(char *s, const char *t)
{
    char *os = s;
    while (*s != '\0')
    {
        s++;
    }
    while (*t != '\0')
    {
        *s++ = *t++;
    }
    *s = '\0';
    return os;
}

void *
memmove(void *vdst, const void *vsrc, uint64 n)
{
    char *dst;
    const char *src;

    dst = vdst;
    src = vsrc;

    if (src > dst)
    {
        while (n--)
        {
            *dst++ = *src++;
        }
    }
    else
    {
        dst += n;
        src += n;
        while (n-- > 0)
            *--dst = *--src;
    }
    return vdst;
}

int memcmp(const void *s1, const void *s2, int n)
{
    const char *p1 = s1, *p2 = s2;
    while (n--)
    {
        if (*p1 != *p2)
        {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    return 0;
}

void *
memcpy(void *vdst, const void *vsrc, uint n)
{
    return memmove(vdst, vsrc, n);
}

uint64
lltostr(int64 n, char *buf)
{
    char temp[24];
    uint i = 0;
    int is_negative = 0;
    if (n == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }
    if (n < 0)
        is_negative = -1;
    do
    {
        int digit = n % 10;
        if (is_negative)
            digit = -digit;
        temp[i++] = digit + '0';
        n /= 10;
    } while (n != 0);
    if (is_negative)
        temp[i++] = '-';
    uint len = i;
    for (int j = 0; j < len; ++j)
    {
        buf[j] = temp[len - 1 - j];
    }
    buf[len] = '\0';
    return len;
}

int
itostr(int n, char *buf)
{
    char temp[12];
    int i = 0;
    int is_negative = 0;
    if (n == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }
    if (n < 0)
        is_negative = -1;
    do
    {
        int digit = n % 10;
        if (is_negative)
            digit = -digit;
        temp[i++] = digit + '0';
        n /= 10;
    } while (n != 0);
    if (is_negative)
        temp[i++] = '-';
    int len = i;
    for (int j = 0; j < len; j++)
    {
        buf[j] = temp[len - j - 1];
    }
    buf[len] = '\0';
    return len;
}

uint64
utostr(uint32 n, char *buf)
{
    char temp[24];
    uint i = 0;
    if (n == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }
    do
    {
        int digit = n % 10;
        temp[i++] = digit + '0';
        n /= 10;
    } while (n != 0);
    uint len = i;
    for (int j = 0; j < len; ++j)
    {
        buf[j] = temp[len - 1 - j];
    }
    buf[len] = '\0';
    return len;
}

uint64
itohex(uint64 n, char *buf, int uppercase){
    char temp[20];
    int i = 0;
    const char* digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if(n == 0){
        buf[0] = '0';
        buf[1] = '\0';
        return 1;
    }

    do{
        temp[i++] = n % 16;
        n /= 16;
    }while(n != 0);
    uint64 len = i;
    for(int j = 0; j < len; j++){
        buf[j] = temp[len - 1 - j];
    }
    buf[len] = '\0';
    return len;
}

void putc(char c)
{
    write(STDOUT_FD, c, 1);
}

int
printf(const char *__format, ...)
{
    va_list ap;
    const char* p;
    
    va_start(ap, __format);

}

int 
scanf(const char *__format, ...)
{

}

int main()
{

    return 0;
}