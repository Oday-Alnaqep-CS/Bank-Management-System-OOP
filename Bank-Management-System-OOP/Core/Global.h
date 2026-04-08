#pragma once
#include <iostream>
#include "ClsUser.h"

inline ClsUser CurrentUser = ClsUser::Find("", "");
