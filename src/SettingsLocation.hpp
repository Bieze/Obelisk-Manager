/*
Copyright (C) 2022 Abdul Hani


This file is part of Obelisk manager.

Obelisk manager is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Obelisk manager is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Obelisk manager. If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "config.h"
#include "base64.hpp"
#include "takeUserPassword.hpp"
#include <boost/filesystem.hpp>
#include "SQLiteCpp/SQLiteCpp.h"
#include <boost/filesystem/fstream.hpp>

using namespace std;
namespace ofs = boost::filesystem;

int createSettingsFiles()
{
    try
    {

        if (!ofs::exists(PROJECT_AUTH_PA))
        {

            ofs::ofstream AUTH_PA(PROJECT_AUTH_PA);
            ofs::permissions(PROJECT_AUTH_PA, ofs::perms::owner_all);
            cout << "Thank your for using Obelisk Manager, since the database has just been created\n";
            cout << "Has been wiped out and reset,   we have to create an admin password to protect\n";
            cout << "Sensitive information stored,   this  means that the password should be strong\n";
            cout << "And can't be shared with anyone else.\n";

            cout << "Enter password: ";

            string input = takePasswdFromUser();
            string encodedInput = base64_encode(input);

            SQLite::Database db(PROJECT_AUTH_PA, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

            SQLite::Transaction transaction(db);
            db.exec("CREATE TABLE \"passwords\" (\"website\"	TEXT, \"username\"	TEXT, \"password\"	TEXT);");

            db.exec("INSERT INTO passwords (website, username, password) VALUES ('obelisk-manager', 'admin', '" + encodedInput + "');");

            transaction.commit();
            return 0;
        }

        else
        {
            return 0;
        }
    }
    catch (exception &e)
    {
        cout << "[1] " << e.what() << endl;
        return 1;
    }

    return 0;
}

int SettingsLocationInit()
{

    string confLoc = string(PROJECT_CONFIG_DIR);

    if (ofs::is_directory(PROJECT_CONFIG_DIR))
    {
        createSettingsFiles();
        ofs::permissions(PROJECT_CONFIG_DIR, ofs::perms::owner_all);
    }
    else
    {
        ofs::create_directory(PROJECT_CONFIG_DIR);
        ofs::permissions(PROJECT_CONFIG_DIR, ofs::perms::owner_all);
        createSettingsFiles();
    }
    return 0;
}