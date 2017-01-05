/*****************************************************************************
 *  
 *   This file is part of the Utopia Documents application.
 *       Copyright (c) 2008-2016 Lost Island Labs
 *           <info@utopiadocs.com>
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

#ifndef UTOPIA_CERTIFICATEERRORDIALOG_P_H
#define UTOPIA_CERTIFICATEERRORDIALOG_P_H

#include <utopia2/certificateerrordialog.h>

#include <QMap>

class QCheckBox;
class QWebView;

namespace Utopia
{

    class CertificateErrorDialog;

    class CertificateErrorDialogPrivate : public QObject
    {
        Q_OBJECT

    public:
        CertificateErrorDialogPrivate(const QString & host, const QList< QSslError > & sslErrors, CertificateErrorDialog * dialog);

        CertificateErrorDialog * dialog;

        QString host;
        QString htmlTemplate;
        QMap< QSslCertificate, QList< QSslError::SslError > > sslErrorsByCertificate;
        CertificateErrorDialog::AllowPolicy policy;

        QWebView * infoFrame;
        QCheckBox * alwaysCheckBox;

    public slots:
        void onAllowButtonClicked();
        void onCertificateListCurrentRowChanged(int);
    };

}

#endif // UTOPIA_CERTIFICATEERRORDIALOG_P_H

