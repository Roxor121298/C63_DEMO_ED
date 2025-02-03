#include "Logger.h"
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

namespace LoopEngine {

    Logger::Logger(const TLevel InLoggingLevel, bool InConsoleTraceActive, bool InFileTraceActive)
        : _LoggingLevel(InLoggingLevel), _IsConsoleTraceActive(InConsoleTraceActive), _IsFileTraceActive(InFileTraceActive), _ptrFileStream(nullptr) {
        if (_IsFileTraceActive) {
            TryOpenFile();
        }
    }

    Logger::~Logger() {
        TryCloseFile();
    }

    void Logger::ActivateConsoleTrace(bool InIsActive) {
        _IsConsoleTraceActive = InIsActive;
    }

    void Logger::SetLoggingLevel(const TLevel InLoggingLevel) {
        _LoggingLevel = InLoggingLevel;
    }

    void Logger::SetAbortLevel(const TLevel InAbortLevel) {
        _AbortLevel = InAbortLevel;
    }

    void Logger::Log(string msg, const TLevel InLoggingLevel) const {
        if (InLoggingLevel < _LoggingLevel) return;

        if (_IsConsoleTraceActive) {
            cout << msg << endl;
        }

        if (_IsFileTraceActive && _ptrFileStream) {
            (*_ptrFileStream) << msg << endl;
        }

        if (InLoggingLevel >= _AbortLevel) {
            abort();
        }
    }

    void Logger::ActivateFileTrace(bool InIsActive) {
        if (_IsFileTraceActive == InIsActive) return;
        _IsFileTraceActive = InIsActive;
        if (_IsFileTraceActive) {
            TryOpenFile();
        }
        else {
            TryCloseFile();
        }
    }

    void Logger::ActivateFileTrace(bool InIsActive, const string& InFileName) {
        SetFileTraceName(InFileName);
        ActivateFileTrace(InIsActive);
    }

    void Logger::SetFileTraceName(const string InFileTraceName) {
        if (InFileTraceName.empty()) {
            Log("Erreur: Le nom du fichier de log est vide.", TLevel::eERROR);
            return;
        }
        _TraceFileName = InFileTraceName;
        TryOpenFile();
    }

    bool Logger::TryOpenFile() {
        TryCloseFile();
        _ptrFileStream = new ofstream(_TraceFileName, ios::app);
        return _ptrFileStream->is_open();
    }

    bool Logger::TryCloseFile() {
        if (_ptrFileStream) {
            _ptrFileStream->close();
            delete _ptrFileStream;
            _ptrFileStream = nullptr;
            return true;
        }
        return false;
    }

}
