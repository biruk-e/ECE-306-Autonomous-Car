#include "inc/time.h"
#include "inc/macros.h"
#include "inc/globals.h"

// from globals.h
volatile unsigned int current_time = 0;
volatile unsigned int last_time = 0;
unsigned char time_changed = FALSE;

void time_process() {
    static unsigned char time_set = FALSE;
    current_time = Time_Sequence;
    time_changed = FALSE;

    if (!time_set) {
        last_time = current_time;
        time_set = TRUE;
    }
    if (current_time != last_time) {
        last_time = current_time;
        time_changed = TRUE;
    }
}
