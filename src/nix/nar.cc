#include "command.hh"

using namespace nix;

struct CmdNar : NixMultiCommand
{
    CmdNar() : MultiCommand(RegisterCommand::getCommandsFor({"nar"}))
    { }

    std::string description() override
    {
        return "create or inspect NAR files";
    }

    std::string doc() override
    {
        return
          #include "nar.md"
          ;
    }

    Category category() override { return catUtility; }

    void run() override
    {
        if (!command)
            throw UsageError("'nix nar' requires a sub-command.");
        command->second->prepare();
        command->second->run();
    }

    void printHelp(const string & programName, std::ostream & out) override
    {
        MultiCommand::printHelp(programName, out);
    }
};

static auto rCmdNar = registerCommand<CmdNar>("nar");
