#include "uc/app/app.h"
#include "uc/target/target.h"
#include "uc/platform/platform.h"

int main(void) {
    uc::platform::Init();
    uc::target::Init();
    uc::app::Main();
}
