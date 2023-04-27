#pragma once
#include "common.h"

class Pausable
{
protected:

	Pausable();
	ResposeData P_StopChat(int sender);
	ResposeData P_ResumeChat(int sender);
	bool IsRunning();

private:
	bool Running_;
};