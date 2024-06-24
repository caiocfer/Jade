#include "power.h"
#include "jade_assert.h"
#include <sdkconfig.h>

// Include implementation specific to hardware and/or power management chip

#if defined(CONFIG_BOARD_TYPE_JADE)
#include "power/jadev10.inc"
#elif defined(CONFIG_BOARD_TYPE_JADE_V1_1)
#include "power/jadev11.inc"
#elif defined(CONFIG_BOARD_TYPE_JADE_V2)
#include "power/jadev20.inc"
#elif defined(CONFIG_BOARD_TYPE_M5_STICKC_PLUS) || defined(CONFIG_BOARD_TYPE_M5_CORE2)
// These have AXP192 but configured differently from the Jade
#include "power/m5stickcplus.inc"
#elif defined(CONFIG_BOARD_TYPE_M5_CORES3)
// M5 Core S3 has AXP2101
#include "power/m5stackcores3.inc"
#elif defined(CONFIG_HAS_IP5306)
#include "power/ip5306.inc"
#else
// Stubs for other hw boards (ie. no power management)
#include "power/minimal.inc"
#endif
