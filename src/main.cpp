/*
Copyright (C) 2022 Abdul Hani


This file is part of Obelisk manager.

Obelisk manager is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Obelisk manager is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Obelisk manager. If not, see <https://www.gnu.org/licenses/>.
*/

#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include "SettingsLocation.hpp"
#include <SQLiteCPP/SQLiteCpp.h>
#include "VerifyPass.hpp"
#include <iostream>
#include "config.h"


using namespace std;
namespace po = boost::program_options;
namespace ofs = boost::filesystem;

int main(int argc, char *argv[]) {
    try {
        SettingsLocationInit();

        string project_name = string(PROJECT_NAME);
        string project_ver = string(PROJECT_VER);
        string project_hash = string(PROJECT_HASH);

        po::options_description desc(project_name + " v" + project_ver);
        desc.add_options()
            ("help,h", "Display this help message")
            ("version,v", "Display the version number")
            ("forgot-password", "Help for what to do if you forgot your master password")
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
        } else if (vm.count("forgot-password")) {
            cout << "If you forgot your password I suggest downloading the SQLite shell\n";
            cout << "Or an SQLite database viewer and decode the password to regain access.";

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