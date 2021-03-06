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
#ifndef PROJECT_H
#define PROJECT_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtQml/QQmlParserStatus>

class Project : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)

public:
    explicit Project(QObject *parent = 0);

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QStringList references READ references WRITE setReferences)
    Q_PROPERTY(QString workingDirectory READ workingDirectory CONSTANT)

    void classBegin();
    void componentComplete();

    QString name() const;
    QStringList references() const;
    QString workingDirectory() const;

    void setName(const QString& name);
    void setReferences(const QStringList& references);

private:
    QString m_name;
    QStringList m_references;
    QString m_workingDirectory;
};

inline QString Project::name() const { return m_name; }

inline QStringList Project::references() const { return m_references; }

inline QString Project::workingDirectory() const { return m_workingDirectory; }

inline void Project::setName(const QString& name)
{
    m_name = name;
}

inline void Project::setReferences(const QStringList& references)
{
    m_references = references;
}



#endif // PROJECT_H
