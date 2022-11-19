#include <boost/program_options.hpp>
#include <iostream>
#include "config.h"

using namespace std;
namespace po = boost::program_options;

int main(int argc, char *argv[]) {
    try {
        string project_name = string(PROJECT_NAME);
        string project_ver = string(PROJECT_VER);
        string project_hash = string(PROJECT_HASH);

        po::options_description desc(project_name + " v" + project_ver);
        desc.add_options()
            ("help,h", "Display this help message")
            ("version,v", "Display the version number")
        ;

        po::variables_map vm;

        po::parsed_options parsed = po::command_line_parser(argc, argv).
            options(desc).
            allow_unregistered().
            run();
        po::store(parsed, vm);
        

        if(vm.count("help") || argc == 1) {
            cout << desc << "\n";
        } else if (vm.count("version")) {
            cout << project_name + " Project Version: v" + 
                project_ver << " Git hash: " << 
                project_hash << " C++ standard: " <<
                __cplusplus << "\n";
        }
    }

    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
    }
    return 0;
}