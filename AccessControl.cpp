#include "AccessControl.h"

AccessControl::AccessControl()
{}

ResposeData AccessControl::AC_BanUser(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	auto Sender = Database.find(sender);
	auto User = Database.find(user);

	if (Sender == Database.end() || User == Database.end())
	{
		response.Response = "ERROR: No such sender or user!";
		return response;
	}

	if (User->second == ROLE::Banned)
	{
		response.Response = "ERROR: User is already banned!";
		return response;
	}

	if (Sender->second != ROLE::Admin && Sender->second != ROLE::Moderator)
	{
		response.Response = "ERROR: Sender is not admin or moderator!";
		return response;
	}

	if (User->second == ROLE::Admin || User->second == ROLE::Moderator)
	{
		response.Response = "ERROR: User is admin or moderator!";
		return response;
	}

	User->second = ROLE::Banned;
	response.Response = "User " + std::to_string(user) + " banned.";
	response.Success = true;
	return response;
}

ResposeData AccessControl::AC_UnBanUser(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	auto Sender = Database.find(sender);
	auto User = Database.find(user);

	if (Sender == Database.end() || User == Database.end())
	{
		response.Response = "ERROR: No such sender or user!";
		return response;
	}

	if (User->second != ROLE::Banned)
	{
		response.Response = "ERROR: User is not banned!";
		return response;
	}

	if (Sender->second != ROLE::Admin && Sender->second != ROLE::Moderator)
	{
		response.Response = "ERROR: Sender is not admin or moderator!";
		return response;
	}

	User->second = ROLE::User;
	response.Response = "User " + std::to_string(user) + " unbanned.";
	response.Success = true;
	return response;
}

ResposeData AccessControl::AC_RegisterNewUser(int sender, int newUser)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	auto User = Database.find(newUser);

	if (User != Database.end())
	{
		response.Response = "ERROR: User already exists!";
		return response;
	}

	auto Sender = Database.find(sender);

	if (Sender == Database.end() || Sender->second != ROLE::Admin)
	{
		response.Response = "ERROR: Sender not found or not an admin!";
		return response;
	}

	Database.emplace(newUser, ROLE::User);

	response.Response = "User registered.";
	response.Success = true;
	return response;
}

ResposeData AccessControl::AC_GrantModeratorRole(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	return response;
}

ResposeData AccessControl::AC_GrantAdminRole(int sender, int user)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	return response;
}
