//获取libevent支持的方法和当前系统使用的方法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <event2/event.h>

int main()
{
	//获取当前系统支持的方法有哪些
	//const char **event_get_supported_methods(void);
	const char **p = event_get_supported_methods();
	int i = 0;
	while(p[i]!=NULL)
	{
		printf("[%s]  ", p[i++]);
	}
	printf("\n");
	
	//创建event_base结构体
	struct event_base *base = event_base_new();
	if(base==NULL)
	{
		printf("event_base_new error\n");
		return -1;
	}
	
	//const char * event_base_get_method(const struct event_base *base);
	printf("[%s]\n", event_base_get_method(base));
	
	//释放event_base节点
	event_base_free(base);
	
	return 0;
	
}