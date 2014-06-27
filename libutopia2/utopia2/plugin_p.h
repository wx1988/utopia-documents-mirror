/*****************************************************************************
 *  
 *   This file is part of the Utopia Documents application.
 *       Copyright (c) 2008-2014 Lost Island Labs
 *   
 *   Utopia Documents is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU GENERAL PUBLIC LICENSE VERSION 3 as
 *   published by the Free Software Foundation.
 *   
 *   Utopia Documents is distributed in the hope that it will be useful, but
 *   WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 *   Public License for more details.
 *   
 *   In addition, as a special exception, the copyright holders give
 *   permission to link the code of portions of this program with the OpenSSL
 *   library under certain conditions as described in each individual source
 *   file, and distribute linked combinations including the two.
 *   
 *   You must obey the GNU General Public License in all respects for all of
 *   the code used other than OpenSSL. If you modify file(s) with this
 *   exception, you may extend this exception to your version of the file(s),
 *   but you are not obligated to do so. If you do not wish to do so, delete
 *   this exception statement from your version.
 *   
 *   You should have received a copy of the GNU General Public License
 *   along with Utopia Documents. If not, see <http://www.gnu.org/licenses/>
 *  
 *****************************************************************************/

#ifndef UTOPIA_PLUGIN_P_H
#define UTOPIA_PLUGIN_P_H

#include <utopia2/config.h>
#include <utopia2/plugin.h>

#include <QObject>
#include <QUuid>

namespace Utopia
{

    class PluginPrivate : public QObject
    {
        Q_OBJECT
        Q_PROPERTY(bool enabled
                   READ isEnabled
                   WRITE setEnabled)
        Q_PROPERTY(Utopia::Plugin::PluginBase base
                   READ getBase
                   WRITE setBase)
        Q_PROPERTY(QString relativePath
                   READ getRelativePath
                   WRITE setRelativePath)

    public:
        PluginPrivate(Plugin * plugin, Plugin::PluginBase base, const QString & relativePath);
        PluginPrivate(Plugin * plugin, const QUuid & uuid);

        Plugin * plugin;

        bool enabled;
        Plugin::PluginBase base;
        QString relativePath;
        bool removed;
        QUuid uuid;

        Plugin::PluginBase getBase() const;
        QString getRelativePath() const;
        bool isEnabled() const;
        void setBase(Plugin::PluginBase base);
        void setEnabled(bool enabled);
        void setRelativePath(const QString & relativePath);

        static QString constructAbsolutePath(Plugin::PluginBase base);

    }; // class Plugin

} // namespace Utopia

#endif // UTOPIA_PLUGIN_P_H
