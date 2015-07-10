
#include <stdio.h>
#include <unistd.h>
#include "eztimer.h"


eztimer_id_t eid[3];
int dispatch(uint32_t ud,const void * cb, int sz)
{
    printf("current ms:%lu timer call back ud:%u cb:%-4.4s sz:%d\n",
            eztimer_ms(),ud, (const char*)cb, sz);
    eid[ud-1] = 0;
    return 0;
}

int main()
{
    int ret = eztimer_init();
    eztimer_set_dispatcher(dispatch);
    uint64_t o = eztimer_ms();
    eid[0] = eztimer_run(400, 1, "first", 5);
    eid[1] = eztimer_run(411, 2, "second", 5);
    eid[2] = eztimer_run(422, 3, "third", 5);
    while(true)
    {
        eztimer_update();
        usleep(1000);
        if(eid[1] > 0 &&
            eztimer_ms() > o + 401)
        {
            eztimer_cancel(eid[1]);
        }
    }
    eztimer_destroy();
    return 0;
}


