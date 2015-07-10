
#include <stdio.h>
#include <unistd.h>
#include "eztimer.h"


eztimer_id_t eid[3];
int dispatch(uint32_t ud,const void * cb, int sz)
{
    printf("current ms:%lu timer call back ud:%u cb:%-4.4s sz:%d\n",
            eztimer_ms(),ud, (const char*)cb, sz);
    if(ud == 1)
    {
        eztimer_cancel(eid[1]);
        eid[1] = 0;
    }
    eid[ud-1] = 0;
    return 0;
}

int main()
{
    int ret = eztimer_init();
    eztimer_set_dispatcher(dispatch);
    uint64_t o = eztimer_ms();
    eid[0] = eztimer_run_after(400, 1, "first", 5);
    eid[1] = eztimer_run_after(1000, 2, "second", 5);
    eid[2] = eztimer_run_every(2000, 3, "third", 5);
    while(true)
    {
        eztimer_update();
        usleep(1000);
    }
    eztimer_destroy();
    return 0;
}


