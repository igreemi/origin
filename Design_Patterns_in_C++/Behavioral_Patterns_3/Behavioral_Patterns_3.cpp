#include <iostream>
#include <string>
#include <fstream>

enum class Type {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
private:
    Type m_type;
    std::string m_msg;

public:
    LogMessage(Type type, const std::string& msg) : m_type(type), m_msg(msg) {}
    Type type() const
    {
        return m_type;
    }

    const std::string& message() const
    {
        return m_msg;
    }
};

class LogHandler
{
protected:
    LogHandler* m_nextHandler;

public:

    virtual void handleLog(const LogMessage& logMsg) = 0;

    virtual void setNextHandler(LogHandler* nextHandler)
    {
        m_nextHandler = nextHandler;
    }
};

class FatalError : public LogHandler
{
public:
    void handleLog(const LogMessage& logMsg) override
    {
        if (logMsg.type() == Type::FatalError)
        {
            std::cout << "FatalError " << std::endl;
            throw std::runtime_error(logMsg.message());
        }
        else
        {
//            std::cout << "No FatalError -> " << std::endl;
            m_nextHandler->handleLog(logMsg);
        }
    }
};

class Error : public LogHandler
{
private:
    std::ofstream logFile;

public:
    Error(const std::string& fileName)
    {
        logFile.open(fileName);
    }

    void handleLog(const LogMessage& logMsg) override
    {
        if (logMsg.type() == Type::Error)
        {
            std::cout << "Error " << std::endl;
            logFile << logMsg.message() << std::endl;
            logFile.close();
        }
        else
        {
//            std::cout << "No Error -> " << std::endl;
            logFile.close();
            m_nextHandler->handleLog(logMsg);
        }
    }
};

class Warning : public LogHandler
{
public:
    void handleLog(const LogMessage& logMsg) override
    {
        if (logMsg.type() == Type::Warning)
        {
            std::cout << "Warning " << std::endl;
//            std::cout << logMsg.message() << std::endl;
        }
        else
        {
//            std::cout << "No Warning -> " << std::endl;
            m_nextHandler->handleLog(logMsg);
        }
    }
};

class Unknow : public LogHandler
{
public:
    void handleLog(const LogMessage& logMsg) override 
    {
        if (logMsg.type() == Type::Unknown) 
        {
            std::cout << "Unknow " << std::endl;
 //           throw std::runtime_error("Unhandled log message");
        }
        else
        {
//            std::cout << "No Unknow -> " << std::endl;
            m_nextHandler->handleLog(logMsg);
        }
    }
};

int main()
{
    LogHandler* fatalHandler = new FatalError();
    LogHandler* errorHandler = new Error("log.txt");
    LogHandler* warningHandler = new Warning();
    LogHandler* unknownHandler = new Unknow();

    fatalHandler->setNextHandler(errorHandler);
    errorHandler->setNextHandler(warningHandler);
    warningHandler->setNextHandler(unknownHandler);

    LogMessage log(Type::Unknown, "Warning message");

    try {
        fatalHandler->handleLog(log);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    delete fatalHandler;
    delete errorHandler;
    delete warningHandler;
    delete unknownHandler;

    return 0;
}
