/*
Copyright (C) 2022 Abdul Hani


This file is part of Obelisk manager.

Obelisk manager is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

Obelisk manager is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Obelisk manager. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef TAKE_USER_PASS
#define TAKE_USER_PASS

#include <conio.h>
#include <iostream>

using namespace std;

inline string takePasswdFromUser()
{
    string ipt = "";
    char ipt_ch;
    while (true)
    {
        ipt_ch = getch();

        // Check whether user enters
        // a special non-printable
        // character
        if (ipt_ch < 32)
        {
            cout << endl;
            return ipt;
        }
        ipt.push_back(ipt_ch);
    }
}

#endif