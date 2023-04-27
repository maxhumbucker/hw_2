#pragma once
#include <string>
#include <iostream>
#include <map>

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
std::map<int, ROLE> Database;
