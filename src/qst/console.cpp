/****************************************************************************
 **
 ** Copyright (C) 2017 The Qst project.
 **
 ** Contact: https://github.com/rweickelt/qst
 **
 ** $BEGIN_LICENSE$
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.

 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.

 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **
 ** $END_LICENSE$
****************************************************************************/
#include "console.h"

#include <QtCore/QString>


void Console::printError(const QString& text)
{
    printToStdError(QString("ERROR: ") + text);
}

void Console::printQmlError(const QString& text, const QString& filename)
{
    printToStdError(QString("ERROR in '%1': %3").arg(filename).arg(text));
}

void Console::printToStdOut(const QString& text)
{
    fputs(qPrintable(text), stdout);
    fputs("\n", stdout);
}

void Console::printToStdError(const QString& text)
{
    fputs(qPrintable(text), stderr);
    fputs("\n", stdout);
}