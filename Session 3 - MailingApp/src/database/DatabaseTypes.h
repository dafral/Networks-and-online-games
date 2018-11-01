#pragma once

#include <string>

enum MessageTYPE
{
	SENT,
	RECEIVED
};

struct Message
{
	std::string senderUsername;
	std::string receiverUsername;
	std::string subject;
	std::string body;
	MessageTYPE type;
};
