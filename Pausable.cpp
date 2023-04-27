#include "Pausable.h"

Pausable::Pausable()
	: Running_(true)
{}

ResposeData Pausable::P_StopChat(int sender)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	if (!Running_)
	{
		response.Response = "ERROR: Chat is already stopped!";
		return response;
	}

	auto Sender = Database.find(sender);

	if (Sender == Database.end() || Sender->second != ROLE::Admin)
	{
		response.Response = "ERROR: No such sender or sender is not admin!";
		return response;
	}

	Running_ = false;

	response.Response = "Chat stopped.";
	response.Success = true;
	return response;
}

ResposeData Pausable::P_ResumeChat(int sender)
{
	ResposeData response;
	response.Response = "";
	response.Success = false;

	if (Running_)
	{
		response.Response = "ERROR: Chat is already running!";
		return response;
	}

	auto Sender = Database.find(sender);

	if (Sender == Database.end() || Sender->second != ROLE::Admin)
	{
		response.Response = "ERROR: No such sender or sender is not admin!";
		return response;
	}

	Running_ = true;

	response.Response = "Chat is running.";
	response.Success = true;
	return response;
}

bool Pausable::IsRunning()
{
	return Running_;
}
