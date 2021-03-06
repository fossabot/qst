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
#ifndef QSTTEST_H
#define QSTTEST_H

#include <QtCore/QDir>
#include <QtCore/QObject>
#include <QtCore/QProcess>
#include <QtCore/QString>

class QstTestResults;

class QstTest : public QObject
{
    Q_OBJECT

protected:
    QString dataPath(const QString& directory) const;
    QString defaultImportPath() const;
    QstTestResults execQstRun(const QStringList& arguments);
    QProcess& qstProcess();

private:
    QProcess m_qstProcess;
    static const QDir m_dataDirectory;
    static const QString m_defaultImportPath;
};

inline QProcess& QstTest::qstProcess() { return m_qstProcess; }


#define VERIFY_PASS(results, name) \
    if (!results.contains(name)) { \
             QFAIL(qPrintable(QString("%1: Not found in output") \
                    .arg(name))); \
    } \
    if (results.output(name).result != "PASS") { \
             QFAIL(qPrintable(QString("%1: Expected PASS but failed, '%2'") \
                    .arg(name) \
                    .arg(results.output(name).message))); \
    }


#define VERIFY_FAIL(results, name, expectedLocation) \
    if (!results.contains(name)) { \
             QFAIL(qPrintable(QString("%1: Not found in output") \
                    .arg(name))); \
    } \
    if (results.output(name).result != "FAIL") { \
        QFAIL(qPrintable(QString("%1: Expected FAIL but passed") \
               .arg(name))); \
    } \
    if (!results.output(name).location.endsWith(expectedLocation)) { \
             QFAIL(qPrintable(QString("%1: Expected location '%2', Actual location '%3'") \
                    .arg(name) \
                    .arg(expectedLocation) \
                    .arg(results.output(name).location))); \
    }

#endif // QSTTEST_H
