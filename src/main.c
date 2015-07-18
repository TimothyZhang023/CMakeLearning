#include <event2/event.h>

#include <LibeventLearningConfig.h>
#include <fetch.h>
#include <pid.h>


int main(int c, char **v) {

      fetchHttp();

      print_pid();

    struct event_base *base;

    base = event_base_new();


    event_base_dispatch(base);

    printf("%d %d", VERSION_MAJOR, VERSION_MINOR);

    return 0;
}