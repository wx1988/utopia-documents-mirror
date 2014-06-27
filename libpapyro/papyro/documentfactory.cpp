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

//#include <utopia2/extension_impl.h>
#include <papyro/documentfactory.h>
#include <utopia2/node.h>
#include <spine/Document.h>
#include <spine/Annotation.h>
#include <boost/foreach.hpp>

#include <QFile>

namespace Papyro
{

    Spine::DocumentHandle DocumentFactory::create(const QString & filename)
    {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly)) {
            return create(file.readAll());
        } else {
            qDebug() << "Could not open pdf: " << filename.toStdString().c_str();
        }

        return Spine::DocumentHandle();
    }

    Spine::DocumentHandle DocumentFactory::load(const QString & filePath)
    {
        Spine::DocumentHandle document;

        if (!filePath.isEmpty()) {
            // Load DocumentFactory plugins
            foreach (DocumentFactory * factory, Utopia::instantiateAllExtensions< DocumentFactory >()) {
                if (factory->isCapable(filePath)) {
                    document = factory->create(filePath);
                }
                delete factory;
            }
        }

        return document;
    }

    Spine::DocumentHandle DocumentFactory::load(Utopia::Node * model)
    {
        Spine::DocumentHandle document;

        if (model && model->attributes.exists("papyro:pdfFile"))
        {
            QString filename = model->attributes.get("papyro:pdfFile").toString();
            if (!filename.isEmpty())
            {
                // Load according to filename

                // Load DocumentFactory plugins
                BOOST_FOREACH(DocumentFactory * factory, Utopia::instantiateAllExtensions< DocumentFactory >())
                {
                    if (factory->isCapable(filename))
                    {
                        document = factory->create(filename);
                    }

                    delete factory;
                }
            }
        }

        return document;
    }

}

UTOPIA_DEFINE_EXTENSION_CLASS(Papyro::DocumentFactory)
