#include "Logger.h"
#include <iostream>
#include <String>


using namespace std;

LoopEngine::Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive){}

LoopEngine::Logger::~Logger(){}

void LoopEngine::Logger::ActivateConsoleTrace(bool InIsActive) { this->_IsConsoleTraceActive = InIsActive; }

void LoopEngine::Logger::SetLoggingLevel(const TLevel InLoggingLevel) { this->_LoggingLevel = InLoggingLevel;}

void LoopEngine::Logger::Log(string msg, const TLevel InLoggingLevel) const {  }

void LoopEngine::Logger::ActivateFileTrace(bool InIsActive){}

void LoopEngine::Logger::ActivateFileTrace(bool InIsActive, const string& InFileName){}

void LoopEngine::Logger::SetFileTraceName(const string InFileTraceName){}

void LoopEngine::Logger::SetAbortLevel(const TLevel InAbortLevel){}

bool LoopEngine::Logger::TryOpenFile()
{
	return false;
}

bool LoopEngine::Logger::TryCloseFile()
{
	return false;
}
