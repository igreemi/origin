#include <iostream>
#include <string>
#include <fstream>

class LogCommand
{
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class LogConsole : public LogCommand
{
public:
	void print(const std::string& message) override
	{
		std::cout << "LogConsole: " << message << std::endl;
	}
};

class LogFile : public LogCommand
{
private:
	std::ofstream file;

public:
	LogFile(const std::string& name_file)
	{
		file.open(name_file);
	}

	~LogFile() override
	{
		file.close();
	}

	void print(const std::string& message) override
	{
		file << "LogFile: " << message << std::endl;
	}
};

void print(LogCommand& log)
{
	log.print("log message");
}

int main()
{
	LogConsole console;
	LogFile file("log.txt");

	print(console);
	print(file);

	return 0;
}
