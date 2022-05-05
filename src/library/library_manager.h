#pragma once
#include "caf_system_base.h"
#include "fruit/fruit.h"
#include "library_manager_base.h"

fruit::Component<fruit::Required<caf_system_base>, library_manager_base>
get_library_manager();