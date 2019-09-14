#include <sys/time.h>


//增加时间戳代码 whale 2019-9-14 
static char * get_local_time(char *time_str, int len, struct timeval *tv)
{
    struct tm* ptm;
    char time_string[40];
    long milliseconds;
    
    ptm = localtime (&(tv->tv_sec));
 
    /* 格式化日期和时间，精确到秒为单位。*/
    strftime (time_string, sizeof(time_string), "%Y\\%m\\%d %H:%M:%S", ptm); //输出格式为: 2018\12\09 10-52-28.302
 
    /* 从微秒计算毫秒。*/
    milliseconds = tv->tv_usec;
 
    /* 以秒为单位打印格式化后的时间日期，小数点后为毫秒。*/
    snprintf (time_str, len, "%s.%06ld", time_string, milliseconds);
 
    return time_str;
}

//打印当前时间 格式为 "[2019/09/14 10:43:13.918449]:"
char * print_local_time()
{
	char local_time_str[128];
	char *pTemp = NULL;
    struct timeval tv;

	gettimeofday(&tv, NULL);
    pTemp = get_local_time(local_time_str, sizeof(local_time_str), &tv);
	printf("[%s]:", pTemp);
}