#pragma once

#include <string>

struct Message
{
	std::string senderUsername;
	std::string receiverUsername;
	std::string subject;
	std::string body;

	Message() {};
	Message(std::string senderUsername, std::string receiverUsername, std::string subject, std::string body)
		: senderUsername(senderUsername), receiverUsername(receiverUsername), subject(subject), body(body) {};
};
