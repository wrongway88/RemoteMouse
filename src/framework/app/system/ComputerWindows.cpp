#include "ComputerWindows.h"

#include <Windows.h>

const unsigned int ComputerWindows::m_maxNameLength = 512;

ComputerWindows::ComputerWindows()
{
}

ComputerWindows::~ComputerWindows()
{
}

std::string ComputerWindows::getName() const
{
	TCHAR name[m_maxNameLength+1];
	DWORD nameLength = m_maxNameLength;

	GetComputerName(name, &nameLength);

	int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, &name[0], nameLength, NULL, 0, NULL, NULL);

	std::string result = std::string(nameLength, 0);

	WideCharToMultiByte(CP_UTF8, 0, &name[0], nameLength, &result[0], sizeNeeded, NULL, NULL);

	return result;
}