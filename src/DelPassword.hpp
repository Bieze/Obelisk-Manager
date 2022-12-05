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
#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;

int DelPasswordFromDb() {
    string website;
    string username;
    string password;

    cout << "Copyright (C) 2022 Abdul Hani\n";
    cout << "Obelisk manager is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.\n";
    cout << "Obelisk manager is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.\n";
    cout << "You should have received a copy of the GNU General Public License along with Obelisk manager. If not, see <https://www.gnu.org/licenses/>.\n";

    cout << "\nPlease fill out each of the questions to be remove the data from the database.\n";
    cout << "NONE of the questions can be BLANK\n";
    cout << "ONCE THIS DATA IS REMOVED IT CANNOT BE RESTORED\n";

    cout << "What is the name of the website or program?\n";
    cout << "Answer: ";
    cin >> website;

    cout << "What is your login username?\n";
    cout << "Answer: ";
    cin >> username;

    cout << "What is your password for this website or program?\n";
    cout << "Answer: ";
    cin >> password;

    if (website.empty()) {
        cout << "[1] Website name can't be nothing.";
        exit(1);
    } else if (username.empty()) {
        cout << "[1] Username can't be nothing.";
        exit(1);
    } else if (password.empty()) {
        cout << "[1] Password can't be nothing.";
        exit(1);
    } else if (!website.empty() and !username.empty() and !password.empty()) {
        try {
            SQLite::Database db(PROJECT_AUTH_PA, SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
            SQLite::Transaction transaction(db);

            db.exec("DELETE FROM passwords WHERE website='" + base64_encode(website) + "' AND username='" + base64_encode(username) + "' AND password='" + base64_encode(password) + "';");
            transaction.commit();

            cout << "Removed data from database!";
        } catch (exception &e) {
            cout << "[1] " << e.what() << endl;
            exit(1);
        }
    }
    return 0;
}