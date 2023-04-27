#pragma once
#include "common.h"

class AccessControl
{
protected:

	AccessControl();
	ResposeData AC_BanUser(int sender, int user);
	ResposeData AC_UnBanUser(int sender, int user);
	ResposeData AC_RegisterNewUser(int sender, int newUser);
	ResposeData AC_GrantModeratorRole(int sender, int user);
	ResposeData AC_GrantAdminRole(int sender, int user);
};
