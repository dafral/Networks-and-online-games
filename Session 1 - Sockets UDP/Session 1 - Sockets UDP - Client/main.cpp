#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define port 8000

#include "Windows.h"
#include "WinSock2.h"
#include "Ws2tcpip.h"

bool InitializeLibs()
{
	WSADATA wsaData;
	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != NO_ERROR)
	{
		// Log and handle error
		return false;
	}

	return true;

}

bool CleanupLibs()
{
	int iResult = WSACleanup();
	if (iResult != NO_ERROR)
	{
		//log and handle error
		return false;
	}

	return true;

}

int main(int argc, char **argv)
{
	SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);


	struct sockaddr_in bindAddr;

	bindAddr.sin_family = AF_INET;
	bindAddr.sin_port = htons(port);
	
	//Destination IP address
	struct sockaddr_in remoteAddr;
	remoteAddr.sin_family = AF_INET; 
	remoteAddr.sin_port = htons(port); 
	const char *remoteAddrStr = "127.0.0.1"; 
	inet_pton(AF_INET, remoteAddrStr, &remoteAddr.sin_addr);


	closesocket(s);
}