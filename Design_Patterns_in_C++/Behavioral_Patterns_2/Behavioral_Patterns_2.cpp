#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Observer
{
public:
	virtual ~Observer() = default;
	virtual void onWarning(const std::string& message) {}
	virtual void onError(const std::string& message) {}
	virtual void onFatalError(const std::string& message) {}
};

class Observable
{
private:
	std::vector<Observer*> observers_;
public:
	void AddObserver(Observer* observer)
	{
		observers_.push_back(observer);
	}

	void RemoveObserver(Observer* observer)
	{
		auto it = std::remove(observers_.begin(), observers_.end(), observer);
		observers_.erase(it, observers_.end());
	}
	void warning(const std::string& message) const
	{
		for (auto observer : observers_)
		{
			observer->onWarning(message);
		}
	}

	void error(const std::string& message) const
	{
		for (auto observer : observers_)
		{
			observer->onError(message);
		}
	}

	void fatalError(const std::string& message) const
	{
		for (auto observer : observers_)
		{
			observer->onFatalError(message);
		}
	}
};

class ConsoleWarningLog : public Observer
{
public:
	void onWarning(const std::string& message) override
	{
		std::cout << "ConsoleWarningLog: " << message << std::endl;
	}

	void onError(const std::string& message) override {}

	void onFatalError(const std::string& message) override {}
};

class FileErrorLog : public Observer
{
private:
	std::ofstream logFile;

public:
	FileErrorLog(const std::string& message)
	{
		logFile.open(message);
	}

	~FileErrorLog() override
	{
		logFile.close();
	}
	void onWarning(const std::string& message) override {}

	void onError(const std::string& message) override
	{
		logFile << "FileErrorLog: " << message << std::endl;
	}

	void onFatalError(const std::string& message) override {}
};

class FatalErrorLog : public Observer
{
private:
	std::ofstream logFile;

public:
	FatalErrorLog(const std::string& message)
	{
		logFile.open(message);
	}

	~FatalErrorLog() override
	{
		logFile.close();
	}
	void onWarning(const std::string& message) override {}

	void onError(const std::string& message) override {}

	void onFatalError(const std::string& message) override
	{
		logFile << "FatalErrorLogFile: " << message << std::endl;
		std::cout << "FatalErrorLogConsole: " << message << std::endl;
	}
};

int main()
{
	Observable observable;

	ConsoleWarningLog WarningLog;
	FileErrorLog ErrorLog("error.txt");
	FatalErrorLog FatalLog("fatal_error.txt");

	observable.AddObserver(&WarningLog);
	observable.AddObserver(&ErrorLog);
	observable.AddObserver(&FatalLog);
	
	observable.warning("warning");
	observable.error("error");
	observable.fatalError("fatal error");

	observable.RemoveObserver(&WarningLog);
	observable.RemoveObserver(&ErrorLog);
	observable.RemoveObserver(&FatalLog);

	return 0;
}
