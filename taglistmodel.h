#ifndef TAGLISTMODEL_H
#define TAGLISTMODEL_H

#include <QColor>
#include <QString>
#include <QList>
#include <QAbstractListModel>
#include <QDebug>
#include <QMimeData>

#include <QPixmap>
#include <QPainter>

#include "tag.h"

class TagListModel : public QAbstractListModel {
/* Un modele qui fait l'interface entre une liste de Tag
* et Qt pour gerer l'affichage et tout
* La on hérite du QAbstractListModel parce qu'on veut
* représenter une liste de tag */
    Q_OBJECT
private:
    QList<Tag *> *m_tags;
public:
    TagListModel(QList<Tag *> *tagList, QObject *parent);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index,
                 const QVariant &value, int role) override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    Qt::DropActions supportedDropActions() const override;
    QStringList mimeTypes() const override;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action,
                      int row, int column, const QModelIndex &parent) override;
public slots:
    void requestedAddTag();
signals:

};

#endif // TAGLISTMODEL_H