#include <stdio.h>
#include <event2/event.h>
#include <event2/bufferevent.h>

// global variables
struct event_base *g_eventBase = NULL;
struct event *g_event = NULL;

int createListenFd(char *port)
{
	int fd = 0;

	return fd;
}

void lsnCb(evutil_socket_t fd, short what, void *arg)
{

}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <port>\n", argv[0]);
		return -1;
	}

	g_eventBase = event_base_new();
	if (g_eventBase == NULL)
	{
		printf("event_base_new error\n");
		return -1;
	}

	lsnFd = createListenFd(argv[1]);
	if (lsnFd < 0)
	{
		printf("createListenFd error\n");
		return -1;
	}

	g_event = event_new(g_eventBase, lsnFd, EV_READ | EV_WRITE | EV_PERSIST, lsnCb, NULL);
	if (g_event == NULL)
	{
		printf("event_new error\n");
		return -1;
	}

	event_add(g_event, NULL);
	event_base_dispatch(g_eventBase);

	event_del(g_event);
	event_free(g_event);


	return 0;
}
