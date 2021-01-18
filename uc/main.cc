#include "code/app.h"
#include "code/target.h"
#include "code/platform.h"

void code_main(void) {
    astros::platform::Init();
    astros::target::Init();
    astros::app:Main();
    panic("Should never reach this point.");
}
