#include <sys/time.h>


//����ʱ������� whale 2019-9-14 
static char * get_local_time(char *time_str, int len, struct timeval *tv)
{
    struct tm* ptm;
    char time_string[40];
    long milliseconds;
    
    ptm = localtime (&(tv->tv_sec));
 
    /* ��ʽ�����ں�ʱ�䣬��ȷ����Ϊ��λ��*/
    strftime (time_string, sizeof(time_string), "%Y\\%m\\%d %H:%M:%S", ptm); //�����ʽΪ: 2018\12\09 10-52-28.302
 
    /* ��΢�������롣*/
    milliseconds = tv->tv_usec;
 
    /* ����Ϊ��λ��ӡ��ʽ�����ʱ�����ڣ�С�����Ϊ���롣*/
    snprintf (time_str, len, "%s.%06ld", time_string, milliseconds);
 
    return time_str;
}

//��ӡ��ǰʱ�� ��ʽΪ "[2019/09/14 10:43:13.918449]:"
char * print_local_time()
{
	char local_time_str[128];
	char *pTemp = NULL;
    struct timeval tv;

	gettimeofday(&tv, NULL);
    pTemp = get_local_time(local_time_str, sizeof(local_time_str), &tv);
	printf("[%s]:", pTemp);
}