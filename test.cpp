
#include <stdio.h>
#include <unistd.h>
#include "eztimer.h"

int dispatch(uint32_t ud,const void * cb, int sz)
{
    printf("current ms:%lu timer call back ud:%u cb:%-4.4s sz:%d",
            eztimer_ms(),ud, (const char*)cb, sz);
    return 0;
}

int main()
{
    int ret = eztimer_init();
    eztimer_set_dispatcher(dispatch);
    uint64_t o = eztimer_ms();
    eztimer_id_t eid1 = eztimer_run(400, 1, "first", 5);
    eztimer_id_t eid2 = eztimer_run(411, 2, "second", 5);
    eztimer_id_t eid3 = eztimer_run(422, 3, "third", 5);
    while(true)
    {
        eztimer_update();
        usleep(1000);
        if(eztimer_ms() > o + 400)
        {
            eztimer_cancel(eid2);
        }
    }
    eztimer_destroy();
    return 0;
}


