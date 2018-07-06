/*************************************************************************
	> File Name: set_timer.c
	> Author: 
	> Mail: 
	> Created Time: Fri Jul  6 18:03:55 2018
 ************************************************************************/

#include <stdio.h>
#include <event2/event.h>
#include <event2/event_struct.h>

struct event *ev;
struct timeval tv;

void timer_cb(int fd, short event, void *argc)
{
    printf("shit, timer wake up\n");
    event_add(ev, &tv);    // reschedule timer
}

int main(int argc, char **argv)
{
    struct event_base *base = event_base_new();

    tv.tv_sec = 2;
    tv.tv_usec = 0;

//    evtimer_new(&ev, timer_cb, NULL);
    ev = event_new(base, -1, EV_PERSIST, timer_cb, NULL);


    event_add(ev, &tv);

    
    event_base_dispatch(base);


    return 0;
}
