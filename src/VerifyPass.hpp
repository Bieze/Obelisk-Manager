/*
Copyright (C) 2022 Abdul Hani


This file is part of Obelisk manager.

Obelisk manager is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Obelisk manager is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Obelisk manager. If not, see <https://www.gnu.org/licenses/>.
*/

#include "config.h"
#include <iostream>
#include "base64.hpp"
#include "takeUserPassword.hpp" 
#include <SQLiteCpp/SQLiteCpp.h>


using namespace std;

int VerifyPass() {
    cout << "Enter admin password: ";
    string input = takePasswdFromUser();
    SQLite::Database db(PROJECT_AUTH_PA, SQLite::OPEN_READONLY);
    SQLite::Statement query(db, "SELECT * FROM passwords WHERE website = 'obelisk-manager'");


    query.executeStep();
    string password = query.getColumn(2);
    if (base64_encode(input) == password) {
        ;
    } else {
        cout << "[1] Incorrect password!";
        exit(1);
    }

    

    return 0;
}