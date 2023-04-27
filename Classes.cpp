#include <iostream>
#include <string>
#include "SystemBase.h"


void PrintResponse(const ResposeData& response) {
	std::cout << "result: " << (response.Success ? "True" : "False") << "\nresponse: " <<
		response.Response << "\n";
}


int main()
{
	int user1 = 1;
	int user2 = 2;
	int user3 = 3;
	SystemBase Chat(user1);
	ResposeData response;
	
	std::cout << "Test: register\n";
	response = Chat.RegisterNewUser(user1, user2);
	PrintResponse(response);
	response = Chat.RegisterNewUser(user2, user3);
	PrintResponse(response);
	response = Chat.RegisterNewUser(user1, user3);
	PrintResponse(response);
	response = Chat.RegisterNewUser(user1, user3);
	PrintResponse(response);

	std::cout << "\nTest: ban\n";
	response = Chat.BanUser(user3, user2);
	PrintResponse(response);
	response = Chat.BanUser(user1, user2);
	PrintResponse(response);
	response = Chat.BanUser(user1, user2);
	PrintResponse(response);

	std::cout << "\nTest: unban\n";
	response = Chat.UnBanUser(user1, user3);
	PrintResponse(response);
	response = Chat.UnBanUser(user3, user2);
	PrintResponse(response);
	response = Chat.UnBanUser(user1, user2);
	PrintResponse(response);

	std::cout << "\nTest: pause\n";
	response = Chat.ResumeChat(user1);
	PrintResponse(response);
	response = Chat.StopChat(user2);
	PrintResponse(response);
	response = Chat.StopChat(user1);
	PrintResponse(response);
	response = Chat.StopChat(user1);
	PrintResponse(response);
	response = Chat.ResumeChat(user2);
	PrintResponse(response);
	response = Chat.ResumeChat(user1);
	PrintResponse(response);

	/*
	AccessControl ac;
	int user1 = 1;
	int user2 = 2;
	int user3 = 3;

	ResposeData response;

	std::cout << "Test: register\n";
	response = ac.AssignRole(1, ROLE::User);
	PrintResponse(response);
	response = ac.AssignRole(2, ROLE::User);
	PrintResponse(response);
	response = ac.AssignRole(3, ROLE::User);
	PrintResponse(response);

	std::cout << "Test: change role\n";
	response = ac.AssignRole(1, ROLE::Admin);
	PrintResponse(response);

	std::cout << "Test: assign same role\n";
	response = ac.AssignRole(1, ROLE::Admin);
	PrintResponse(response);
	*/
}
