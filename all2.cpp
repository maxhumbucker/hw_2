#pragma once
#include <string>
#include <iostream>
#include <map>
#include <vector>

enum ROLE
{
	Admin = 0,
	Moderator,
	Banned,
	User
};

struct ResposeData
{
	bool Success;
	std::string Response;
};

struct UserData {
    int ID;
    ROLE Role;
};

std::vector<UserData> Database;



class AccessControl {
protected:
    AccessControl();
    ResposeData AC_BanUser(int sender, int user);
    ResposeData AC_UnBanUser(int sender, int user);
    ResposeData AC_RegisterNewUser(int sender, int newUser);
    ResposeData AC_GrantModeratorRole(int sender, int user);
    ResposeData AC_GrantAdminRole(int sender, int user);
};

AccessControl::AccessControl() {}

ResposeData AccessControl::AC_BanUser(int sender, int user) {
    ResposeData response;
    response.Response = "";
    response.Success = false;

    if (sender >= Database.size() || user >= Database.size()) {
        response.Response = "ERROR: No such sender or user!";
        return response;
    }

    if (Database[user].Role == ROLE::Banned) {
        response.Response = "ERROR: User is already banned!";
        return response;
    }

    if (Database[sender].Role != ROLE::Admin && Database[sender].Role != ROLE::Moderator) {
        response.Response = "ERROR: Sender is not admin or moderator!";
        return response;
    }

    if (Database[user].Role == ROLE::Admin || Database[user].Role == ROLE::Moderator) {
        response.Response = "ERROR: User is admin or moderator!";
        return response;
    }

    Database[user].Role = ROLE::Banned;
    response.Response = "User " + std::to_string(user) + " banned.";
    response.Success = true;
    return response;
}

ResposeData AccessControl::AC_UnBanUser(int sender, int user) {
    ResposeData response;
    response.Response = "";
    response.Success = false;

    if (sender >= Database.size() || user >= Database.size()) {
        response.Response = "ERROR: No such sender or user!";
        return response;
    }

    if (Database[user].Role != ROLE::Banned) {
        response.Response = "ERROR: User is not banned!";
        return response;
    }

    if (Database[sender].Role != ROLE::Admin && Database[sender].Role != ROLE::Moderator) {
        response.Response = "ERROR: Sender is not admin or moderator!";
        return response;
    }

    Database[user].Role = ROLE::User;
    response.Response = "User " + std::to_string(user) + " unbanned.";
    response.Success = true;
    return response;
}

ResposeData AccessControl::AC_RegisterNewUser(int sender, int newUser)
{
ResposeData response;
response.Response = "";
response.Success = false;

auto User = std::find_if(Database.begin(), Database.end(),
	[&newUser](const UserData& user) { return user.ID == newUser; });

if (User != Database.end())
{
	response.Response = "ERROR: User already exists!";
	return response;
}

auto Sender = std::find_if(Database.begin(), Database.end(),
	[&sender](const UserData& user) { return user.ID == sender; });

if (Sender == Database.end() || Sender->role != ROLE::Admin)
{
	response.Response = "ERROR: Sender not found or not an admin!";
	return response;
}

Database.emplace_back(newUser, ROLE::User);

response.Response = "User registered.";
response.Success = true;
return response;
}

ResposeData AccessControl::AC_GrantModeratorRole(int sender, int user)
{
ResposeData response;
response.Response = "";
response.Success = false;

auto Sender = std::find_if(Database.begin(), Database.end(),
	[&sender](const UserData& user) { return user.ID == sender; });

auto User = std::find_if(Database.begin(), Database.end(),
	[&user](const UserData& user) { return user.ID == user; });

if (Sender == Database.end() || User == Database.end())
{
	response.Response = "ERROR: No such sender or user!";
	return response;
}

if (Sender->role != ROLE::Admin && Sender->role != ROLE::Moderator)
{
	response.Response = "ERROR: Sender isn't admin or moderator!";
	return response;
}

if (User->role == ROLE::Admin || User->role == ROLE::Moderator)
{
	response.Response = "ERROR: User is admin or moderator!";
	return response;
}


User->role = ROLE::Moderator;
response.Response = "User " + std::to_string(user) + " is moderator.";
response.Success = true;
return response;
}

ResposeData AccessControl::AC_GrantAdminRole(int sender, int user)
{
ResposeData response;
response.Response = "";
response.Success = false;

auto Sender = std::find_if(Database.begin(), Database.end(),
    [&sender](const UserData& user) { return user.ID == sender; });

auto User = std::find_if(Database.begin(), Database.end(),
    [&user](const UserData& user) { return user.ID == user; });

if (Sender == Database.end() || User == Database.end())
{
	response.Response = "ERROR: No such sender or user!";
	return response;
}

if (Sender->role != ROLE::Admin)
{
	response.Response = "ERROR: Sender isn't admin!";
	return response;
}

if (User->role == ROLE::Admin)
{
	response.Response = "ERROR: User is admin!";
	return response;
}

User->role = ROLE::Admin;
response.Response = "User " + std::to_string(user) + " is admin.";
response.Success = true;

return response;
}