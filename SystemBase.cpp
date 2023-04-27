#include "SystemBase.h"

SystemBase::SystemBase(int admin)
{
	Database.emplace(admin, ROLE::Admin);
}

ResposeData SystemBase::BanUser(int sender, int user)
{
	return AC_BanUser(sender, user);
}

ResposeData SystemBase::UnBanUser(int sender, int user)
{
	return AC_UnBanUser(sender, user);
}

ResposeData SystemBase::RegisterNewUser(int sender, int newUser)
{
	return AC_RegisterNewUser(sender, newUser);
}

ResposeData SystemBase::GrantModeratorRole(int sender, int user)
{
	return AC_GrantModeratorRole(sender, user);
}

ResposeData SystemBase::GrantAdminRole(int sender, int user)
{
	return AC_GrantAdminRole(sender, user);
}

ResposeData SystemBase::StopChat(int sender)
{
	return P_StopChat(sender);
}

ResposeData SystemBase::ResumeChat(int sender)
{
	return P_ResumeChat(sender);
}

bool SystemBase::TestRunning()
{
	return IsRunning();
}