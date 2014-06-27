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

#ifndef ATHENAEUM_SORTFILTERPROXYMODEL_H
#define ATHENAEUM_SORTFILTERPROXYMODEL_H

#include <athenaeum/abstractbibliographiccollection.h>

#include <QSortFilterProxyModel>

namespace Athenaeum
{

    class AbstractFilter;

    class SortFilterProxyModelPrivate;
    class SortFilterProxyModel : public QSortFilterProxyModel
    {
        Q_OBJECT

    public:
        SortFilterProxyModel(QObject * parent = 0);
        ~SortFilterProxyModel();

        AbstractFilter * filter() const;
        void setFilter(AbstractFilter * filter);

    protected:
        SortFilterProxyModelPrivate * d;

        bool filterAcceptsColumn(int source_column, const QModelIndex & source_parent) const;
        bool filterAcceptsRow(int source_row, const QModelIndex & source_parent) const;

        // Hide the standard filtering methods
        using QSortFilterProxyModel::filterCaseSensitivity;
        using QSortFilterProxyModel::filterKeyColumn;
        using QSortFilterProxyModel::filterRegExp;
        using QSortFilterProxyModel::filterRole;
        using QSortFilterProxyModel::setFilterCaseSensitivity;
        using QSortFilterProxyModel::setFilterKeyColumn;
        using QSortFilterProxyModel::setFilterRegExp;
        using QSortFilterProxyModel::setFilterRole;

    }; // class SortFilterProxyModel

} // namespace Athenaeum

#endif // ATHENAEUM_SORTFILTERPROXYMODEL_H
