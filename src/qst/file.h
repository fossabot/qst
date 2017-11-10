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

#ifndef FILE_H
#define FILE_H

#include <QObject>

class QJSEngine;
class QQmlEngine;

class File : public QObject
{
    Q_OBJECT
public:
    explicit File(QObject* parent = 0);
    Q_INVOKABLE bool exists(const QString& filePath) const;

public:
    static QObject* createSingleInstance(QQmlEngine* engine, QJSEngine* scriptEngine);

};

#endif // FILE_H